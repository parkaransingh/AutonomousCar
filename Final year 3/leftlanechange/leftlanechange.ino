#define trigPinL 27 // Left sensors
#define echoPinL 26
void setup() {
  Serial.begin(9600);
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT);
}
void loop() {
  long durationL, distanceL;
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPinL, LOW);
  durationL = pulseIn(echoPinL, HIGH);
  distanceL = (durationL/ 2) / 29.1;
  if (distanceL <= 10)
  {
    Serial.println ("There is an object or Vehicle Detected on the Left of the Car");
    

  }
  else  {
    Serial.println("Nothing has been detected");
    
 

  }
}
