#include <LiquidCrystal.h> // Libreria per il display LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define alarm 6            // buzzer
#define motionSensor 7     // pir_sensor
#define led 13           // LED

void setup() {
  //impostzione delle uscite dei componenti
    pinMode(alarm, OUTPUT); 
    pinMode(motionSensor, INPUT);
    pinMode(led, OUTPUT);

    lcd.begin(16, 2);
    lcd.print("Sistema Pronto");
    delay(2000);
    lcd.clear();
}

void loop() {
    if (digitalRead(motionSensor) == HIGH) {
        digitalWrite(alarm, LOW);
        digitalWrite(led, HIGH);
         lcd.clear();                       // Pulisce lo schermo
        lcd.print("Movimento rilevato");
        delay(100);
        digitalWrite(alarm, HIGH);
        digitalWrite(led, LOW);
        delay(100);
    } else {
      //componenti in riposo
        digitalWrite(alarm, LOW);
        digitalWrite(led, LOW);
        lcd.print("sistema disattivato");
    }
}