
float getSound(){
  return analogRead(sound);
}

void testSound(){
  Serial.print("Sound val: ");
  Serial.println(getSound());
  float soundval = getSound();
//  if(soundval > 880 && soundval < 900){
//    Serial.println(" START MUTHAFUCKA");
//  }
  delay(69);
  
}

boolean soundStart(){
  float soundval;
  int count = 0;
  for(int i=0; i<10; i++){
    soundval = getSound();
    if(soundval > 850 && soundval < 950){
      count++;
    }
    delay(35);
  }
    if(count > 4){
      Serial.println(" START MUTHAFUCKA");
      green(ON);
      delay(2000);
      green(OFF);
      return true;
      goboy = true;
    } else { 
      return false;
    }
}

