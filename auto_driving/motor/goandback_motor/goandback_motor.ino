//go and back

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

  
  for(int cnt = 0;cnt <2;cnt++){
    //go
    //go - left
    digitalWrite(DIRFL, HIGH);  
    analogWrite(PWMFL, 0);
    digitalWrite(DIRBL, HIGH);  
    analogWrite(PWMBL, 0);
    //go - right
    digitalWrite(DIRFR, HIGH);  
    analogWrite(PWMFR, 0);
    digitalWrite(DIRBR, HIGH);  
    analogWrite(PWMBR, 0);digitalWrite(DIRFR, HIGH);  
    analogWrite(PWMFR, 0);
    digitalWrite(DIRBR, HIGH);  
    analogWrite(PWMBR, 0);

    delay(2000);

    //stop
    //stop - left
    digitalWrite(DIRFL, LOW); 
    analogWrite(PWMFL, 0);
    digitalWrite(DIRBL, LOW); 
    analogWrite(PWMBL, 0);
    //stop - right
    digitalWrite(DIRFR, LOW); 
    analogWrite(PWMFR, 0);
    digitalWrite(DIRBR, LOW); 
    analogWrite(PWMBR, 0);
  
    delay(2000);


    //back
    //back - left
    digitalWrite(DIRFL, LOW);  
    analogWrite(PWMFL, 255);
    digitalWrite(DIRBL, LOW);  
    analogWrite(PWMBL, 255);
    //back - right
    digitalWrite(DIRFR, LOW);  
    analogWrite(PWMFR, 255);
    digitalWrite(DIRBR, LOW);  
    analogWrite(PWMBR, 255);
    
    delay(2000);
  
    //stop
    //stop - left
    digitalWrite(DIRFL, LOW); 
    analogWrite(PWMFL, 0);
    digitalWrite(DIRBL, LOW); 
    analogWrite(PWMBL, 0);
    //stop - right
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
