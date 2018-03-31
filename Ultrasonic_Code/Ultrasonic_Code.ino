//Ultrasonic Sensors
//Left
#define triggerL 
#define echoL 
float timeL = 0;
float distanceL = 0;
//Right
#define triggerR 
#define echoR 
float timeR = 0;
float distanceR = 0;
//Front
#define triggerH A4
#define echoH A5
float timeH = 0;
float distanceH = 0;

 /**Function to send an ultrasonic signal and calculate the distance at that point
 * returns float distance in centimeters (cm)
 */
float sonarL(){
    digitalWrite(triggerL, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerL, HIGH);
    delayMicroseconds(10);
    timeL = pulseIn(echoL, HIGH);
    distanceL = timeL/58;
    return distanceL;
} 

float sonarH(){
    digitalWrite(triggerH, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerH, HIGH);
    delayMicroseconds(10);
    timeH = pulseIn(echoH, HIGH);
    distanceH = timeH/58;
    return distanceH;
} 

float sonarR(){
    digitalWrite(triggerR, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerR, HIGH);
    delayMicroseconds(10);
    timeR = pulseIn(echoR, HIGH);
    distanceR = timeR/58;
    return distanceR;
}

proximity proxL(){
  if(sonarL() > fnt){
    return F;
  } else {
    return N;
  }
}

proximity proxH(){
  if(sonarH() > fnt){
    return F;
  } else {
    return N;
  }
}

proximity proxR(){
  if(sonarR() > fnt){
    return F;
  } else { 
    return N;
  }
}


//function that returns the derivative of the sonar reading of the parameter side
//LL = left. HH = head, RR = right
float d(side s){
  float y1;
  float y2;
  if(s == LL){
    y1 = sonarL();
    y2 = sonarL();
  } else if(s == HH){
    y1 = sonarH();
    y2 = sonarH();
  } else if(s == RR){
    y1 = sonarR();
    y2 = sonarR();
  }
  return y2 - y1;
}



void testSonar(){
  Serial.print("SonarL: ");
  Serial.print(sonarL());
  
  Serial.print(" SonarH: ");
  Serial.print(sonarH());
  
  Serial.print(" SonarR: ");
  Serial.println(sonarR());
}


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
