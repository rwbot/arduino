const int pr1 = A1;
const int pr2 = A2;
const int pr3 = A3;

const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

int redSValue = 0;
int greenSValue = 0;
int blueSValue = 0;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  redSValue = analogRead(pr1);
  greenSValue = analogRead(pr2);
  blueSValue = analogRead(pr3);
  Serial.print("Raw Sensor Value:\tRed: ");
  Serial.print(redSValue);
  Serial.print("\tGreen: ");
  Serial.print(greenSValue);
  Serial.print("\tBlue: ");
  Serial.print(blueSValue);
  Serial.println();

  redValue = redSValue/4 ;
  greenValue = greenSValue/4 ;
  blueValue = blueSValue/4 ;
  Serial.print("Mapped Sensor Value:\tRed: ");
  Serial.print(redValue);
  Serial.print("\tGreen: ");
  Serial.print(greenValue);
  Serial.print("\tBlue: ");
  Serial.print(blueValue);
  Serial.println();

  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

  Serial.println();
  




  

}
