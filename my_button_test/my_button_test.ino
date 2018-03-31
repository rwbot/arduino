int adc_key_val[5] ={50, 200, 400, 600, 800 };
int adc_key_in = 0;
int raw_val;
int b;

void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT);  //we'll use the debug LED to output a heartbeat
  Serial.begin(9600);
  Serial.println("start"); 
}

void loop() {
  // put your main code here, to run repeatedly:
  raw_val = read_raw();
  Serial.println(raw_val);
  //Serial.print("\t "); 
  b = raw_to_button(raw_val);
  Serial.println(b); 
  
}

int read_raw(){
  delay(50);
  adc_key_in = analogRead(7);    // read the value from the sensor  
  //Serial.print("raw: ");
  //Serial.println(adc_key_in);
  return adc_key_in;
}

int raw_to_button(int raw){
  int k;
  for (k = 0; k < 5; k++){
      if (raw < adc_key_val[k]){     // Get the button pressed 
            return k+1;
      } else {
        return 999;
      }
   }
}

