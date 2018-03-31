#define t 5

void setup() {
  Serial.begin(9600);
  pinMode(t, INPUT);

}

void loop() {
  Serial.println(analogRead(t));

}
