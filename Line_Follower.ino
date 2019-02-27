#define In11 2
#define In12 3
#define ENA 9
#define ENB 10
#define In21 4
#define In22 5

void setup() {
  // put your setup code here, to run once:
pinMode(In11,OUTPUT);
pinMode(In12,OUTPUT);
pinMode(In21,OUTPUT);
pinMode(In22,OUTPUT);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int lsensor=digitalRead(6);
int rsensor=digitalRead(7);
if((lsensor==LOW)&&(rsensor==LOW))
{
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,LOW);
  digitalWrite(In22,HIGH);
  }
 else if((lsensor==HIGH)&&(rsensor==LOW))
 {
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,LOW);
  digitalWrite(In12,HIGH);
  digitalWrite(In21,LOW);
  digitalWrite(In22,HIGH);
  }
  else if((lsensor==LOW)&&(rsensor==HIGH))
  {
  analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,HIGH);
  digitalWrite(In22,LOW);
    }
  else if((lsensor==HIGH)&&(rsensor==HIGH))
  {
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  digitalWrite(In11,LOW);
  digitalWrite(In12,LOW);
  digitalWrite(In21,LOW);
  digitalWrite(In22,LOW
  );
    }
}
