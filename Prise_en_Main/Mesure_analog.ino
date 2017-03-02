/*
 * Mesure sur ka voie analogique 0
 * Conversion en volt
 * Affichage resultat
 */
#define Pin_read_0 0
int val_lue = 0 ;
float val_volt = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  val_lue = analogRead(Pin_read_0);
  val_volt = val_lue*5.0/1023;
  Serial.print("Val num : " );
  Serial.println(val_lue );
  Serial.print("Val nvolt : " );
  Serial.println(val_volt , 4);
  delay(200);

}
