void HUNT(){
  red(ON);
    float y1 = getFlame();
    Serial.println("WHAT THE FUCK");
    rotateRightSlow();
    delay(500);
    float y2 = getFlame();
    boolean out = false;
    while(out == false){
      bubble();
        while(getFlame() > 1000){
          bubble();
          rotateLeftSlow();
          Serial.println("Lost Flame, scanning");
        }
        while(getFlame() < 850){
          Serial.println("Hunting");
          
        //*********START HUNTING
              if(y2 < y1+20){
                rotateLeftSlow(); 
                delay(300);
              } else {
                rotateRightSlow();
                delay(300);
              }
              bubble();
              forwardSlow();    //FIX THIS LOOP
              delay(500);
              Serial.println("Hunting Forward");
              y1 = getFlame();
              delay(100);
              y2 = getFlame();   
      //********END HUNTING
      //********START POUNCE
      while(getFlame() < 50){
        bubble;
        Serial.println("Pouncing");
        while(getFlame() < 100){
          chill();
          fan(true);
          if(irh() < 10 && getFlame() > 1000){
            chill();
            Serial.println("Candle Extinguished");
            brake(ON);
            red(OFF);
          } else {
            bubble;
           forwardSlow();
            Serial.println("Candle Spotted, going closer");
          }
          
        }
      }
      //*********END POUNCE
      }
      
    }
    
}

void bubble(){
  while(irh() < 10 ){
      if(irr() < 10){
          Serial.println("Too close to Right wall");
          backwardSlow();
          delay(1800);
          rotateLeftSlow();
          delay(300);
      } else if(irl() < 7){
           Serial.println("Too close to Left wall");
           backwardSlow();
           delay(1800);
           rotateRightSlow();
           delay(300);
      }
          
  }
 
}

