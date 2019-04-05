#include<Arduino.h>

#define ENA 9
#define In11 2
#define In12 3

int msensor=A1;
int msvalue=0;
int led=13;
boolean flag=false;
void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(In11, OUTPUT);
  pinMode(In12, OUTPUT);
  pinMode(msensor,INPUT);
  pinMode(led,OUTPUT);

  Serial.begin(9600);
}

void pumpON(){
    
    analogWrite(ENA, 255);
  digitalWrite(In11, HIGH); 
  digitalWrite(In12, LOW);
}

void pumpOFF(){

   analogWrite(ENA,0);
}

void loop() {
  msvalue=analogRead(msensor);
  Serial.println(msvalue);

  if(msvalue>500)
  {
      pumpON();
      digitalWrite(led,HIGH);
//      flag=true;
      delay(1000);
      
  }
       else
       {
          pumpOFF();
          digitalWrite(led,LOW);
//          flag=false;
          delay(1000);
       }
          delay(10);

}
