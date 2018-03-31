const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionPin = 4;
const int potPin = A0;

int directionState = 0;
int prevDirectionState = 0;

int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(directionPin, INPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.print(directionState = digitalRead(directionPin));
  Serial.print(" ");
  Serial.println(motorSpeed = analogRead(potPin)/4);
  analogWrite(enablePin, motorSpeed);

  if(directionState != prevDirectionState){
    if(directionState == HIGH){
      motorDirection = !motorDirection;
    }
  }

  if(motorDirection == 1){
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  

  prevDirectionState = directionState;

}
