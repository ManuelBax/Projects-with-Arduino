#include <LiquidCrystal.h> // LCD display library

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define alarm 6            // buzzer
#define motionSensor 7     // pir_sensor
#define led 13             // LED

void setup() {
  //Setting Component Outputs
  pinMode(alarm, OUTPUT); 
  pinMode(motionSensor, INPUT);
  pinMode(led, OUTPUT);

  lcd.begin(16, 2);
  lcd.setCursor(1, 0);   
  lcd.print("Sistema");
  lcd.setCursor(0, 1); 
  lcd.print("Attivato"); 
  delay(2000);
  lcd.clear();
}

void loop() {
  if (digitalRead(motionSensor) == HIGH) {
    digitalWrite(alarm, LOW);
    digitalWrite(led, HIGH);
    lcd.clear();            //Screen cleaning the screen    
    lcd.setCursor(1, 0);               
    lcd.print("Movimento");
    lcd.setCursor(0, 1);
    lcd.print("Rilevato"); 
    delay(100);
    digitalWrite(alarm, HIGH);
    digitalWrite(led, LOW);
    delay(100);
  } else {
    // Componenti in riposo
    digitalWrite(alarm, LOW);
    digitalWrite(led, LOW);
    lcd.setCursor(1, 0);   
    lcd.print("Nessun   ");// added spaces for the correct reading of the message
    lcd.setCursor(0, 1); 
    lcd.print("Rilevamento");
  }
}