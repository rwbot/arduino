const int E1 = 5; //Motor 1 speed control PWM
const int E2 = 6; //Motor 2 speed control PWM
const int M1 = 4; //Motor 1 direction pin
const int M2 = 7; //Motor 2 direction pin

void setup() {
  int speed = 169;
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}

void loop() {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, speed);
  analogWrite(E2, speed);
  delay(2000);

  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, speed);
  analogWrite(E2, speed);
  delay(2000);
}
