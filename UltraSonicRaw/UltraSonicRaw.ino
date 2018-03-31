const int trigger = A2; //orange  
const int echo = A3;    //red
float time_taken = 0;   // 'time' is a keyword
float distance = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Distance: " + String( sonar() ) + "cm");
}

/**Function to send an ultrasonic signal 
 * and calculate the distance at that point
 * returns float distance in centimeters (cm)
 */
float sonar(){
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    
    time_taken = pulseIn(echo, HIGH);
    distance = time_taken/58;
    return distance;
}
