#include "Ultrasonic.h"

//criando objeto ultrasonic e definindo as portas digitais do Trigger - 6 - e Echo - 7
Ultrasonic ultrasonic(6,7);


#define In11 2
#define In12 3
#define ENA 9
#define ENB 10
#define In21 4
#define In22 5
const int ledgreen = 13;
const int ledyellow = 12;
const int ledred = 11;

long microsec = 0;
float distanciaCM = 0;

void setup () {
Serial.begin(9600); 

pinMode(ledgreen,OUTPUT);
pinMode(ledyellow,OUTPUT); 
pinMode(ledred,OUTPUT);
pinMode(In11,OUTPUT);
pinMode(In12,OUTPUT);
pinMode(In21,OUTPUT);
pinMode(In22,OUTPUT);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
}

void loop () {
microsec = ultrasonic.timing(); //Lendo o sensor
distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM); //Convertendo a distância em CM

ledDistancia();

Serial.print(distanciaCM);
Serial.println(" cm");
//delay(1000);
}

//Método que centraliza o controle de acendimento dos leds.
void ledDistancia () {

//Apagando todos os leds
digitalWrite(ledgreen,LOW);
digitalWrite(ledyellow,LOW);
digitalWrite(ledred,LOW);

//Acendendo o led adequado para a distância lida no sensor
if (distanciaCM > 20) {
digitalWrite(ledgreen,HIGH);
analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,LOW);
  digitalWrite(In22,HIGH);
}

if (distanciaCM <=20 and distanciaCM >= 10) {
digitalWrite(ledyellow,HIGH);
analogWrite(ENA,0);
  analogWrite(ENB,0);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,HIGH);
  digitalWrite(In21,HIGH);
  digitalWrite(In22,HIGH);
  delay(1000);
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,HIGH);
  digitalWrite(In22,LOW);
  delay(2500);
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,LOW);
  digitalWrite(In22,HIGH);
}

if (distanciaCM < 10) {
digitalWrite(ledred,HIGH);
analogWrite(ENA,0);
  analogWrite(ENB,0);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,HIGH);
  digitalWrite(In21,HIGH);
  digitalWrite(In22,HIGH);
  delay(1000);
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,HIGH);
  digitalWrite(In22,LOW);
  delay(2500);
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,LOW);
  digitalWrite(In22,HIGH);
}
}
