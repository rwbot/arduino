void test1(){
  // Setting the speed pin to be HIGH 
  // In HIGH, the speed pin receives +5V, and is able can move
  digitalWrite(speedL, HIGH);
  digitalWrite(speedR, HIGH);

  //Synchronizes rotation direction of both motors
  //Rotating in the same direction drives in that direction
  //Rotating in opposite directions makes it rotate 
  digitalWrite(directionL, LOW); 
  digitalWrite(directionR, LOW);

  //Set the speed for the Left motor to 's'
  analogWrite(speedL, 100);       
  //Set the speed for the Right motor to 's'
  analogWrite(speedR, 100);

  //Freezes the states of pins for the amount of time
  //Using delay here allows the robot to drive for 2.5 seconds
  //Before exiting the loop
  delay(2500);

  //Setting the speed pin to be LOW 
  //In LOW, the speed pin receives 0V
  //We take advantage of that feature by using it 
  //as our way to 'brake' the motors
  digitalWrite(speedL, LOW);
  digitalWrite(speedR, LOW);
}
