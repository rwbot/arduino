
//Channel A
const int directionL = 12;          //Channel A
const int speedL = 3;
const int brakeL = 9; 

//Channel B 
const int directionR = 13;          //Channel B
const int speedR = 11;
const int brakeR = 8;

const byte s = 169;                  //Constant speed

enum driveDirection { forward, backward };  
enum turnDirection { right, left, around };
enum brakeStatus{ ON, OFF };



void setup() {
 
  
  //Channel A setup
  pinMode(directionL, OUTPUT);
  pinMode(brakeL, OUTPUT);
  pinMode(speedL, OUTPUT);
  digitalWrite(speedL, LOW);
  
  //Channel B setup
  pinMode(directionR, OUTPUT);
  pinMode(brakeR, OUTPUT);
  pinMode(speedR, OUTPUT);
  digitalWrite(speedR, LOW);

  setbrake(ON);
  
  delay(4000);
}

//main loop
void loop() {
  delay(7000);
  
  
   
    test(0);
    delay(3000);
  
  
}




void test(int i){

  go(forward, i);
  delay(3000);
  
  setbrake(ON);
  delay(1000);

  go(backward, i);
  delay(3000);

  setbrake(ON);
  
  
}

/**General function for driving the robot
 * @param DIRECTION sets the direction accepts type driveDirection: *forward* or *backward*
 */
void go(driveDirection DIRECTION, int i){
  setdirection(DIRECTION);
  setspeedR(169);
  setspeedL(s-i);
  setbrake(OFF);
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

