const int trigger = A0;
const int echo = A1;
float time = 0;
float distance = 0;
int pitch;
const int piezoPin = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);

  time = pulseIn(echo, HIGH);
  distance = time/58;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("cm");

  pitch = map(distance, 0, 400, 50, 4000);
  tone(piezoPin, pitch, 20);
  
  Serial.print("    Pitch: ");
  Serial.print(pitch);
  Serial.println("hz");
}
