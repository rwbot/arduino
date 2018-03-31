const int directionM1 = 4;
const int speedM1 = 5;

const int directionM2 = 6;
const int speedM2 = 7;

byte motorOutput;
const int sensorPin = 1;
int x;

void setup() {
  pinMode(directionM1, OUTPUT);
  pinMode(speedM1, OUTPUT);
  pinMode(directionM2, OUTPUT);
  pinMode(speedM2, OUTPUT);

  digitalWrite(directionM1, HIGH);
  digitalWrite(directionM2, LOW);
}

void loop() {
  delay(10);
  x = analogRead(sensorPin);
  
  if(x>=200){
    motorOutput = x;
  } else if(x<200 && x>=100){
    motorOutput = x + 50;
  } else if(x<100 && x>=50){
    motorOutput = x + 25;
  } else if (x<50 && x>=0){
    motorOutput = x;
  }
  
  analogWrite(speedM1, motorOutput);
  analogWrite(speedM2, motorOutput);
}

