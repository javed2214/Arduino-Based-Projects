#include <SoftwareSerial.h>
#include "Ultrasonic.h"
Ultrasonic ultrasonic(6,7);

#define ENA 9
#define ENB 10
#define In11 2
#define In12 3
#define In21 4
#define In22 5

long microsec = 0;
float distanciaCM = 0;
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
microsec = ultrasonic.timing(); //Lendo o sensor
distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM);

ledDistancia();

Serial.print(distanciaCM);
Serial.println("cm");
 analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,LOW);
  digitalWrite(In22,HIGH);

  
   }
void ledDistancia () {


if (distanciaCM > 20) {
analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,LOW);
  digitalWrite(In22,HIGH);
}



if (distanciaCM < 10) {

analogWrite(ENA,0);
  analogWrite(ENB,0);
  digitalWrite(In11,LOW);
  digitalWrite(In12,LOW);
  digitalWrite(In21,LOW);
  digitalWrite(In22,LOW);
  delay(300);
   analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,HIGH);
  digitalWrite(In22,LOW);
  delay(300)
}
}
