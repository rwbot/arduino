
void setspeed(int s){
  analogWrite(speedL,s);
  analogWrite(speedR, s);
 }
 
 void brakeON(){
    digitalWrite(speedL, LOW);
    digitalWrite(speedR, LOW);

}

 void brakeOFF(){
    digitalWrite(speedL, HIGH);
    digitalWrite(speedR, HIGH);
}

void forward(){
  brakeOFF();
  digitalWrite(directionL, LOW);
  digitalWrite(directionR, LOW);
  setspeed(80);
}

void backward(){
  brakeOFF();
  digitalWrite(directionL, HIGH);
  digitalWrite(directionR, HIGH);
  setspeed(80);

}

  void rotateRight(){
  brakeOFF();
  digitalWrite(directionL, LOW);
  digitalWrite(directionR, HIGH);
  setspeed(80);

}

  void rotateLeft(){
  brakeOFF();
  digitalWrite(directionL, HIGH);
  digitalWrite(directionR, LOW);
  setspeed(80);

}
