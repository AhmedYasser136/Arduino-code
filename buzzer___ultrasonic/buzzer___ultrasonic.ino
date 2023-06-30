int buzzer1= 12; 
int trig1  = 8;
int echo1  = 9;
float duration;
float distance;
float ultrasonic()
{
  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);
  duration=pulseIn(echo1,HIGH);
  distance=0.034*duration/2;
  Serial.print ("distance =");
Serial.println(distance);

}

void setup()
{
   pinMode(buzzer1   ,   OUTPUT);
  
 
   pinMode(echo1    ,    INPUT);
   pinMode(trig1    ,   OUTPUT);
}

void loop() 
{


  
  if (distance < 20)
{
     digitalWrite (buzzer1 ,HIGH );
  //   delay (100);
 
  }
  else 
  {
  digitalWrite ( buzzer1 , LOW );
   delay (1000);
   
}
  
}
