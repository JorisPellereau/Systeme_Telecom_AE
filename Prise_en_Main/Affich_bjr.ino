#include <stdio.h>
#include <stdlib.h>


void setup() {
  
  Serial.begin(9600);     // Init Com serie à 9600 bauds
}

void loop() {
  
    Serial.println("Hello world");        // Affichage dans la console
    delay(50);
}
