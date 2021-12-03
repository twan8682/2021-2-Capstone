import cv2
import numpy as np
import matplotlib.pyplot as plt
import pymysql
import requests
def make_coordinates(image,line_parameters):
    slope, intercept = line_parameters
    y1 = image.shape[0]  # Height
    y2 = int(y1 * (3/5))
    x1 = int((y1 - intercept)/slope)
    x2 = int((y2 - intercept)/slope)
    return np.array([x1,y1,x2,y2]) 

def average_slope_intercept(image,lines):
    left_fit = []
    right_fit = []
    for line in lines:
        x1,y1,x2,y2 = line.reshape(4)
        parameters = np.polyfit((x1,x2),(y1,y2),1)
        slope = parameters[0]
        intercept = parameters[1]
        if slope<0:
            left_fit.append((slope,intercept))
        else :
            right_fit.append((slope,intercept))
    left_fit_average = np.average(left_fit,axis=0)
    right_fit_average = np.average(right_fit,axis=0)
    left_line = make_coordinates(image,left_fit_average)
    right_line = make_coordinates(image,right_fit_average)
    return np.array([left_line,right_line])


def canny(image):
    gray = cv2.cvtColor(image,cv2.COLOR_RGB2GRAY)
    blur = cv2.GaussianBlur(gray,(5,5),0)   # Kernel size is 5x5
    canny = cv2.Canny(blur,50,150)
    return canny

def display_lines(image,lines):
    line_image = np.zeros_like(image)
    if lines is not None:
        for line in lines:
            x1,y1,x2,y2 = line.reshape(4)  # Reshaping all the lines to a 1D array.
            cv2.line(line_image,(x1,y1),(x2,y2),(255,0,0),5) # Draw a Blue Line(BGR in OpenCV)
    return line_image

def region_of_interest(image):
    height = image.shape[0]
    polygons = np.array([
        [(0,240),(410,230),(290,195),(130,195)]
    ])          # Triangle polygon because cv2.fillPoly expects an array of polygons.
    mask = np.zeros_like(image)   # Create a black mask to apply the above Triangle on.
    cv2.fillPoly(mask,polygons,255)     # A complete white triangle polygon on a black mask.
    masked_image = cv2.bitwise_and(image,mask)
    return masked_image

num = 1
conn = pymysql.connect(host='localhost', user='root', password='1234', charset='utf8', db='capstone0') #DB 연결
cur = conn.cursor()

cap = cv2.VideoCapture('http://192.168.219.117:81/stream')
while(cap.isOpened()):
    _, frame = cap.read()
    canny_image = canny(frame)
    #cropped_image = region_of_interest(canny_image)
    #lines = cv2.HoughLinesP(cropped_image,2,np.pi/180,100,np.array([]),minLineLength=10,maxLineGap=5)
    #averaged_lines = average_slope_intercept(frame,lines)
    #line_image = display_lines(frame,averaged_lines)
    #combo_image = cv2.addWeighted(frame,0.8,line_image,1,1)    # Imposing the line_image on the original image

    cv2.imshow('Result',frame)
    
    key = cv2.waitKey(1)

    if key == 26:
        print("캡쳐")
        cv2.imwrite("C:\\Users\\twan8\\eclipse-workspace\\Web\\WebContent\\resources\\images\\" + str(num) + ".png", frame)
        sql = "INSERT INTO result VALUES("+str(num)+")"
        cur.execute(sql)
        conn.commit()
        requests.get('http://localhost:8080/Web/testResult.jsp?dectect=ok')
        num=num+1
