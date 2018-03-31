#include <Metro.h>
#include <GoBLE.h>

int joystickX, joystickY;
int buttonState[7];

//Function          Motor1      Motor2
//Direction         D 4         D 7
//Speed (PWM)       D 5         D 6

//Motor 1
int directionL=4;      //Left motor direction
int speedL=5;          //left motor speed
//Motor 2
int directionR=7;      //Right motor direction   
int speedR=6;         //Right motor speed

enum ONOFF{ ON, OFF };


void setup() {
  Goble.begin();
  Serial.begin(115200);
    
  //Left Motor setup
  pinMode(directionL, OUTPUT);
  pinMode(speedL, OUTPUT);
  digitalWrite(speedL, LOW);
  
  //Right Motor setup
  pinMode(directionR, OUTPUT);
  pinMode(speedR, OUTPUT);
  digitalWrite(speedR, LOW);

  brake(ON);
}

void loop() {

  if(Goble.available()){
    joystickX = Goble.readJoystickX();  
    joystickY = Goble.readJoystickY();

    buttonState[SWITCH_UP]     = Goble.readSwitchUp();
    buttonState[SWITCH_LEFT]   = Goble.readSwitchLeft();
    buttonState[SWITCH_RIGHT]  = Goble.readSwitchRight();
    buttonState[SWITCH_DOWN]   = Goble.readSwitchDown();
    buttonState[SWITCH_SELECT] = Goble.readSwitchSelect();
    buttonState[SWITCH_START]  = Goble.readSwitchStart();
    
    //brake(ON);
    
    if (buttonState[1] == PRESSED){
        rotateLeftSlow(); 
    } 
     if (buttonState[2] == PRESSED){
        forward(); 
    } 
     if (buttonState[3] == PRESSED){
        rotateRightSlow(); 
    } 
    if (buttonState[4] == PRESSED){
        backwardSlow(); 
    }
        
  }
}





