// On off sur ka pin n°2
#define Pin_2 2

void setup() {
  
  /*pinMode(Pin_2 , OUTPUT);
  digitalWrite(Pin_2 , LOW);*/
  //Avec les PORTs PIn2 => sur PORT D
  DDRD = DDRD | 0x04;
}

void loop() {
  
  /*digitalWrite(Pin_2 , HIGH);
  //delay(500);
  digitalWrite(Pin_2 , LOW);
  //delay(500);*/
  
  
  PORTD = PORTD | 0x04;
  //delay(250);
  PORTD = PORTD & 0xFB; // Observation : Pas même temps en haut qu'en bas !!!! => execution instruction plus long
  //delay(250);
  
}
