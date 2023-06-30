/* 
   -- New project -- 
    
   This source code of graphical user interface  
   has been generated automatically by RemoteXY editor. 
   To compile this code using RemoteXY library 2.3.3 or later version  
   download by link http://remotexy.com/en/library/ 
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                    
     - for ANDROID 4.1.1 or later version; 
     - for iOS 1.2.1 or later version; 
     
   This source code is free software; you can redistribute it and/or 
   modify it under the terms of the GNU Lesser General Public 
   License as published by the Free Software Foundation; either 
   version 2.1 of the License, or (at your option) any later version.     
*/ 

////////////////////////////////////////////// 
//        RemoteXY include library          // 
////////////////////////////////////////////// 

// RemoteXY select connection mode and include library  
#define REMOTEXY_MODE__HARDSERIAL

#include <RemoteXY.h> 

// RemoteXY connection settings  
#define REMOTEXY_SERIAL Serial 
#define REMOTEXY_SERIAL_SPEED 9600 


// RemoteXY configurate   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,3,0,0,0,11,0,8,13,0,
  6,0,39,2,58,58,2,26 }; 
   
// this structure defines all the variables of your control interface  
struct { 

    // input variable
  uint8_t rgb_1_r; // =0..255 Red color value 
  uint8_t rgb_1_g; // =0..255 Green color value 
  uint8_t rgb_1_b; // =0..255 Blue color value 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY; 
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 
#define r 9
#define g 10
#define b 11


void setup()  
{ 
  RemoteXY_Init ();  
  pinMode (r, OUTPUT);
  pinMode (g, OUTPUT);
  pinMode (b, OUTPUT); 
   
  // TODO you setup code 
   
} 

void setColor(int red, int green, int blue)
{
analogWrite(r, red);
analogWrite(g, green);
analogWrite(b, blue);
}

void loop()  
{  
  RemoteXY_Handler (); 
  setColor(RemoteXY.rgb_1_r, RemoteXY.rgb_1_g, RemoteXY.rgb_1_b);  
   
  // TODO you loop code 
  // use the RemoteXY structure for data transfer 


}

