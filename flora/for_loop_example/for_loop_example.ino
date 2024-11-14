#include <Adafruit_NeoPixel.h>

#define ONBOARD_NEOPIXEL 8
#define NEOPIXEL_STRIP 9
#define STRIP_LENGTH 11

Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIP_LENGTH, NEOPIXEL_STRIP, NEO_RGB);

int step = 32767 / (STRIP_LENGTH - 1);

void setup() {
  Serial.begin(9600);

  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop() {

  for (int i = 0; i < STRIP_LENGTH; i++) {
    strip.clear();
    strip.setPixelColor(i , strip.Color(255, 0, 0));
    Serial.print("lighting pixel #");
    Serial.println(i);

    strip.show();
    delay(500);
  }
}
