int pitch;
int prVal;
int prL = 1023;
int prH = 0;
int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600);

  
  
  while (millis() < 5000) {
    prVal = analogRead(A0);
    Serial.print(prVal);
  Serial.print("  ");
    if (prVal < prL){
      prL = prVal;
    } 
    Serial.print(prL);
  Serial.println("  ");
    if (prVal > prH) {
      prH = prVal;
    }
    Serial.print(prH);
  Serial.print("  ");
    delay(5);
  }
  digitalWrite(ledPin, LOW);


}

void loop() {
  // put your main code here, to run repeatedly:
  prVal = analogRead(A0);
  Serial.print(prVal);
  Serial.print("  ");
  
  pitch = map(prVal, prL, prH, 50, 4000);
  Serial.println(pitch);

  tone(8, pitch, 30);
  delay(20);

  

}
