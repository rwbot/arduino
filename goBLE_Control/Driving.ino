void forward() {
    brake(OFF);
    digitalWrite(directionL, LOW); 
    digitalWrite(directionR, LOW);

    setspeedL(100);
    setspeedR(110); 
}

void backwardSlow(){
  brake(OFF);
  digitalWrite(directionL, HIGH); 
  digitalWrite(directionR, HIGH);
  setspeed(90);
}

void rotateRightSlow(){
  digitalWrite(directionL, LOW); 
  digitalWrite(directionR, HIGH);
  setspeed(90); 
}

void rotateLeftSlow(){
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


