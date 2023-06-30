int r1 = 3;//rf
int r2 = 5;//rb
int R1 = 6;//lb
int R2 = 9;//lf
int trig1 = 2;
int echo1 = 4;
int trig2 = 7;
int echo2 = 8;
int trig3 = 10;
int echo3 = 11;
float duration1;
float duration2;
float duration3;
float distance1;
float distance2;
float distance3;
float ultrasonic1()
{
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  duration1 = pulseIn(echo1, HIGH);
  distance1 = 0.034 * duration1 / 2;
}
float ultrasonic2()
{ digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  duration2 = pulseIn(echo2, HIGH);
  distance2 = 0.034 * duration2 / 2;
}
float ultrasonic3()
{
  digitalWrite(trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);
  duration3 = pulseIn(echo3, HIGH);
  distance3 = 0.034 * duration3 / 2;
}
void straight()
{
  analogWrite(r1, 110);
  analogWrite(r2, 0);
  analogWrite(R1, 0);
  analogWrite(R2, 110);
}
void right()
{
  analogWrite(r1, 0);
  analogWrite(r2, 85);
  analogWrite(R1, 0);
  analogWrite(R2, 85 );
}
void left()
{
  analogWrite(r1, 85);
  analogWrite(r2, 0);
  analogWrite(R1, 85);
  analogWrite(R2, 0 );
}
void setup()
{
  pinMode(r1,   OUTPUT);
  pinMode(r2,   OUTPUT);
  pinMode(R1,   OUTPUT);
  pinMode(R2,   OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(trig3, OUTPUT);
}
void loop() 
  {
    ultrasonic1();
    ultrasonic2();
    ultrasonic3();



    
  if (distance1>12)  
  {
   straight();
  if (distance2<4.50)  
 left();
delay(2);// تعديل هنااااا
 if (distance3<4.50) 
  right();
 delay(2);
 }


 
 if (distance1<=12)
  {
   
    
    
    
    if (distance2>40)   // تعديل هنااااا
  {
   right ();
  if (distance2<5)  
 left();
 delay(2);
   if (distance3<5) 
  right();
  delay(2);
   }




   
    if (distance2<10)// تعديل هنااااا
  {


    
     if (distance3>10)
  {
    left ();
if (distance2<5)  
 left(); 
 delay(2);
 if (distance3<5) 
  right();
  delay(2);
  
  }
  }
  } 
  }
