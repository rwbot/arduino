/**Ultrasonic Sensor (Model# HC-SR04) Tutorial
 * by @rwbot
 */
 
const int trigger = A2; //orange
const int echo = A3;    //yellow
float time_taken = 0;
int distance = 0;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop(){
  int raw = sonarRaw();
  Serial.println( "Distance: " + String(raw) + "cm" );
}



/**Sends an ultrasonic wave, measures raw echo time
 * Then calculates & returns the raw distance in centimeters (cm)
 */
int sonarRaw(){
    /**
     * TBH I don't understand all of the digital logic 
     * of these 4 lines from the Manufacturer's code
     * I see it as like a revolver
     * First turning the trigger LOW seems like the cocking the trigger
     * And then turning the trigger HIGH seems like actually pulling the trigger
     * In cases like this where manufacturers just say "use this code"
     * and you don't really understand it, its better to just box it in 
     * a function that can just call and not worry about having to rewrite the code
     */
    //Cocking the trigger
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    //Pulling the trigger
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);


    //pulseIn(pin, HIGH/LOW) records time taken for the pin to become HIGH/LOW
    //Here pulseIn(echo, HIGH) implies echo is default LOW
    //and is only HIGH for a fraction of a second when echo is received
    //So this records time taken for echo pin to receive a signal and become HIGH
    time_taken = pulseIn(echo, HIGH);
    
    distance = time_taken/58;
    return distance;
}


/**Sends an ultrasonic wave, measures the echo time if in range
 * Then calculates & returns the int distance in centimeters (cm)
 * TIMEOUT 10,000 microseconds (10ms) to prevent false readings  
 * Range accurate only up until ~150cm or ~5 feet
 * Returns 0 if target out of range
 */
int sonarRanged(){
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);

    //pulseIn(pin, HIGH/LOW) records time taken for the pin to become HIGH/LOW
    //Here pulseIn(echo, HIGH) implies echo is default LOW
    //and is only HIGH for a fraction of a second when echo is received
    //So this records time taken for echo pin to receive a signal and become HIGH
    //BUT this restrains echo time to 10,000 microseconds (10ms), which equals ~150cm or ~5ft
    //Past that range, there is too much interference
    time_taken = pulseIn(echo, HIGH, 10000);
    
    distance = time_taken/58;
    return distance;
}


/**Interprets raw sonar input into meaningful output
 * If sonarRanged() returns 0 (d<0.5), sends Error Message
 * If the distance is within range, returns output message
 */
String sonarOut(int d){
  String out = "Target Too Far or Too Absorbent";
  if(d > 0.5){
    out = "Distance: " + String(d) + "cm";
  } 
  return out;
}




