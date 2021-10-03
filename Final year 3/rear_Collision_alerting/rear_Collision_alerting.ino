 #define trigPin2 33 // Rear sensors
#define echoPin2 32
void setup() {
  Serial.begin(9600);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}
void loop() {
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) / 29.1;
  if (distance2 <= 40)
  {
    Serial.println("A Vehicle Seems to be Following You very closely");
    delay(900);
    Serial.println ("Rear Car Details:");
    Serial.println ("Distance From Car is" );
    Serial.print ( distance2);
    Serial.print ( "CM!");// print out the distance in centimeters.
  }
  else  {
    Serial.println("NO Car is Following you closely");
    delay(500);
    
  }
}
