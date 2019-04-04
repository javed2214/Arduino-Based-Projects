#include<Arduino.h>

#define ENA 9
#define In11 2
#define In12 3

void setup(){

  pinMode(ENA, OUTPUT);
  pinMode(In11, OUTPUT);
  pinMode(In12, OUTPUT);

  Serial.begin(9600);
}

void loop(){

  analogWrite(ENA, 255);
  digitalWrite(In11, HIGH);
  digitalWrite(In12, LOW);

  delay(10000);

  analogWrite(ENA, 0);
  digitalWrite(In11, LOW);
  digitalWrite(In12, HIGH);

  delay(10000); 
}
