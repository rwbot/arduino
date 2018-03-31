//Function          Channel A   Channel B
//Direction         D 12        D 13
//Speed (PWM)       D 3         D 11
//Brake             D 9         D 8
//Current Sensing   A 0         A 1

//Channel A
const int directionL = 12;
const int speedL = 3;
const int brakeL = 9;

//Channel B 
const int directionR = 13;
const int speedR = 11;
const int brakeR = 8;

enum driveDirection { forward, backward };
enum brakeStatus{ ON, OFF };

void setup() {
  pinMode(directionR, OUTPUT);
  pinMode(brakeR, OUTPUT);

  pinMode(directionL, OUTPUT);
  pinMode(brakeL, OUTPUT);

  
  test();
  
}

void loop() {
  
}

void test(){

  go(forward, 255);
  delay(3000);
  
  SetBrake(ON);
  delay(1000);

  go(backward, 120);
  delay(3000);

  SetBrake(ON);
  
}

/**General function for driving the robot
 * @param DIRECTION sets the direction accepts type driveDirection: *forward* or *backward*
 * @param SPEED sets the speed. accepts int 0-255
 */
void go(driveDirection DIRECTION, int SPEED){
  SetBrake(OFF);
  SetSpeed(SPEED);
  SetDirection(DIRECTION);
}

/**General function for setting speed
 * @param s accpets int 0 - 255
 */
void SetSpeed(int s){
  analogWrite(speedL, s);       
  analogWrite(speedR, s);
}

/**Function for setting direction of motors
 * @param d accepts enum type driveDirection: *forward* or *backward*
 * Note: the motors are placed on the chassis so that they mirror each other
 * therefore they must turn in opposite directions for the robot to drive a certain direction
 */
void SetDirection(driveDirection d){
  if(d == forward){
    digitalWrite(directionL, LOW); //forward
    digitalWrite(directionR, HIGH);
  } else if(d == backward){
    digitalWrite(directionL, HIGH);  //backward
    digitalWrite(directionR, LOW);
  }
}

/**Function for engaging or disengage brakes
 * @param b accepts enum type brakeStatus: *ON* or *OFF*
 */
void SetBrake(brakeStatus b) {
  if(b == ON){
    digitalWrite(brakeL, HIGH);     //brake
    digitalWrite(brakeR, HIGH);
  } else if (b == OFF){
    digitalWrite(brakeL, LOW);      //disengage brake
    digitalWrite(brakeR, LOW);
  }
}




/*
void fullSpeed(){
  analogWrite(speedR, 255);       //Full speed
  analogWrite(speedL, 255);
}

void halfSpeed(){
  analogWrite(speedR, 123);       //half speed
  analogWrite(speedL, 123);
}
*/
