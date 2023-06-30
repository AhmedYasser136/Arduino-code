int x;
int y;
int flamesen = A2;
int gas = A3;
int relay1 = 3;
int relay2 = 2;
int bz1 = 10;
int bz2 = 11;
void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);


}

void loop()
{
  x = analogRead(flamesen);
  y = analogRead(gas);

  Serial.print("  ///   ");
  Serial.print(A0);
  Serial.print("   //// ");
  Serial.print("  ///   ");
  Serial.print(A1);
  Serial.print("  \n   ");

  if (x < 100) { //fire detected
    digitalWrite(relay1, LOW);
    //delay(1000);
    tone(bz2, 4000); // Send 1KHz sound signal...
    delay(500);        // ...for 1 sec
    tone(bz2, 1000); // Send 1KHz sound signal...
    delay(500);        // ...for 1 sec
    tone(bz2, 4000); // Send 1KHz sound signal...
    delay(500);        // ...for 1 sec
    tone(bz2, 1000); // Send 1KHz sound signal...
    delay(500); 
    tone(bz2, 4000); // Send 1KHz sound signal...
    delay(500);        // ...for 1 sec
    tone(bz2, 1000); // Send 1KHz sound signal...
    delay(500); 
    
    noTone(bz2);     // Stop sound...
    // delay(1000);        // ...for 1sec
  }

  else {
    noTone(bz2);     // Stop sound...
    digitalWrite(relay1, HIGH);
  }


  if (y < 600) {
    digitalWrite(relay2, HIGH);
    noTone(bz1);     // Stop sound...

  }

  else {
    digitalWrite(relay2, LOW);
    tone(bz1, 1500); // Send 1KHz sound signal...
    delay(500);        // ...for 1 sec
    tone(bz1, 3000); // Send 1KHz sound signal...
    delay(500);        // ...for 1 sec
    tone(bz1, 1500); // Send 1KHz sound signal...
    delay(500); 
    tone(bz1, 3000); // Send 1KHz sound signal...
    delay(500);        // ...for 1 sec
    tone(bz1, 1500); // Send 1KHz sound signal...
    delay(500);        // ...for 1 sec
    tone(bz1, 3000); // Send 1KHz sound signal...
    delay(500); 

    
    noTone(bz1);     // Stop sound...

  }
}
