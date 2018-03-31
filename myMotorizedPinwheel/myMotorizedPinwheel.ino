const int potPin = A0;
const int motorPin = 9;
int potVal;
int potSpeed;

void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);
  pinMode(motorPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);

  potSpeed = map(potVal, 0, 1023, 0, 255);

  analogWrite(motorPin, potSpeed);

}
