// Ahmed Yasser
// 2 motor industrial

int M1 = 5;
int M2 = 6;

int M3 = 7;
int M4 = 8;

int en1 = 9;
int en2 = 10;

int ir = 4;
int A = 0;
int Y;

void setup()
{

  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(ir, INPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  Y = digitalRead (ir);
  if (Y == HIGH) {


    
    while(Y==1){
 Y=digitalRead(ir);
}

 
 
 delay (100);
    A++;

 //   if (A == 2) A = 0;

  }

  analogWrite(en1 , 100);
  analogWrite(en2 , 1000);

  Serial.print(A);
  Serial.print("  \n   ");

  digitalWrite( M1 , 1 );
  digitalWrite( M2 , 0 );
  digitalWrite( M3 , 0 );
  digitalWrite( M4 , 0 );



  if ( A == 2  ) {

    digitalWrite( M1 , 0 );
    digitalWrite( M2 , 0 );
    digitalWrite( M3 , 1 );
    digitalWrite( M4 , 0 );
    delay(1000);
    A = 0 ;
  }


}
