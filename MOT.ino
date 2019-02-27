#include <SoftwareSerial.h>



#define In11 2
#define In12 4
#define ENA 10
#define ENB 11
#define In21 7
#define In22 8

int state = 0;
void setup()
{
  

pinMode(In11,OUTPUT);
pinMode(In12,OUTPUT);
pinMode(In21,OUTPUT);
pinMode(In22,OUTPUT);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
Serial.begin(38400);
  }

void loop()
{
   if(Serial.available() > 0)  
   {
      state = Serial.read();       
   }
      if(state == '1')
      {
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,HIGH);
  digitalWrite(In22,LOW);
  state=0;
      }
      else if(state == '2')    
      {     
 analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,LOW);
  digitalWrite(In12,HIGH);
  digitalWrite(In21,HIGH);
  digitalWrite(In22,LOW);
  state=0;
 }   
   else if(state == '3')    
      {     
 analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,LOW);
  digitalWrite(In22,HIGH);
  state=0;
 }   

  else if(state == '4')    
      {     
 analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,LOW);
  digitalWrite(In12,HIGH);
  digitalWrite(In21,LOW);
  digitalWrite(In22,HIGH);
  state=0;
 }   
  else if(state == '0')    
      {     
 analogWrite(ENA,0);
  analogWrite(ENB,0);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,HIGH);
  digitalWrite(In21,HIGH);
  digitalWrite(In22,HIGH);
  state=0;
 }   
   }

