#include <Servo.h>
Servo myServo;

const int potPin=A0;
int potValue;
int angle;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);
  angle = map(potValue, 0, 1023, 0, 179);
  myServo.write(angle);
  delay(15);

}
