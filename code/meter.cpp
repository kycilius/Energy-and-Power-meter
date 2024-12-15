#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
float voltageInput = 0.0;
float voltageReading = 0.0;
float currentReading = 0.0;
float RA = 15000.0;
float RB = 1500.0;
float energy = 0.0;
float power = 0.0;
unsigned long prevTime = 0;
         
void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
}

void loop ()
{
  unsigned long currentTime = millis();
  float deltaTime = (currentTime - prevTime) / 1000.0;
    voltageInput = (analogRead(A0)*5.0)/1023.0;
  voltageReading = voltageInput/(RB/(RA + RB));
  currentReading = 1000*(voltageReading/(RA+RB));
  power = voltageReading*currentReading ;
   energy += power * deltaTime;
   prevTime = currentTime;
  
  lcd.setCursor(0,0);
  lcd.print("power");
  lcd.setCursor(6, 0);
  lcd.print(power);
  lcd.setCursor(12, 0);
  lcd.print("Watt");
  
  lcd.setCursor(0,1);
  lcd.print("energy");
  lcd.setCursor(8, 1);
  lcd.print(energy);
  lcd.setCursor(14, 1);
  lcd.print("J");
  delay(1000);
  

}
