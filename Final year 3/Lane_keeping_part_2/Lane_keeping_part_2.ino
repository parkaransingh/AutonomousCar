#include <AFMotor.h>
AF_DCMotor motor1(1,MOTOR12_64KHZ); // set up motors.
AF_DCMotor motor2(2, MOTOR12_64KHZ);

//LOW white
//HI black
//Motor 2 is steering motor 
void setup() {
pinMode(24,OUTPUT);//470 resistor - left side(LED Cathode)
pinMode(48,OUTPUT);//470 resistor- right side

  motor1.setSpeed(255); //set the speed of the motors, between 0-255
  motor2.setSpeed (255);

pinMode(25,INPUT);//Left photo
pinMode(49,INPUT);//right photo

}

void loop() {
digitalWrite(24,HIGH);
digitalWrite(48,HIGH);
// dynamic line follower code
// if the sensor is on white it returns LOW value to the Arduino
// if it is on black it returns a HIGH value to the Arduino
int lsensor=digitalRead(25);
int rsensor=digitalRead(49);
if((lsensor==HIGH)&&(rsensor==HIGH))
{
//both sensors on BLACk
// go forward Without turning
motor1.run(FORWARD);
motor2.run(RELEASE);

}
else if((lsensor==HIGH)&&(rsensor==LOW))
{
//right sensor on white lane marking
// turn left
motor1.run(FORWARD);
motor2.run(FORWARD);// Turns the steering left

}
else if((lsensor==LOW)&&(rsensor==HIGH))
{
//left sensor on white lane marking
// turn Right
motor1.run(FORWARD);
motor2.run(BACKWARD);//Turns the motor Right

}
else if((lsensor==LOW)&&(rsensor==LOW))
{
  // Sensors are on the white lane markings meaning at the stop sign
  motor1.run(RELEASE);
  motor2.run(RELEASE);
digitalWrite(36, HIGH);
}
else
{
motor1.run(FORWARD);
motor2.run(RELEASE);
}
}
