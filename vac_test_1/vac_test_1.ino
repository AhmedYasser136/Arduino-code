int trig1  = 44;
int echo1  = 46;

int r1 = 7;//rf
int r2 = 8;//rb

int en1 = 6;
int en2 = 3;

int R1 = 5;//lb
int R2 = 4;//lf


int ir1 =  A0;
int ir2 =  A1;

int A = 0;
int Y;



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
  digitalWrite(r2, en1); //يمين
  digitalWrite(R1, 0);
  digitalWrite(R2, en2); // شمال
}
void right()
{
  digitalWrite(r1, 0);
  digitalWrite(r2, 0);
  digitalWrite(R1, 0);
  digitalWrite(R2, en2 );
}
void left()
{
  digitalWrite(r1, 0);
  digitalWrite(r2, en1);
  digitalWrite(R1, 0);
  digitalWrite(R2, 0 );
}

#include <LiquidCrystal.h>
LiquidCrystal lcd(23, 25, 27, 29, 31, 33, 35, 37, 39, 41);
//***************  RS  E   D4  D5 D6 D7
float Amp, Pw, Voltres, Voltin;

int relay1 = 50;
int sw1 = 49;

int relay2 = 52;
int sw2 = 45;

int Y1 ;
int Y2 ;

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


  lcd.begin(16, 2);
  Serial.begin (9600);


  pinMode(relay1, OUTPUT);
  pinMode(sw1, INPUT);

  pinMode(relay2, OUTPUT);
  pinMode(sw2, INPUT);





}

void loop() {


  int ADC0 = analogRead(A15);
  int ADC1 = analogRead(A15);



  //**************حساب التوتر *****************//
  Voltin   = ADC1 * 4.88 * 0.00601;

  Pw       = Voltin * Amp * 0.001 ;


  lcd.setCursor(4, 0);
  lcd.print("V:");
  lcd.print(Voltin);
  lcd.print("V");



  Y1 = digitalRead (sw1);
  if (Y1 == HIGH) {
    digitalWrite(relay1 , HIGH );
  }

  else  digitalWrite(relay1 , LOW );

  Y2 = digitalRead (sw2);
  if (Y2 == HIGH) {
    digitalWrite(relay2 , HIGH );
  }

  else  digitalWrite(relay2 , LOW );




  analogWrite(en1 , 100);  
  analogWrite(en2 , 100); 
  Serial.print ("distance =");
  Serial.println(distance);

  ultrasonic();
  if (distance < 25)
  {
    A++;
  }

  if ( A == 0  || A == 2 )
  {
    straight();

  }

  if (A == 1)
  {
    left ();
    delay(2700);//////////////////
    A = 2;
  }

  if (A == 3)
  {
    right ();
    delay(3000);/////////////////
    A = 4;
  }


  if (A == 4)
  {
    A = 0 ;
  }

  Serial.println(A);

}
