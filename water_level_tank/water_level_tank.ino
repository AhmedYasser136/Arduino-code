#include <LiquidCrystal.h>
int level_1   = A1;
int level_2   = A2;
int level_3   = A3;
int level_4   = A4;
int level_5   = A5;
int pin_motor = 6;
int a;
int b;
int c;
int d;
int e;
int r; //Water Pump status
int z=100; 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
pinMode(level_1,INPUT);
pinMode(level_2,INPUT);
pinMode(level_3,INPUT);
pinMode(level_4,INPUT);
pinMode(level_5,INPUT);
pinMode(pin_motor,OUTPUT);
lcd.begin(16, 2);
digitalWrite(pin_motor , HIGH);
}

void loop()
{
  
r=digitalRead(pin_motor);
a=analogRead(level_1);
b=analogRead(level_2);
c=analogRead(level_3);
d=analogRead(level_4);
e=analogRead(level_5);
lcd.clear();


if(e>z && d>z && c>z && b>z && a>z )
{
  digitalWrite(pin_motor,HIGH);
  lcd.setCursor(0,0);
  lcd.print("Tank is 100% ");
}
else if(e<z && d>z && c>z && b>z && a>z )
{
  lcd.setCursor(0,0);
  lcd.print("Tank is 80% ");
}
else if(e<z && d<z && c>z && b>z && a>z )
{
  lcd.setCursor(0,0);
  lcd.print("Tank is 60% ");
}
else if(e<z && d<z && c<z && b>z && a>z )
{
  lcd.setCursor(0,0);
  lcd.print("Tank is 40%    ");
}
else if(e<z && d<z && c<z && b<z && a>z )
{
  lcd.setCursor(0,0);
  lcd.print("Tank is 20% ");
}

else if(e<z && d<z && c<z && b<z && a<z )
{
  
  digitalWrite(pin_motor,LOW);
  lcd.setCursor(0,0);
  lcd.print("Tank is EMPTY   ");
}

if(r==LOW)
{
  lcd.setCursor(0,1);
  lcd.print("Pump is (ON)     ");
}
else
{
  lcd.setCursor(0,1);
  lcd.print("Pump is (OFF)      ");
}

  delay(10);
  lcd.clear();

}
