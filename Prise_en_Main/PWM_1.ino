/*PWM
 * Generation d'un signal triangulaire => Filtre RC à ajouter
 */

#define pin_pwm_1 3
#define Pin_read_0 0
int val_lue = 0 ,i;

void setup() {
  pinMode(pin_pwm_1 , OUTPUT);
  Serial.begin(9600);
}

void loop() {
/*
    // Test lecture analogique => PWM
    val_lue = analogRead(Pin_read_0);
    //val_lue = val_lue*255/1023;
    analogWrite(pin_pwm_1 , val_lue / 4);   // genere le PWM
    //Serial.println(val_lue);
  */
    
    triangle_pwm();
    
    
}

void sinusoide_pwm() {
  int sin_duty = 0;

  for(i = 0 ; i <= 500 ; i++) {
    sin_duty = sin(i*3.14/2);
     analogWrite(pin_pwm_1 , sin_duty);
     delay(1);
  }
  for(i = 500 ; i <= 0 ; i--) {
    sin_duty = sin(i*3.14/2);
      analogWrite(pin_pwm_1 , sin_duty);
      delay(1);
  }
 }
 
void triangle_pwm() {
  for(i = 0 ; i <= 255 ; i++) { 
      analogWrite(pin_pwm_1 , i);
      delay(1);
    }
    
    for(i = 255 ; i >= 0 ; i--) { 
      analogWrite(pin_pwm_1 , i);
      delay(1);
    }
}

