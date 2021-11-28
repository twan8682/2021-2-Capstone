import cv2
# 샘플 영상
url = 'http://192.168.219.117:81/stream'
cap = cv2.VideoCapture(url)

while True :
    ret, frame = cap.read()
    # 윈도우 창 출력용
    cv2.imshow("1", frame)
    cv2.waitKey(1)
