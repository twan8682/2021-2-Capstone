//left_front, go and back

//pin
const int DIRFL = 2; 
const int PWMFL = 3;

void setup() {
  //setting
  pinMode(DIRFL, OUTPUT);

  digitalWrite(DIRFL, LOW);
  analogWrite(PWMFL, 0);


  for(int cnt =0;cnt <2;cnt ++) {
    //go
    digitalWrite(DIRFL, HIGH);  
    analogWrite(PWMFL, 0);
    
    delay(2000);
  
    //stop
    digitalWrite(DIRFL, LOW); 
    analogWrite(PWMFL, 0);
    
    delay(2000);
  
    //back
    digitalWrite(DIRFL, LOW);  
    analogWrite(PWMFL, 255);
    
    delay(2000);
  
    //stop
    digitalWrite(DIRFL, LOW); 
    analogWrite(PWMFL, 0);
    
    delay(2000);
  }
}


void loop() {
  // put your main code here, to run repeatedly:

}
