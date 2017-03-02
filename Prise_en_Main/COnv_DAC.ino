/*
 * Convertisseur numerique analogique + R2R
 */
 #define b0 0
 #define b1 1
 #define b2 2
 char i = 0;
 void setup() {
  DDRD = 0x07;
}

void loop() {
  for(i = 0 ; i <= 7 ; i++) {
    PORTD = i;
    delay(10);
  }
  for(i = 7 ; i >= 0 ; i--) {
    PORTD = i;
    delay(10);
  }

}
