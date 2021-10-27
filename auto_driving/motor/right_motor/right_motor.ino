//right, go and back

//pin
const int DIRFR =4; 
const int PWMFR =5; 
const int DIRBR =19; 
const int PWMBR =10; 

void setup() {
  //setting
  pinMode(DIRFR, OUTPUT);
  pinMode(DIRBR, OUTPUT);

  digitalWrite(DIRFR, LOW);
  analogWrite(PWMFR, 0);
  digitalWrite(DIRBR, LOW);
  analogWrite(PWMBR, 0);


  for(int cnt =0;cnt <2;cnt ++) {
    //go
    digitalWrite(DIRFR, HIGH);  
    analogWrite(PWMFR, 0);
    digitalWrite(DIRBR, HIGH);  
    analogWrite(PWMBR, 0);
    
    delay(2000);
  
    //stop
    digitalWrite(DIRFR, LOW); 
    analogWrite(PWMFR, 0);
    digitalWrite(DIRBR, LOW); 
    analogWrite(PWMBR, 0);
    
    delay(2000);
  
    //back
    digitalWrite(DIRFR, LOW);  
    analogWrite(PWMFR, 255);
    digitalWrite(DIRBR, LOW);  
    analogWrite(PWMBR, 255);
    
    delay(2000);
  
    //stop
    digitalWrite(DIRFR, LOW); 
    analogWrite(PWMFR, 0);
    digitalWrite(DIRBR, LOW); 
    analogWrite(PWMBR, 0);
    
    delay(2000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
