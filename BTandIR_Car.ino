#include <SoftwareSerial.h>
#include "Ultrasonic.h"
Ultrasonic ultrasonic(6,7);

#define In11 2
#define In12 3
#define ENA 9
#define ENB 10
#define In21 4
#define In22 5
#define ledgreen 13
#define ledyellow 12
#define ledred 11
long microsec = 0;
float distanciaCM = 0;
int state = 0;

void setup()
{
  
pinMode(ledgreen,OUTPUT);
pinMode(ledyellow,OUTPUT); 
pinMode(ledred,OUTPUT);
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
microsec = ultrasonic.timing(); //Lendo o sensor
distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM); //Convertendo a distância em CM

ledDistancia();

Serial.print(distanciaCM);
Serial.println(" cm");
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
void ledDistancia () {

//Apagando todos os leds
digitalWrite(ledgreen,LOW);
digitalWrite(ledyellow,LOW);
digitalWrite(ledred,LOW);

//Acendendo o led adequado para a distância lida no sensor
if (distanciaCM > 20) {
digitalWrite(ledgreen,HIGH);
}

if (distanciaCM <=20 and distanciaCM >= 10) {
digitalWrite(ledyellow,HIGH);
}

if (distanciaCM < 10) {
digitalWrite(ledred,HIGH);
analogWrite(ENA,0);
  analogWrite(ENB,0);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,HIGH);
  digitalWrite(In21,HIGH);
  digitalWrite(In22,HIGH);
  state=0;
}
}
