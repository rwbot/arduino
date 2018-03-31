void test1(){
  digitalWrite(speedL, HIGH);
  digitalWrite(speedR, HIGH);
  digitalWrite(directionL, LOW);
  digitalWrite(directionR, LOW);
  analogWrite(speedL, 200);
  analogWrite(speedR,225);
  delay(2500);
  digitalWrite(speedL, LOW);
  digitalWrite(speedR, LOW);
  
}

