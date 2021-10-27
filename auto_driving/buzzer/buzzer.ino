const int buzzer = 17;
int howMany = 1000;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {  
  if(howMany>0) {
    howMany--;
    
    digitalWrite(buzzer, HIGH);
    delay(1);
    digitalWrite(buzzer, LOW);
    delay(1);
  
  }
}
