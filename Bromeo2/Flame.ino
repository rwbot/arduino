
float getFlame(){
  return (analogRead(flame) + analogRead(flame) + analogRead(flame)) / 3;
}

void testFlame(){
  Serial.print(" Flame analog: ");
  Serial.println(getFlame());
}


void fan(boolean s){
  if(s){
    digitalWrite(fanpin, LOW);
  } else {
    digitalWrite(fanpin, HIGH);
  }
}


