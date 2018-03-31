/***
 * helpers
 * helper methods for using two motors with a DFRobot Romeo arduino
 * @rwbot
 * v1.5
 */

/***
 * This creates an easy way to set the speed of both motors
 * We assign the name 's' to be our integer input speed for the function
 * Instead of digitalWrite(), we'll use analogWrite()
 * digitalWrite() can only assign pins to two states: HIGH or LOW
 * analogWrite() can give pins a range of values, from 0-255 or 0-1023
 * In our case, the range of speed spans from 0 to 255
 */
void setspeed(int s){
  //Set the speed for the Left motor to 's'
  analogWrite(speedL, s);       
  //Set the speed for the Right motor to 's'
  analogWrite(speedR, s);
}

/***
 * This allows us to easily control the brakes of both motors
 * Here we set the pin controlling speed to LOW
 * Which means the pin is currently off
 * Since it receives no power, the motors won't rotate
 */
void brakeON(){
    // Setting the speed pin to be LOW 
    // In LOW, it receives 0V, and so can't move
    digitalWrite(speedL, LOW);
    digitalWrite(speedR, LOW);
}

/***
 * This allows us to easily control the brakes of both motors
 * Here we set the pin controlling speed to HIGH
 * Which means it's able to receive power and rotate
 * at the given speed
 */
void brakeOFF(){
    // Setting the speed pin to be HIGH 
    // In HIGH, it receives +5V, and so can move
    digitalWrite(speedL, HIGH);
    digitalWrite(speedR, HIGH);
}

/***
 * This synchronizes the motors to turn in the same direction
 * The direction pin uses HIGH or LOW to represent 
 * the direction in which the motors will spin
 * In our case, LOW means forward
 */
void forward(){
  brakeOFF();
  digitalWrite(directionL, LOW); 
  digitalWrite(directionR, LOW);
  setspeed(100);
}

/***
 * This synchronizes the motors to turn in the same direction
 * The direction pin uses HIGH or LOW to represent 
 * the direction in which the motors will spin
 * In our case, HIGH means backward
 */
void backward(){
  brakeOFF();
  digitalWrite(directionL, HIGH); 
  digitalWrite(directionR, HIGH);
  setspeed(100);
}

/***
 * This tells the motors to turn in opposite directions
 * This rotates the robot
 * In our case, rotating right involves
 * directionL = LOW and directionR = HIGH
 */
void rotateRight(){
  brakeOFF();
  digitalWrite(directionL, LOW); 
  digitalWrite(directionR, HIGH);
  setspeed(100); 
}

/***
 * This tells the motors to turn in opposite directions
 * This rotates the robot
 * In our case, rotating left involves
 * directionL = HIGH and directionR = LOW
 */
void rotateLeft(){
  brakeOFF();
  digitalWrite(directionL, HIGH); 
  digitalWrite(directionR, LOW);
  setspeed(100); 
}
