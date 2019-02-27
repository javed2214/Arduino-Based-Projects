int del=100; 
void setup() {
    for (int i = 0; i<=13 ; i++) {
    pinMode(i, OUTPUT);
  } 
} 
 
void loop() {
  for (int i = 0; i<=13; i++) { 
    digitalWrite(i, HIGH);
    delay(del);
    digitalWrite(i, LOW);
  }
  for (int i = 12; i>=1; i--) { 
    digitalWrite(i, HIGH);
    delay(del);
    digitalWrite(i, LOW);
  }
}
