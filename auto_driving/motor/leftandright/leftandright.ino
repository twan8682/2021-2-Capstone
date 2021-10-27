//좌회전 우회전

//left wheel
const int DIRFL = 2; 
const int PWMFL = 3; 
const int DIRBL = 7; 
const int PWMBL = 6; 

//right wheel
const int DIRFR =4; 
const int PWMFR =5; 
const int DIRBR =19; 
const int PWMBR =10; 

void setup() {
  //left wheel setting
  pinMode(DIRFL, OUTPUT);
  pinMode(DIRBL, OUTPUT);

  digitalWrite(DIRFL, LOW);
  analogWrite(PWMFL, 0);
  digitalWrite(DIRBL, LOW);
  analogWrite(PWMBL, 0);

  //right wheel setting
  pinMode(DIRFR, OUTPUT);
  pinMode(DIRBR, OUTPUT);

  digitalWrite(DIRFR, LOW);
  analogWrite(PWMFR, 0);
  digitalWrite(DIRBR, LOW);
  analogWrite(PWMBR, 0);


  for(int cnt =0;cnt <2;cnt ++) {
    //go right
    //left go
    digitalWrite(DIRFL, HIGH);  
    analogWrite(PWMFL, 0);
    digitalWrite(DIRBL, HIGH);  
    analogWrite(PWMBL, 0);
    //right back
    digitalWrite(DIRFR, LOW);  
    analogWrite(PWMFR, 255);
    digitalWrite(DIRBR, LOW);  
    analogWrite(PWMBR, 255);
    
    delay(2000);
  
    //stop
    //left stop
    digitalWrite(DIRFL, LOW); 
    analogWrite(PWMFL, 0);
    digitalWrite(DIRBL, LOW); 
    analogWrite(PWMBL, 0);
    //right stop
    digitalWrite(DIRFR, LOW); 
    analogWrite(PWMFR, 0);
    digitalWrite(DIRBR, LOW); 
    analogWrite(PWMBR, 0);
    
    delay(2000);
  
    //left
    //left back
    digitalWrite(DIRFL, LOW);  
    analogWrite(PWMFL, 255);
    digitalWrite(DIRBL, LOW);  
    analogWrite(PWMBL, 255);
    //right go
    digitalWrite(DIRFR, HIGH);  
    analogWrite(PWMFR, 0);
    digitalWrite(DIRBR, HIGH);  
    analogWrite(PWMBR, 0);
    
    delay(2000);
  
    //stop
    //left stop
    digitalWrite(DIRFL, LOW); 
    analogWrite(PWMFL, 0);
    digitalWrite(DIRBL, LOW); 
    analogWrite(PWMBL, 0);
    //right stop
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
