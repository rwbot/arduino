const int stripe = 7;
int val;

void setup() {
  pinMode(stripe, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Val: ");
  val = analogRead(stripe);
  Serial.print(val);

  if(val > 200){
    Serial.println("  Black");
  } else {
    Serial.println("  White");
  }
  
}
