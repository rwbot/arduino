
void red(ONOFF x){
  if(x == ON){
    analogWrite(redLED, 255);
  } else if(x == OFF){
    analogWrite(redLED, 0);
  }
}

void green(ONOFF x){
  if(x == ON){
    analogWrite(greenLED, 255);
  } else if(x == OFF){
    analogWrite(greenLED, 0);
  }
}
