#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11);
//BTRX to 10
//BTTX to 11

#define key 7

void setup()
{
  pinMode(key, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(key, HIGH);
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  //BTSerial.begin(9600);  // HC-05 default speed in AT command more
  BTSerial.begin(38400);  // HC-05 default speed in AT command more
  
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}
