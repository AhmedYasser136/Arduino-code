int r1 = 1;
int r2 = 2;
int R1 = 3;
int R2 = 4;
int trig1 =5;
int echo1 =6;

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
  
  return distance;
}
void straight()
{
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW );
  digitalWrite(R1,HIGH);
  digitalWrite(R2,LOW );
}
void back()
{
  digitalWrite(r1,LOW );
  digitalWrite(r2,HIGH);
  digitalWrite(R1,LOW );
  digitalWrite(R2,HIGH);
}
void right()
{
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW );
  digitalWrite(R1,LOW );
  digitalWrite(R2,HIGH);
}
void left()
{
  digitalWrite(r1,LOW );
  digitalWrite(r2,HIGH);
  digitalWrite(R1,HIGH);
  digitalWrite(R1,LOW );
}
void setup()
{
   pinMode(r1,   OUTPUT);
   pinMode(r2,   OUTPUT);
   pinMode(R1,   OUTPUT);
   pinMode(R2,   OUTPUT);
   pinMode(echo1, INPUT);
   pinMode(trig1,OUTPUT);
;
}

void loop() 
{
  if (distance>20)
{
    straight();
  }
  
  if (distance>5)
  {
    right();
  }
  
  if (distance<5)
  {
    back ();
    delay(200);
    right();
  }
}
