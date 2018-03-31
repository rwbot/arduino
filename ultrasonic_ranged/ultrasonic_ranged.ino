/***
 * ultrason ranged
 * Tutorial on formatting Ultrasonic Data
 * @rwbot
 * v1.1
 */

const int trigger = A2; //orange
const int echo = A3;    //yellow
float time_taken = 0;
float distance = 0;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  int raw = sonarRaw();
  //Converts raw sonar value to meaningful output, returned as String
  String out = sonarOut(raw);
  Serial.print("raw: " + String(raw) + "cm  ~  " + out);
}

/**Sends an ultrasonic wave and measures the echo time
 * Then calculates & returns the float distance in centimeters (cm)
 * TIMEOUT 10,000 microseconds (10ms) to prevent false readings  
 * Range accurate only up until ~150cm or ~5 feet
 */
float sonarRaw(){
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    
    time_taken = pulseIn(echo, HIGH, 10000);
    //echo pin is default LOW. 
    //Only HIGH for a fraction of a second when echo is received
    //pulseIn records time taken for echo pin to become HIGH
    //but restrains echo time to 10ms, which equals ~150cm or ~5ft
    //Past that range, there is too much interference
    
    distance = time_taken/58;
    return distance;
}

String sonarOut(float d){
  String out = "Target Too Far or Too Absorbent";
  if(d > 0.5){
    out = "Distance: " + String(d) + "cm";
  } 
  return out;
}

