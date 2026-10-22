#include <Arduino.h>
#include <U8x8lib.h>

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/U8X8_PIN_NONE);

void setup(void) {
 u8x8.begin();
 u8x8.setPowerSave(0);
}

void loop(void) {
 u8x8.setFont(u8x8_font_chroma48medium8_r);
 u8x8.drawString(0, 1, "Hello World!");
 u8x8.setInverseFont(1);
 u8x8.drawString(0, 0, "012345678901234567890123456789");
 u8x8.setInverseFont(0);
 u8x8.refreshDisplay();  // only required for SSD1606/7
 delay(2000);
}
