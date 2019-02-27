const int buzzer = 7; 


void setup(){
 
  pinMode(buzzer, OUTPUT); 

}

void loop(){
 
  tone(buzzer, 700); 
  delay(500);        
  noTone(buzzer);     
  delay(150);        
  
}
