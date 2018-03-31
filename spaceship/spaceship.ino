const int greenLed=3;
const int redLed1=4;
const int redLed2=5;

const int switchPin=2;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenLed,OUTPUT);
  pinMode(redLed1,OUTPUT);
  pinMode(redLed2,OUTPUT);

  pinMode(switchPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int switchState;

  switchState=digitalRead(switchPin);

  if(switchState == LOW){
    digitalWrite(greenLed, LOW);

    digitalWrite(redLed1, HIGH);
    digitalWrite(redLed2, LOW);
    delay(250);
    digitalWrite(redLed1, LOW);
    digitalWrite(redLed2, HIGH);
    delay(250);
  } else {
    digitalWrite(redLed1, LOW);
    digitalWrite(redLed2, LOW);

    digitalWrite(greenLed, HIGH);
  }

}
