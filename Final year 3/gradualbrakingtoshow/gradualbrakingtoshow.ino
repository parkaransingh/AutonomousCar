#include <AFMotor.h>
#define trigPin 41 // define the pins of front sensor
#define echoPin 39 // define the pins of front sensor

AF_DCMotor motor1(1,MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);// set up motors.

void setup() {
  Serial.begin(9600); // begin serial communitication  
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
  pinMode(36, OUTPUT);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  //set the speed of the motors, between 0-255
  }
 
void loop() { 
  long duration, distance; // start the scan
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //this delay is required. There needs to be individual waves. Breaking them apart
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);//
  distance = (duration/2) / 29.1; // convert the distance to centimeters.
      if (distance <= 25)
      {
    motor1.setSpeed(150);
 
    digitalWrite(36, HIGH);
  }
if(distance<=15){
  motor1.run(RELEASE);
  digitalWrite(36, HIGH);
  }
 else {
   motor1.run(FORWARD);
   motor2.run(RELEASE);
   digitalWrite(36, LOW);
 }
}

