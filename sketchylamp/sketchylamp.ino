int in8 = 8;

void setup() {
  pinMode(in8, OUTPUT);
  digitalWrite(in8, HIGH);  //off
  Serial.begin(9600);
  while(! Serial);
}


void loop() 
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch == 'y')
    {
      digitalWrite(in8, LOW); //on
    }
    if (ch == 'n')
    {
      digitalWrite(in8, HIGH);  //off
    }
  }
}
