#include "Ultrasonic.h"
Ultrasonic ultrasonic( 10, 11);

#define PWMA 3
#define AIN1 0
#define AIN2 1
#define PWMB 5
#define BIN1 2
#define BIN2 4
#define STBY 6
#define LED 7
#define SPEAKER 9
#define FREQ 1000

/* Robot should continue straight until an object is within the distance threshold */
/* Sorry for the superflous code at the bottom - I need to get those functions */
/* into a header file  */

/* The robot should move forward and have a steady green LED until something is 7 inches in front of the sensor.
   Then the robot should stop and rotate left until there is not an object within 7 inches anymore               */

void setup() {
 
pinMode(PWMA,OUTPUT);
pinMode(AIN1,OUTPUT);
pinMode(AIN2,OUTPUT);
pinMode(PWMB,OUTPUT);
pinMode(BIN1,OUTPUT);
pinMode(BIN2,OUTPUT);
pinMode(STBY,OUTPUT);
pinMode(LED,OUTPUT);

}

void loop() {
 
  startUp();
  while(ultrasonic.Ranging(INC) < 9) {
    rotateLeft();
    digitalWrite(LED,HIGH);
    tone(SPEAKER,FREQ);
    delay(20);
    digitalWrite(LED,LOW);
    noTone(SPEAKER);
    delay(20);
  }
  goForward();
  digitalWrite(LED,HIGH);
 
 
}
void goForward ()
{
  digitalWrite (AIN1,HIGH);
  digitalWrite (AIN2,LOW);
  analogWrite(PWMA,233);
  digitalWrite (BIN1,HIGH);
  digitalWrite (BIN2,LOW);
  analogWrite(PWMB,255); 
}

void goBackward ()
{
  digitalWrite (AIN1,LOW);
  digitalWrite (AIN2,HIGH);
  analogWrite(PWMA,233);
  digitalWrite (BIN1,LOW);
  digitalWrite (BIN2,HIGH);
  analogWrite(PWMB,255); 
}

void rotateRight ()
{
  digitalWrite (AIN1,HIGH);
  digitalWrite (AIN2,LOW);
  analogWrite(PWMA,255);
  digitalWrite (BIN1,LOW);
  digitalWrite (BIN2,HIGH);
  analogWrite(PWMB,255); 
}

void rotateLeft ()
{
  digitalWrite (AIN1,LOW);
  digitalWrite (AIN2,HIGH);
  analogWrite(PWMA,255);
  digitalWrite (BIN1,HIGH);
  digitalWrite (BIN2,LOW);
  analogWrite(PWMB,255); 
}

void veerLeft ()
{
  digitalWrite (AIN1,HIGH);
  digitalWrite (AIN2,LOW);
  analogWrite(PWMA,190);
  digitalWrite (BIN1,HIGH);
  digitalWrite (BIN2,LOW);
  analogWrite(PWMB,255); 
}

void veerRight ()
{
  digitalWrite (AIN1,HIGH);
  digitalWrite (AIN2,LOW);
  analogWrite(PWMA,255);
  digitalWrite (BIN1,HIGH);
  digitalWrite (BIN2,LOW);
  analogWrite(PWMB,190); 
}

void applyBrakes ()
{
  digitalWrite (AIN1,HIGH);
  digitalWrite (AIN2,HIGH);
  analogWrite(PWMA,255);
  digitalWrite (BIN1,HIGH);
  digitalWrite (BIN2,HIGH);
  analogWrite(PWMB,255); 
}

void startUp ()
{
  digitalWrite(STBY,HIGH);
}

void turnAround()
{
  rotateLeft();
  delay(1370);
}

void shutDown ()
{
  digitalWrite(STBY,LOW);
}
