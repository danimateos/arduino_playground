#include <Adafruit_NeoPixel.h>

#define ONBOARD_NEOPIXEL 8
#define NEOPIXEL_STRIP 9
#define STRIP_LENGTH 18

Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIP_LENGTH, NEOPIXEL_STRIP, NEO_RGB);

int step = 32767 / (3);

void setup() {
  Serial.begin(9600);

  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop() {

  for (int i = 0; i < STRIP_LENGTH; i++) {
    Serial.println(i);
    strip.clear();
    strip.setPixelColor((i + 0) % STRIP_LENGTH, strip.ColorHSV(0, 255, 128));
    strip.setPixelColor((i + 1) % STRIP_LENGTH, strip.ColorHSV(step, 255, 128));
    strip.setPixelColor((i + 2) % STRIP_LENGTH, strip.ColorHSV(2 * step, 255, 128));
    strip.setPixelColor((i + 3) % STRIP_LENGTH, strip.Color(0, 0, 0));

    strip.show();
    delay(500);
  }
}
