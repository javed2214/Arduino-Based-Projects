#include<SoftwareSerial.h>
#include<Servo.h>
#include<Arduino.h>

#define ENA 9
#define ENB 10
#define In11 2
#define In12 3
#define In21 4
#define In22 5
int servoPin1 = 7;
int servoPin2 = 8;
Servo servo1, servo2;

int angle1 = 0, angle2 = 0;
static int lev=0;

int srg1=0,srg2=0;

int state=-1;

void setup() {

  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo1.write(0);
  servo2.write(130);
  
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(In11,OUTPUT);
  pinMode(In12,OUTPUT);
  pinMode(In21,OUTPUT);
  pinMode(In22,OUTPUT);

  
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
  else if(state=='6'){    // Servo 1 Grab

    srg1+=5;
    servo1.write(srg1);
  }
  else if(state=='7'){  // Servo 1 Free

    srg1-=5;
    servo1.write(srg1);
  }
  else if(state==-'8'){  // Servo 2 Grab

    srg2+=5;
    servo2.write(srg2);
  }
  else if(state=='9'){   // Servo 2 Free

    srg2-=5;
    servo2.write(srg2);
  }
    
      // lev++;
      // if(lev%2!=0){
              
      //         for(angle1 = 0, angle2 = 130; angle1 <= 130, angle2 >=0; angle1++, angl2--)  
      //         {                                  
      //           servo1.write(angle1);
      //           servo2.write(angle2);               
      //           delay(5);                   
      //         } 
      //     }
      //     else{
      //             for(angle1 = 130, angle2 = 0; angle1 >=0, angle2 >=130; angle--, angle2--)  
      //             {                                  
      //               servo1.write(angle1);
      //               servo2.write(angle2);               
      //               delay(5);                   
      //             }  
      //         }
            
      //     if(lev%2!=0) servo1.write(130), servo2.write(0);               
      //     else servo1.write(0), servo2.write(130);
      //     state='5';
     }
