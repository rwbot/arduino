#include <SharpIR.h>

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


void setup() {
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

  brake(ON);
  Serial.begin(9600);

//  do{
//    soundStart();
//    Serial.println("Looping until soundstart");
//    delay(50);
//    
//  } while(goboy == false);
//  Serial.println("Sound Heard, Exiting Setup");

  delay(5000);
  green(ON);
}

void loop() {
//      if(getFlame() < 669){
//        Serial.println("HUNT MODE ACTIVATED");
//        HUNT();
//      } else {
//        fan(false);
//        Serial.println("Navigating");
//        navigate();
//      }
  //forward();
  //normalFollow();
  //testTurn();
  //turnRight();
  testIR();
  //navigate();
  //forward();
  //go();
  //testFlame();    
  //red(ON);
  //green(ON);
  //closer();
  //testSound();
  //soundStart();
 
  
}





