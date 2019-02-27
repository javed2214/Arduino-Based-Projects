#include <SoftwareSerial.h>

#define ledb1 6
#define ledb2 7
#define ledl1 12
#define ledl2 13
#define ledr1 8
#define ledr2 11
#define In11 2
#define In12 3
#define ENA 9
#define ENB 10
#define In21 4
#define In22 5

int state = 0;
int i;
int p=0;
void setup()
{
pinMode(ledb1,OUTPUT);
pinMode(ledb2,OUTPUT);
pinMode(ledl1,OUTPUT);
pinMode(ledl2,OUTPUT);
pinMode(ledr1,OUTPUT);
pinMode(ledr2,OUTPUT);
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
  digitalWrite(ledl1, HIGH);   
  digitalWrite(ledl2, HIGH); 
   digitalWrite(ledr1, LOW);   
  digitalWrite(ledr2, LOW);   
   digitalWrite(ledb1,LOW);   
  digitalWrite(ledb2, LOW);         
  
  
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
    digitalWrite(ledb1, HIGH);   
  digitalWrite(ledb2, HIGH);  
   digitalWrite(ledr1,LOW);   
  digitalWrite(ledr2, LOW);  
   digitalWrite(ledl1, LOW);   
  digitalWrite(ledl2, LOW);
 
 
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
  digitalWrite(ledr1, HIGH);   
  digitalWrite(ledr2, HIGH);  
   digitalWrite(ledl1, HIGH);   
  digitalWrite(ledl2, HIGH);  
   digitalWrite(ledb1,LOW);   
  digitalWrite(ledb2, LOW);  
   
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
   digitalWrite(ledr1, HIGH);   
  digitalWrite(ledr2, HIGH);  
   digitalWrite(ledl1, LOW);   
  digitalWrite(ledl2, LOW);  
   digitalWrite(ledb1,LOW);   
  digitalWrite(ledb2, LOW);  
   
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
  digitalWrite(ledr1,LOW);   
  digitalWrite(ledr2, LOW);  
   digitalWrite(ledl1, LOW);   
  digitalWrite(ledl2, LOW); 
   digitalWrite(ledb1,LOW);   
  digitalWrite(ledb2, LOW);  
  state=0;
 }   
}

