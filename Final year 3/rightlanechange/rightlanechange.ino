#define trigPinR 47 // Right Sensors
#define echoPinR 46
void setup() {
  Serial.begin(9600);
  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT);
  
}
void loop() {
  long durationR, distanceR;
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPinR, LOW);
  durationR = pulseIn(echoPinR, HIGH);
  distanceR = (durationR/ 2) / 29.1;
  if (distanceR <= 10)
  {
    Serial.println ("There is an object or Vehicle Detected on the Right of the Car");
    delay(500);
    Serial.println("It is recomended to not change to that lane");

  }
  else  {
    Serial.println("Nothing has been detected");
    delay(500);
    Serial.println("Driver may proceed changing the Lane");
   

  }
}
