/*
Example Code to demonstrates current sensing with the Arduino Motor Shield.  
This Code Turns the Motor on and prints to the Serial terminal the current.

Each integer will represent 2.96mA
So for example, if the analogRead(A0) produces a value of 121 
The motor (or load) is drawing 0.36 amps.
*/


void setup() {
  Serial.begin(19200);    //Sets up the serial port 
  
  pinMode(12,OUTPUT);     //Channel A Direction Pin Initialize
  digitalWrite(12, HIGH); //Channel A Direction Forward
  analogWrite(3, 255);    //Channel A Speed 100%
  delay(1000);            //1 Second Delay
}

void loop() {
  float current = 0.00296*analogRead(A0);  //Calcualtes the Current 
  Serial.print(current);    //Prints the current to the terminal
  Serial.println(" amps");  //adds the suffix "amps" to the terminal
  delay(500);  //half second delay between the serial prints
}
