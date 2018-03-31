#include <SharpIR.h>
#include <Metro.h>
#include <GoBLE.h>

//Function          Motor1      Motor2
//Direction         D 4         D 7
//Speed (PWM)       D 5         D 6

//Motor 1
int directionL=4;      //Left motor direction
int speedL=5;          //left motor speed
//Motor 2
int directionR=7;      //Right motor direction   
int speedR=6;         //Right motor speed


float cos45 = 0.707;

//enum driveDirection { forward, backward };  
enum ONOFF{ ON, OFF };

#define fanpin 12
#define flame A1
#define sound A2
#define redLED 9
#define greenLED 10

//Infrared 
#define model 1080
#define irsr A5
#define irsh A3
#define irsl A4

boolean goboy = false;

//Distance from wall
float cushion = 6.9;

int bState = 1;



int joystickX, joystickY;
int buttonState[7];

void setup() {
  Goble.begin();
  Serial.begin(115200);
  //Sound setup
  pinMode(sound, INPUT);
  pinMode(fanpin, OUTPUT);

  //LED
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  //IR Setup
  pinMode(irsl, INPUT);
  pinMode(irsh, INPUT);
  pinMode(irsr, INPUT);
    
  //Left Motor setup
  pinMode(directionL, OUTPUT);
  pinMode(speedL, OUTPUT);
  digitalWrite(speedL, LOW);

  fan(false);
  
  //Right Motor setup
  pinMode(directionR, OUTPUT);
  pinMode(speedR, OUTPUT);
  digitalWrite(speedR, LOW);

  
  forward();
  delay(500);
  brake(ON);
  Serial.begin(9600);

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
    
    brake(ON);
    
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





