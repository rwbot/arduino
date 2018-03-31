// program exercises servo attached to port “servoport”
// Include the Servo, Wire, and LiquidCrystal libraries
#include <Servo.h>
#include <Wire.h>
//#include <LiquidCrystal_I2C.h>

//#LiquidCrystal_I2C //lcd(0x27,16,2);  // set the //lcd address to 0x27 for a 16 chars and 2 line display
Servo myservo;  // create servo object to control a servo 

int servoport = 9;
int pos = 0;    // variable to store the servo position

void setup() 
{ 
  // initialize the //lcd
  //lcd.init();                     
  //lcd.backlight();
  Serial.begin(9600);
  pinMode(servoport,OUTPUT);  //set output port
  myservo.attach(servoport);  // attaches the servo on pin 9 to the servo object, 600-2400 us pulse width range   
  myservo.write(90);
  wiggle();
} 

void wiggle(){
  pos = 90;
  myservo.write(pos);
  for(int i=89; i<180; i++){
    pos = i;
    myservo.write(pos);
    delay(50);
  }
  for(int i=90; i!=90; i--){
    pos = i;
    myservo.write(pos);
  }
  for(int i=89; i>0; i--){
    pos = i;
    myservo.write(pos);
  }
}

void loop() 
{
//  int delta = 1;          // milliseconds delay between servo steps
//  for(pos = 0; pos < 181; pos++)  // goes from 0 degrees to 180 degrees 
//  {   
//    Serial.print("pos "); 
//    Serial.println(pos, DEC);
//    // in steps of 1 degree 
//    myservo.write(pos);    // tell servo to go to position in variable 'pos' 
//    delay(delta);          // waits for the servo to reach the position 
//  }
//  for(pos = 180; pos > 0; pos--)     // goes from 180 degrees to 0 degrees 
//  {         
//    Serial.print("pos "); 
//    Serial.println(pos, DEC);                   
//    myservo.write(pos); 
//    delay(delta); 
//  } 
}


