//Function          Channel A   Channel B
//Direction         D 12        D 13
//Speed (PWM)       D 3         D 11
//Brake             D 9         D 8
//Current Sensing   A 0         A 1

//Channel A
#define directionL 12     //Channel A
#define speedL 3
#define brakeL 9 
#define senseL A0

//Channel B 
#define directionR 13          //Channel B
#define speedR 11
#define brakeR 8
#define senseR A1

byte s = 169;                 //Constant speed
int masterVal;
int slaveVal;
float error;

enum driveDirection { forward, backward };  
enum turnDirection { right, left, around };
enum brakeStatus{ ON, OFF };
//enum state { scan, gogogo,  };

//Ultrasonic Sensor
#define trigger A2
#define echo A3
float time = 0;
float distance = 0;


void setup() {
  //Ultrasonic setup
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  
  //Channel A setup
  pinMode(directionL, OUTPUT);
  pinMode(brakeL, OUTPUT);
  pinMode(speedL, OUTPUT);
  digitalWrite(speedL, LOW);
  
  //Channel B setup
  pinMode(directionR, OUTPUT);
  pinMode(brakeR, OUTPUT);
  pinMode(speedR, OUTPUT);
  digitalWrite(speedR, LOW);

  setbrake(ON);
  Serial.begin(9600);
  delay(5000);
}

//main loop
void loop() {
  //navigate();
  go(forward);
  //Serial.print(stringWheelValues());
  printWheelValues();
  delay(200);
}


