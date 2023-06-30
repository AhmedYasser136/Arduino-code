#define IR A1

int reading;


int led = 9;




void setup() {
  Serial.begin(9600);



     pinMode (led , OUTPUT  );

}



void loop() {
  reading = digitalRead(IR);

  Serial.println(reading);
if ( reading == HIGH)
{
digitalWrite(led ,HIGH);
}

else
{
digitalWrite(led , LOW);
}

  
}
