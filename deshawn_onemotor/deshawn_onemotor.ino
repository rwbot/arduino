/***
 * oneMotorIntro
 * Tutorial on using one motor with a DFRobot Romeo arduino
 * @rwbot
 * v1.1
 */
 
//Motor pin configuration
int directionL = 4;       //Pin controlling Left motor direction
int speedL = 5;           //Pin controlling Left motor speed

int directionR = 7;       //Pin controlling Right motor direction
int speedR = 6;           //Pin controlling Right motor speed

void setup() {
  //Declaring the directin pin as an output
  pinMode(directionL, OUTPUT);
  pinMode(directionR, OUTPUT);

  //Declaring the directin pin as an output
  pinMode(speedL, OUTPUT);
  pinMode(speedR, OUTPUT);

  //The direction pin takes only 2 values, HIGH or LOW
  //This pin controls the rotation of the motor
  //HIGH can mean clockwise, while LOW is counter-clockwise
  //Or vise versa, depending on how your motor is wired
  //Assigning HIGH to the direction pin
  digitalWrite(directionL, HIGH);
  digitalWrite(directionR, HIGH);
  
  //Assigning LOW to the speed pin cuts off the power
  //and without power, the motor cannot turn
  //Toggling between HIGH/LOW is how we can control
  //when we want a motor should spin and when not to.
  digitalWrite(speedL, LOW);
  digitalWrite(speedR, LOW);
}

void loop() {
  //test1();
 rotateRight();
}
