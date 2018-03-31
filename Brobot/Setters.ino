/**Function for setting direction of motors
 * @param d accepts enum type driveDirection: *forward* or *backward*
 * Note: the motors are placed on the chassis so that they mirror each other
 * therefore they must turn in opposite directions for the robot to drive a certain direction
 */
void setdirection(driveDirection d){
  if(d == backward){
    digitalWrite(directionL, LOW); //backward
    digitalWrite(directionR, HIGH);
  } else if(d == forward){
    digitalWrite(directionL, HIGH);  //forward
    digitalWrite(directionR, LOW);
  }
}


/**Function for engaging or disengage brakes
 * @param b accepts enum type brakeStatus: *ON* or *OFF*
 */
void setbrake(brakeStatus b) {
  if(b == ON){
    digitalWrite(brakeL, HIGH);     //brake
    digitalWrite(brakeR, HIGH);
  } else if (b == OFF){
    digitalWrite(brakeL, LOW);      //disengage brake
    digitalWrite(brakeR, LOW);
  }
}


/**General function for setting speed
 * @param s accpets int 0 - 255
 * currently hardcoded as 169
 */
void setspeed(int s){
  analogWrite(speedL, s);       
  analogWrite(speedR, s);
}

void setspeedL(int sl){
    analogWrite(speedL, sl);
}

void setspeedR(int sr){
    analogWrite(speedR, sr);
}
