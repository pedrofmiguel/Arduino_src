boolean started =  false ;
int IrSensorVal = 0;
void setup() {
  pinMode(7,INPUT);
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  
  delay(20); 
  IrSensorVal = digitalRead (7) ; 
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    switch (inByte) {
      case '0':
        Stop(); 
        break;
      case '1':  
        Start();
        break;
    }
  }

//  if (started) {
if(digitalRead(7) == 0)
{ 
  Serial.println("1");
 // digitalWrite(13,HIGH);
  }

}

void Start(){
   if (started) {
    Serial.println("Invalid");
  } else {
    started = true; 
    Serial.println("Start");
}
}

void Stop(){
  if (!started) {
    Serial.println("Invalid");
  } else {
    started = false; 
    Serial.println("Stop");
}
}
