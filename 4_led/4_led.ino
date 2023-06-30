// Example_6_fading_led_light
const int led5 = 5;  
const int led6 = 6;  

const int led7 = 7;  
const int led9 = 9;  

int i = 0;          
 
void setup( )  
{  
  
  pinMode(led5, OUTPUT);    
    pinMode(led6, OUTPUT);    
  pinMode(led7, OUTPUT);    
  pinMode(led9, OUTPUT);    

} 


void loop()
{     


 
  

 digitalWrite(led5, HIGH);      
 delay(100); 
digitalWrite(led5, LOW);      
 delay(100); 

 
  digitalWrite(led6, HIGH);      
 delay(100); 
 digitalWrite(led6, LOW);      
 delay(100); 

 
  digitalWrite(led7, HIGH);      
 delay(100); 
 digitalWrite(led7, LOW);      
 delay(100); 

  /*
  
   for 
    (i = 0; i < 255; i++)      
  {      analogWrite(led9, i);   

   
  delay(10);    
  }     
  for (i = 255; i > 0; i--)    
  
  {   
    
    analogWrite(led9, i);   

  
  delay(10);         
  } */
  } 
