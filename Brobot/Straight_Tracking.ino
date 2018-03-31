/*
master - slave relationship, using encoders
Each integer will represent 2.96mA
So for example, if the analogRead(A0) produces a value of 121 
The motor (or load) is drawing 0.36 amps.
Try full speed on USB power
Try full speed on 9V or larger power source
*/

float master(){
  return analogRead(senseL);
}

float slave(){
  return analogRead(senseR);
}

float getError(){
  error = master() - slave();
  return error;
}

void correctSlaveSpeed(){
  if(error > 0){
    analogWrite(speedR, s+getError());
  } else {
    analogWrite(speedR, s-getError());
  }

}

String stringWheelValues(){
  masterVal = analogRead(senseL);
  slaveVal = analogRead(senseR);
  String reading1 = "Master L: " + masterVal;
  String reading2 =" Slave R: " + slaveVal;
  String reading = reading1 + reading2;
  return reading;
}

void printWheelValues(){
  masterVal = analogRead(senseL);
  slaveVal = analogRead(senseR);
  Serial.print("MasterL: ");
  Serial.print(masterVal);
  Serial.print(" SlaveR: ");
  Serial.print(slaveVal); 
  Serial.print(" Error: ");
  Serial.println(getError());
}

//Motor Sheild Tutorial Current Sensing
void tutorialCurrentSensing(){
  float current = 0.00296*analogRead(A0);  //Calcualtes the Current 
  Serial.print(current);    //Prints the current to the terminal
  Serial.println(" amps");  //adds the suffix "amps" to the terminal
  delay(500);  //half second delay between the serial prints
}





