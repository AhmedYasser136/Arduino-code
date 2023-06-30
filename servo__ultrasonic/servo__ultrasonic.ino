/* Servo motor with Arduino example code. Position and sweep. More info: https://www.makerguides.com/ */

// Include the servo library:
#include <Servo.h>

// Create a new servo object:
Servo myservo;

// Define the servo pin:
#define servoPin 9

// Create a variable to store the servo position:
int angle = 0;
int trig1  = 13;
int echo1  = 12;
float duration;
int distance;
void setup() {
  // Attach the Servo variable to a pin:
  myservo.attach(servoPin);
  pinMode(echo1, INPUT);
   pinMode(trig1,OUTPUT);
   Serial.begin (9600);
}

void loop() {
  
  /*
  
  // Tell the servo to go to a particular angle:
  myservo.write(90);
  
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(90);
  delay(1000);
    myservo.write(0);
  delay(1000);
  
  */  
  

 digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);
  duration=pulseIn(echo1,HIGH);
  distance=0.034*duration/2;
  Serial.print ("distance =");
Serial.println(distance);

  // Sweep from 0 to 180 degrees:
  for (angle = 0; angle <= 180; angle += 1) {
    myservo.write(angle);
   delay(10);
  }
 
  // And back from 180 to 0 degrees:
  for (angle = 180; angle >= 0; angle -= 1) {
    myservo.write(angle);
   delay(10);
  }




}
