#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Reference: https://randomnerdtutorials.com/esp32-esp8266-i2c-lcd-arduino-ide/
// Except: install LiquidCrystal_I2C (by Frank de Brabander) from Library Manager 


#define ADDRESS_I2C 0x27 // Default address; can be changed by soldering A0, A1, A2 (behind controller)

LiquidCrystal_I2C lcd(ADDRESS_I2C, 16, 2);  

void setup() {
  lcd.init();
  Serial.begin(115200);
}

void loop() {

  lcd.backlight();
  lcd.setCursor(0, 0);  //Start at character 0 on line 0
  lcd.print("Let's build STUFF!");

  delay(500);
}
