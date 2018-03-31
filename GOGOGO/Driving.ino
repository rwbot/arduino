
  void navigate(){
    Serial.println("forward");
      forward();
    while(irh() < 20){
        if (irl() < 16){
          rotateRight();
        } 
    }
    while(irl() < 5 || irh() < 5 || irr() < 5){
      backwardSlow();
      delay(2000);
      rotateLeft();
    }
    while(irr() < 10){
      rotateLeft();
      delay(200);
      forward();
    }
      
      while(irh() > 80 && irl() > 50){
      Serial.println("Left After Third Room");
      rotateLeft();
      delay(700);
      forward();
      }
  
    
    //Condition for intersection
    while(irl() > 40 && irh() > 100 && irr() > 50){
      Serial.println("Left at Intersection");
      rotateLeft();
    }
    
  }

  void forward() {
    brake(OFF);
    digitalWrite(directionL, LOW); 
    digitalWrite(directionR, LOW);

    while (irl() > 30 && irh() < 38){
      
      delay(500);
      rotateLeft();
    }
    if(irl() > 14 && irr() > 14 && irh() > 20){
      Serial.println("straight");
      setspeedL(100);
      setspeedR(110);
    } else if(irl() < 10){
      while(irl() < 12){
        rotateRight();
      }
      Serial.println("veering right");
      setspeedL(169);
      setspeedR(80);
    } else if(irl() > 15){
      Serial.println("veering left");
      setspeedL(100);
      setspeedR(169);
    } 
    
  }

void forwardSlow(){
  brake(OFF);
  digitalWrite(directionL, LOW); 
  digitalWrite(directionR, LOW);
  setspeed(90);
  Serial.println("Forward slowly");
}

void backwardSlow(){
  brake(OFF);
  digitalWrite(directionL, HIGH); 
  digitalWrite(directionR, HIGH);
  setspeed(90);
  Serial.println("BACK IT UP PON DI DUMPAH TRUCK");
}

void rotateRightSlow(){
  Serial.println("Rotating right slowly");
  digitalWrite(directionL, LOW); 
  digitalWrite(directionR, HIGH);
  setspeed(90); 
}

void rotateLeftSlow(){
  Serial.println("Rotating left slowly");
  digitalWrite(directionL, HIGH); 
  digitalWrite(directionR, LOW);
  setspeed(90); 
}




/* Function for going forward
 *  Make it sensor based
 *  Algorithm uses left wall following to maintain straightness
 *  Should account for crossing forks where hallway is open on the right
 */
 //CALIBRATE SENSORS!!!! 


/*  Sensor Based Turning
 *   Right & Left turn
 *  Use change of state FN of each sensor
 *  In each of the possible right turn LHR conditions
 *  Turn around for dog obstacle
 */
//Testing for sensor based right turn

void rotateRight(){
  Serial.println("Rotating right");
  digitalWrite(directionL, LOW); 
  digitalWrite(directionR, HIGH);
  setspeed(150); 
}

void rotateLeft(){
  Serial.println("Rotating left");
  digitalWrite(directionL, HIGH); 
  digitalWrite(directionR, LOW);
  setspeed(100); 
}



/**Function for toggling brakes
 * @param bs accepts enum type ONOFF either ON or OFF
*/
void brake(ONOFF bs){
  if(bs == ON){
    digitalWrite(speedL, LOW);
    digitalWrite(speedR, LOW);
  } else {
    digitalWrite(speedL, HIGH);
    digitalWrite(speedR, HIGH);
  }
}

//give Bromeo a chill pill
void chill(){
  brake(ON);
}

void go(){
  digitalWrite(directionL, LOW); 
  digitalWrite(directionR, LOW);
  setspeed(255);
}


