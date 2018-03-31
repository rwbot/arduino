//Motor 1
int directionL=4;      //Left motor direction
int speedL=5;          //left motor speed
//Motor 2
int directionR=7;      //Right motor direction   
int speedR=6;         //Right motor speed



void setup() {
  // put your setup code here, to run once:
  //Left Motor setup
  pinMode(directionL, OUTPUT);
  pinMode(speedL, OUTPUT);
  digitalWrite(speedL, HIGH);
  
  //Right Motor setup
  pinMode(directionR, OUTPUT);
  pinMode(speedR, OUTPUT);
  digitalWrite(speedR, HIGH);

  digitalWrite(directionL, LOW); 
  digitalWrite(directionR, LOW);
   analogWrite(speedL, 255);       
  analogWrite(speedR, 200);

}

void loop() {
  

}
