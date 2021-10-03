
void setup() {
pinMode(24,OUTPUT);

pinMode(25,INPUT);

Serial.begin(9600);
}

void loop() {

// dynamic line follower code
// if the sensor is on white it returns LOW value to the Arduino
// if it is on black it returns a HIGH value to the Arduino
digitalWrite(24,HIGH);


int lsensorreciever=digitalRead(25);


if(lsensorreciever==HIGH)
{
Serial.println("Im on BLack");

}
else if(lsensorreciever==LOW)
{
//right sensor on black line
// turn right
Serial.println("Im on white");

}

}
