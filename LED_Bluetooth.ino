#include <SoftwareSerial.h>

#define ledPin 7
int state=0;


void setup()
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(38400);
  
  }

void loop()
{
  if(Serial.available()>0)
  {
    state=Serial.read();
    }
  
if(state=='0')
{
  digitalWrite(ledPin, LOW);
  Serial.println("LED: OFF");
  state=0;
  }
else if(state=='1')
{
  digitalWrite(ledPin,HIGH);
  Serial.println("LED: ON");
  state=0;
  }
  else if(state=='2')
{
  
  digitalWrite(ledPin,HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  delay(300);
  digitalWrite(ledPin,HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  delay(300);
  digitalWrite(ledPin,HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  delay(300);
  digitalWrite(ledPin,HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  delay(300);
  digitalWrite(ledPin,HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  delay(300);
  Serial.println("LED: BLINK");
  
  state=0;
  }
}
