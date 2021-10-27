//right_front, go and back

//pin setting
const int DIRFR =4; 
const int PWMFR =5;

void setup() {
  //setting
  pinMode(DIRFR, OUTPUT);

  digitalWrite(DIRFR, LOW);
  analogWrite(PWMFR, 0);


  for(int cnt =0;cnt <2;cnt ++) {
    //go
    digitalWrite(DIRFR, HIGH);  
    analogWrite(PWMFR, 0);
    
    delay(2000);
  
    //stop
    digitalWrite(DIRFR, LOW); 
    analogWrite(PWMFR, 0);
    
    delay(2000);
  
    // 오른쪽 후진
    digitalWrite(DIRFR, LOW);  
    analogWrite(PWMFR, 255);
    
    delay(2000);
  
    //back
    digitalWrite(DIRFR, LOW); 
    analogWrite(PWMFR, 0);
    
    delay(2000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
