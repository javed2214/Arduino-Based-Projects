int In11=2;
int In12=4;
int ENA=10;
int ENB=11;
int In21=7;
int In22=8;
int motorSpeed=255;
int turn=50;
void setup()
{
  
Serial.begin(9600);
pinMode(In11,OUTPUT);
pinMode(In12,OUTPUT);
pinMode(In21,OUTPUT);
pinMode(In22,OUTPUT);


  }
  void loop()
  {
    
     analogWrite(ENA,255);
  analogWrite(ENB,255);
  digitalWrite(In11,HIGH);
  digitalWrite(In12,LOW);
  digitalWrite(In21,HIGH);
  digitalWrite(In22,LOW);

    }

    
