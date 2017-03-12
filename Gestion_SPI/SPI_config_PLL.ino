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
#define ordre MSBFIRST
#define mode SPI_MODE0
//------------------

void setup() {
  pinMode(SS , OUTPUT);
  pinMode(IN_MUXOUT , INPUT);
  digitalWrite(SS , HIGH);                                   // Mide à l'état bas
  SPI.beginTransaction(SPISettings(freqH , ordre , mode));   // Configuration de la com
  Serial.begin(9600);     // Init Com serie à 9600 bauds
}

//== BOUCLE PRINCIPAL ==
void loop() {
    char data_ctrl_reg[3] = {0x0F , 0xF1 , 0x20};
    char data_N_reg[3] = {0x04 , 0xA2 , 0x62};
    char data_R_reg[3] = {0x00 , 0x00 , 0xC9};
    
    envoi_datas(data_R_reg);
    delay(10); 
    envoi_datas(data_ctrl_reg);
    delay(10); 
    envoi_datas(data_N_reg);
    delay(10); 
    
    while(1);
    
}
//======================
void ctrl_latch_config(){
    char tab[3] = {0 ,0 ,0};
    long ctrl_latch = 0;
    long presv_powd = 0x0 , current_set = 0x3F , outpw_lvl = 0x3 , DB11_8 = 0x1 , muxout_ctrl = 0x1;
    long DB4_DB0 = 0;
    ctrl_latch = ctrl_latch | (presv_powd << 20);
    ctrl_latch = ctrl_latch | (current_set << 14);
    ctrl_latch = ctrl_latch | (outpw_lvl << 12);
    ctrl_latch = ctrl_latch | (DB11_8 << 8);
    ctrl_latch = ctrl_latch | (muxout_ctrl << 5);
    ctrl_latch = ctrl_latch | (DB4_DB0);
    
    Serial.print("ctrl_latch = ");
    Serial.println(ctrl_latch , BIN);        // Affichage dans la console
    tab[0] = (ctrl_latch & 0xFF0000) >> 16;
    Serial.print("paquet 1 : ");
    Serial.println(tab[0] , BIN);        // Affichage dans la console
    
    tab[1] = (ctrl_latch & 0x00FF00) >> 8;
    Serial.print("paquet 2 : ");
    Serial.println(tab[1] , BIN);        // Affichage dans la console
    
    tab[2] = (ctrl_latch & 0x0000FF);
    Serial.print("paquet 3 : ");
    Serial.println(tab[2] , BIN);        // Affichage dans la console
    
    
}

void N_cntr_latch_config() {
  char tab[3] = {0 ,0 ,0};
  long N_cntr_latch = 0;
  long divide_by_slct = 0 , divide_by_2 = 0 , cp_gain = 0, cntr_B = 0x4A2;
  long cntr_A = 0x18 , ctrl_bits = 0x02;
  N_cntr_latch = N_cntr_latch | (divide_by_slct << 23);
  N_cntr_latch = N_cntr_latch | (divide_by_2 << 22);
  N_cntr_latch = N_cntr_latch | (cp_gain << 21);
  N_cntr_latch = N_cntr_latch | (cntr_B << 8);
  N_cntr_latch = N_cntr_latch | (cntr_A << 2);
  N_cntr_latch = N_cntr_latch | (ctrl_bits);
  
  Serial.print("N_cntr_latch = ");
  Serial.println(N_cntr_latch , BIN);        // Affichage dans la console

    Serial.print("ctrl_latch = ");
    Serial.println( N_cntr_latch , BIN);        // Affichage dans la console
    tab[0] = ( N_cntr_latch & 0xFF0000) >> 16;
    Serial.print("paquet 1 : ");
    Serial.println(tab[0] , BIN);        // Affichage dans la console
    
    tab[1] = ( N_cntr_latch & 0x00FF00) >> 8;
    Serial.print("paquet 2 : ");
    Serial.println(tab[1] , BIN);        // Affichage dans la console
    
    tab[2] = ( N_cntr_latch & 0x0000FF);
    Serial.print("paquet 3 : ");
    Serial.println(tab[2] , BIN);        // Affichage dans la console

  
}

void R_cntr_latch_config() {
  long R_cntr_latch = 0;
  long band_slct_clk = 0 , test_mod_bit = 0 , lock_detect = 0 , anti_backlash = 0;
  long ref_cntr = 0x32 , ctrl_bits = 1;
  
  R_cntr_latch = R_cntr_latch | (band_slct_clk << 20);
  R_cntr_latch = R_cntr_latch | (test_mod_bit << 19);
  R_cntr_latch = R_cntr_latch | (lock_detect << 18);
  R_cntr_latch = R_cntr_latch | (anti_backlash << 16);
  R_cntr_latch = R_cntr_latch | (ref_cntr << 2);
  R_cntr_latch = R_cntr_latch | (ctrl_bits);
  
  Serial.print("R_cntr_latch = ");
  Serial.println(R_cntr_latch , BIN);        // Affichage dans la console
}


void envoi_datas(char *data_out) {
    SPI.begin();
    char i;
    digitalWrite(SS , LOW);
    for(i = 0 ; i < 3 ; i++) {             
        SPI.transfer(data_out[i]);     // Envoi datas  
        delay(10);      
    }
    digitalWrite(SS , HIGH);
}




