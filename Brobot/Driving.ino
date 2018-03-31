void navigate(){
  
  Serial.print("Distance cm: ");
  Serial.print(sonar());
    while(sonar() < 10){
        turn(left, 45);
        Serial.print(" Turning");
    }
    go(forward);
    Serial.println(" Straight");
}

/**General function for driving the robot
 * @param DIRECTION sets the direction accepts type driveDirection: *forward* or *backward*
 */
void go(driveDirection DIRECTION){
  setdirection(DIRECTION);
  setspeedL(255);
  //correctSlaveSpeed();
  setspeedR(255);
  setbrake(OFF);
}

int turnConstant = 0; //delay time for robot to move 45 degrees

void turn(turnDirection td, int angle){
    if(td == right){
        digitalWrite(directionL, HIGH); 
        digitalWrite(directionR, HIGH);
    } else {
        digitalWrite(directionL, LOW); 
        digitalWrite(directionR, LOW);
    } 
    setspeed(s);
    setbrake(OFF);
    delay(turnConstant / angle);
    setbrake(ON);
}

