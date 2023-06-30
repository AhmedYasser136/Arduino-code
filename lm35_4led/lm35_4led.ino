
////////////////////////////////////////
#include <LiquidCrystal.h>
LiquidCrystal lcd(23,25,27,29,31,33,35,37,39,41); 

int value=0;            //initializing variables
float volts=0.0;      
float temp=0.0;      
float tempF=0.0;

void setup()
{
  pinMode(6,OUTPUT);      //setting arduino pin3 as input
  pinMode(7,OUTPUT);      //setting arduino pin3 as input
  pinMode(8,OUTPUT);      //setting arduino pin3 as input

  
  
  Serial.begin(9600);   // opens serial port, sets data rate to 9600 bps
  lcd.begin(16,2);      // set up the LCD's number of columns and rows
 
  
}

void loop()
{
  value=analogRead(A15);          //read from A0
  volts=(value/1024.0)*5.0;      //conversion to volts
  temp= volts*100.0;             //conversion to temp Celsius
  tempF=temp*9/5+32;             //conversion to temp Fahrenheit

//display temp no lcd

  Serial.print("temperature= "); 
  Serial.println(temp);
  lcd.setCursor(0,0);
  lcd.print("TEMP= ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("TEMP= ");
  lcd.print(tempF);
  lcd.print(" F");
 
 if  (   temp >100)///////////////////////////////////////////////
    digitalWrite( 6 , HIGH);
 // delay(500);
 
  if  (   temp >200)/////////////////////////////////////////////
    digitalWrite( 7 , HIGH);
 // delay(500);
 
  if  (   temp >300)///////////////////////////////////////////
    digitalWrite( 8 , HIGH);
 // delay(500);


  if  (   temp <100)
    digitalWrite( 6 , LOW);

    
if  (   temp <200)
    digitalWrite( 7 , LOW);
    
if  (   temp <300)
    digitalWrite( 8 , LOW);

  
}
