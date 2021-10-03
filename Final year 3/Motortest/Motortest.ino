#include <AFMotor.h>
 // set up motors.
AF_DCMotor motor2(2,MOTOR12_64KHZ);
AF_DCMotor motor1(1,MOTOR12_64KHZ);
void setup() {
  motor2.setSpeed(255);
  motor1.setSpeed(255);
  //set the speed of the motors, between 0-255
  }
 
void loop() { 
 
  motor2.run(FORWARD);
  motor1.run(FORWARD);
}
