int led = 13; // Pin 13 has an LED connected; Here we delare it as a variable
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led,HIGH);// turn the LED
delay(1000);
digitalWrite(led, LOW);
delay(1000);
}
