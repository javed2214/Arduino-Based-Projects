#include<SoftwareSerial.h>
#include<Servo.h>
#include<Arduino.h>

#define ENA 9
#define ENB 10
#define In11 2
#define In12 3
#define In21 4
#define In22 5
int servoPin = 7;
Servo servo;  
int angle = 0;
static int lev=0;

int state=-1;
#define Led 11

void setup() {
  // put your setup code here, to run once:

  servo.attach(servoPin); 
  servo.write(0);
  
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(In11,OUTPUT);
  pinMode(In12,OUTPUT);
  pinMode(In21,OUTPUT);
  pinMode(In22,OUTPUT);
  pinMode(Led,OUTPUT);
  
  Serial.begin(9600);
}

void forwardMotion(){
  
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,LOW);
  digitalWrite(In22,HIGH);
}

void backwardMotion(){
  
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,LOW);
  digitalWrite(In12,HIGH);
  digitalWrite(In21,HIGH);
  digitalWrite(In22,LOW);
}

void Left(){
  
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,LOW);
  digitalWrite(In12,HIGH);
  digitalWrite(In21,LOW);
  digitalWrite(In22,HIGH);
}

void Right(){
  
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,HIGH);
  digitalWrite(In22,LOW);
}

void Stop(){
  
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  digitalWrite(In11,LOW);
  digitalWrite(In12,LOW);
  digitalWrite(In21,LOW);
  digitalWrite(In22,LOW);
}

void loop() {
//   put your main code here, to run repeatedly:

  if(Serial.available()>0){
    state=Serial.read();
  }
  if(state=='1'){
    forwardMotion();
  }
  else if(state=='2'){
    backwardMotion();
  }
  else if(state=='4'){
    Left();
  }
  else if(state=='3'){
    Right();
  }
  else if(state=='5'){
    Stop();
  }
  else if(state=='6'){
    lev++;
    if(lev%2!=0){
            
            for(angle = 0; angle <= 130; angle++)  
          {                                  
              servo.write(angle);               
              delay(5);                   
          }  
      }
      else{
                for(angle = 130; angle >=0; angle--)  
          {                                  
              servo.write(angle);               
              delay(5);                   
          }  
        }
          
        if(lev%2!=0) servo.write(130);               
        else servo.write(0);
        state='5';
   }
}
