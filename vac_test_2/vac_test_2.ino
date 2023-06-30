int trig1  = 12;
int echo1  = 11;

int r1 = 2;//rf
int r2 = 4;//rb

int en1 = 5;
int en2 = 6;

int R1 = 7;//lb
int R2 = 8;//lf


int ir1 =  A0;
int ir2 =  A1;

int A = 0;
int Y;


int reading1;
int reading2;



float duration;
int distance;

float ultrasonic()
{
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  duration = pulseIn(echo1, HIGH);
  distance = 0.034 * duration / 2;
}


void straight()
{
  digitalWrite(r1, 0);
  digitalWrite(r2, en1);
  digitalWrite(R1, 0);
  digitalWrite(R2, en2);
}
void right()
{
  digitalWrite(r1, en1);
  digitalWrite(r2, 0);
  digitalWrite(R1, 0);
  digitalWrite(R2, en2 );
}
void left()
{
  digitalWrite(r1, 0);
  digitalWrite(r2, en1);
  digitalWrite(R1, en2);
  digitalWrite(R2, 0 );
}

void stop()
{
  digitalWrite(r1, 0);
  digitalWrite(r2, 0);
  digitalWrite(R1, 0);
  digitalWrite(R2, 0);
}

void setup() {

  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);

  pinMode(r1,   OUTPUT);
  pinMode(r2,   OUTPUT);
  pinMode(R1,   OUTPUT);
  pinMode(R2,   OUTPUT);

  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);



  Serial.begin (9600);
}

void loop() {

  analogWrite(en1 , 255); // الشمال
  analogWrite(en2 , 225); // اليمين
  //Serial.print ("distance =");
  //Serial.println(distance);
  /*
    ultrasonic();
    if (distance >= 12)
    {
      straight();
    }

    if (distance < 12)
    {
    right();
    delay(500);
        straight();

    }
  */



  reading1 = digitalRead(ir1);
  reading2 = digitalRead(ir2);

  //  Serial.println(reading1);
  if ( reading1 == LOW && reading2 == LOW  )
  {
    straight();
    Serial.println ("straight");

  }

  if  ( reading1 > reading2  )
  {
    left();
    Serial.println ("left");
  }

if  ( reading1 < reading2  )
  {
    right();
delay
    
    Serial.println ("right");
  }


  Serial.print ("A1 =");
  Serial.println(reading1);

  Serial.print ("A2 =");
  Serial.println(reading2);

  



  if ( reading1 == HIGH  && reading2 == HIGH  )
  {
    Serial.println ("stop");
    stop();
  }


}
