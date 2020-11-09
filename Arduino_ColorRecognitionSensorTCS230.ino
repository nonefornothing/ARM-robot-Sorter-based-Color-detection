/*
// TCS230 color recognition sensor 
// Sensor connection pins to Arduino are shown in comments

Color Sensor      Arduino
-----------      --------
 VCC               5V
 GND               GND
 s0                8
 s1                9
 s2                12
 s3                11
 OUT               10
 OE                GND
*/
#include <Servo.h>
Servo m1;
Servo m2;
Servo m3;
Servo m4;

int pos = 0;
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;   
// Variables  
int red = 0;  
int green = 0;  
int blue = 0;  
    
void setup()   
{  
  Serial.begin(9600); 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH); 

   m1.attach (2);
   m2.attach (3);
   m3.attach (4);
   m4.attach (5);
}  
    
void loop() 
{  
  color(); 
  Serial.print("R Intensity:");  
  Serial.print(red, DEC);  
  Serial.print(" G Intensity: ");  
  Serial.print(green, DEC);  
  Serial.print(" B Intensity : ");  
  Serial.print(blue, DEC);  
  //Serial.println();  

  

  if (red < blue && red < green && red < 20)
  {  
   Serial.println(" - (Red Color)");  
   m2.write (90);
   delay (30);

   m3.write (0);
   delay (30);
   m4.write (180);
   delay (30);
   m1.write (0);
   delay (600);

// Pengambilan Kotak

  for (pos=0; pos<= 66; pos +=1 ){
  m3.write (pos);
  delay (12);  
}
  m3.write (45);
  delay (200);

   m2.write (50);
   delay (500);
   m2.write (60);
   delay (500);

// Pencengkraman Gripper
  m1.write (90);
  delay (2000);

// peletakan objek
  for (pos=45 ; pos>= 0; pos -=1){

  m3.write (pos);
  delay (10);
}
  m4.write (40);
  delay (80);

  for (pos=0 ; pos<=40 ; pos +=1){
   m3.write (pos);
   delay (10);
    }  
    m3.write (45);
    delay (500);

    m1.write (0);
    delay (500);
  for (pos=45 ; pos>= 0; pos -=1){

  m3.write (pos);
  delay (10);
}
  for (pos = 75; pos<= 90; pos += 1){  
  m2.write (pos);
  delay (50);
}
  m4.write (180);
  delay (100);
  }  
  
  else if (blue < red && blue < green)   
  {  
   Serial.println(" - (Blue Color)");  

   m2.write (90);
   delay (30);

   m3.write (0);
   delay (30);
   m4.write (180);
   delay (30);
   m1.write (0);
   delay (600);

// Pengambilan Kotak

for (pos=0; pos<= 66; pos +=1 ){
  m3.write (pos);
  delay (12);  
}
  m3.write (45);
  delay (200);

   m2.write (50);
   delay (500);
   m2.write (54);
   delay (500);

// Pencengkraman Gripper
  m1.write (90);
  delay (2000);

// peletakan objek
  for (pos=45 ; pos>= 0; pos -=1){

  m3.write (pos);
  delay (10);
  }
 m4.write (100);
 // m4.write (120);
  delay (350);

  for (pos=0 ; pos<=40 ; pos +=1){
   m3.write (pos);
   delay (10);
    }  
    m3.write (45);
    delay (500);

    m1.write (0);
    delay (500);
  for (pos=45 ; pos>= 0; pos -=1){

  m3.write (pos);
  delay (10);
  }
  for (pos = 75; pos<= 90; pos += 1){  
  m2.write (pos);
  delay (50);
  }
  m4.write (180);
  delay (800);

    }  
  
  else if (green < red && green < blue)  
  {  
   Serial.println(" - (Green Color)");  

  m2.write (90);
  delay (30);
  m3.write (0);
  delay (30);
  m4.write (180);
  delay (30);
  m1.write (0);
  delay (600);

  for (pos=0; pos<= 66; pos += 1){
  m3.write (pos);
  delay (12);
  }
  m3.write (45);
  delay (700);

  m2.write (40);
  delay (10);
  m2.write (50);
  delay (700);

  m1.write (90);
  delay (2000);

for (pos = 45; pos>=0; pos -=1){
  m3.write (pos);
  delay (10);
}
  m3.write (0);
  delay (500);

  m4.write (60);
  delay (350);

for (pos = 0; pos <= 40; pos+=1){
  m3.write (pos);
  delay (20);
}
  m3.write (45);
  delay (500);

  m1.write (0);
  delay (500);

for (pos = 45; pos>= 0; pos-=1){
  m3.write (20);
}

for (pos = 80; pos <= 90; pos+=1 ){
  m2.write (pos);
  delay (50);
}
  m4.write (180);
  delay (800);
  }  
  
  else{
  Serial.println();  
  }
  delay(300);   
}    
    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
