/***
 * twoMotorIntro
 * Tutorial on using two motors with a DFRobot Romeo arduino
 * @rwbot
 * v1.5
 */
 
//Function    Direction   Speed (PWM)
//Motor 1     D 4         D 5
//Motor 2     D 7         D 6

//Motor 1
int directionL = 4;       //Pin controlling Left motor direction
int speedL = 5;           //Pin controlling Left motor speed
//Motor 2
int directionR = 7;       //Pin controlling Right motor direction   
int speedR = 6;           //Pin controlling Right motor speed

void setup() {
  //Left Motor setup
  pinMode(directionL, OUTPUT);
  pinMode(speedL, OUTPUT);
  digitalWrite(speedL, LOW);

  //Right Motor setup
  pinMode(directionR, OUTPUT);
  pinMode(speedR, OUTPUT);

  //Turns motor pins off until needed
  digitalWrite(speedL, LOW);
  digitalWrite(speedR, LOW);
}

void loop() {
  //run test() functions
//  test1();
//  test2();
  test3();
  delay(3000);
}
