/*
 * GESTION SPI 24 bit
 * 
 */
#include <SPI.h>

#define SCK 13
#define MOSI 11
#define MISO 12
#define SS 9
#define IN_MUXOUT 7

// Config SPI
#define freqH 200000
#define ordre LSBFIRST
#define mode SPI_MODE0
//------------------

void setup() {
  pinMode(SS , OUTPUT);
  pinMode(entree , INPUT);
  digitalWrite(SS , HIGH);                                   // Mide à l'état bas
  SPI.beginTransaction(SPISettings(freqH , ordre , mode));   // Configuration de la com
}

void loop() {
    delay(1);
    envoi_datas();
}

void envoi_datas() {
    SPI.begin();
    char data_out[3] = {0xAA , 0xAB , 0xAC} , i;
    
    for(i = 0 ; i < 3 ; i++) {    
        digitalWrite(SS , LOW); 
        SPI.transfer(data_out[i]);     // Envoi datas
        digitalWrite(SS , HIGH); 
    }
}




