const int sensorPin=A0;
const float baseline=21;
float sensorVal;
float v;
float temp;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  for(int i=2; i<5; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorVal = analogRead(sensorPin);
  Serial.print("sensor: ");
  Serial.print(sensorPin);

  v = (sensorVal/1024) * 5;
  Serial.print("voltage: ");
  Serial.print(v);
  
  temp = (v - 0.5) * 100; 
  Serial.print("Celcius: ");
  Serial.print(temp);

  Serial.println();

  if (temp > baseline+1)
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  if (temp > baseline+2)
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  if (temp > baseline+3)
    digitalWrite(4, HIGH);
}
