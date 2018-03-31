#include <SharpIR.h>
//Infrared 
#define model 1080
#define irsr A5
#define irsh A3
#define irsl A4
float cos45 = 0.707;

void setup() {
  Serial.begin(9600);
  //IR Setup
  pinMode(irsl, INPUT);
  pinMode(irsh, INPUT);
  pinMode(irsr, INPUT);
}



void loop() {
  //Serial.print("IR: ");
  //Serial.println( analogRead(A5) );
  //testIR();
  Serial.println(irh());
}

/**Function to send an IR signal and calculate the distance at that point
 * returns float distance in centimeters (cm)
 */


// ir: the pin where your sensor is attached
// model: an int that determines your sensor:  1080 for GP2Y0A21Y
// (working distance range according to the datasheets)

float irl(){
  SharpIR SharpIR(irsl, model);
  int dis=(SharpIR.distance()) * 1.34;  // this returns the distance to the object you're measuring
  return dis * cos45;
} 

float irh(){
     SharpIR SharpIR(irsh, model);
  int dis=(SharpIR.distance()) * 1.34;  // this returns the distance to the object you're measuring
  return dis;
} 

float irr(){
     SharpIR SharpIR(irsr, model);
  int dis=(SharpIR.distance()) * 1.34;  // this returns the distance to the object you're measuring
  return dis * cos45;
} 



void testIR(){
  Serial.print(" IRL: ");
  Serial.print(irl());
  Serial.print(" IRH: ");
  Serial.print(irh());
  Serial.print(" IRR: ");
  Serial.println(irr());
}
