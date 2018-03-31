/*
Adafruit Arduino - Lesson 5. Serial Monitor
*/
 


int led = 13;
 
void setup() 
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  while (! Serial); // Wait untilSerial is ready - Leonardo
  Serial.println("Enter y or n to toggle LED state");
  digitalWrite(led, LOW);
}
 
void loop() 
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch == 'y')
    {
      digitalWrite(led, HIGH);
      Serial.print("Turned on LED ");
      Serial.println(led);
    }
    if (ch == 'n')
    {
      digitalWrite(led, LOW);
      Serial.println("Cleared");
    }
  }
}
 

