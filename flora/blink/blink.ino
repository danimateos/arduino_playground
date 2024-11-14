#include <Adafruit_NeoPixel.h>

#define ONBOARD_NEOPIXEL 8
#define STRIP_LENGTH 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIP_LENGTH, ONBOARD_NEOPIXEL, NEO_GRB);


void setup() {
  Serial.begin(9600);

  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop() {

  strip.setPixelColor(0, strip.Color(150, 50, 0));
  strip.show();
  delay(500);

  strip.clear();
  strip.show();
  delay(500);
}
