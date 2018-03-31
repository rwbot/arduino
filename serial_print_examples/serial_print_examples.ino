void setup() {
  Serial.begin(9600);
}

void loop() {
  //Serial.print();
  Serial.println( "string" );
  
  Serial.println( "yo" "ho" "lo");
  
  String x = "yuh";
  String y = "muma";
  Serial.println( x + y );

  int num = 69;
  Serial.println( "raw" + String(num) + " like a dragon" );

}
