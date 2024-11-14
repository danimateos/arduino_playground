#include <Adafruit_NeoPixel.h>

#define ONBOARD_NEOPIXEL 8
#define STRIP_LENGTH 4
#define STRIP_PIN 9

Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIP_LENGTH, STRIP_PIN, NEO_RGB);
Adafruit_NeoPixel onboard = Adafruit_NeoPixel(1, ONBOARD_NEOPIXEL, NEO_GRB);

void setup() {
  onboard.begin();
  onboard.setBrightness(30);
  onboard.show();

  strip.begin();
  strip.show();
}

void loop() {

  
  onboard.setPixelColor(0, onboard.Color(79, 47, 79));
  onboard.show();


  strip.clear();
  strip.setPixelColor(0, strip.Color(255, 0, 0));
  strip.setPixelColor(1, strip.Color(0, 255, 0));
  strip.setPixelColor(2, strip.Color(0, 0, 255));
  strip.show();
  delay(500);

  strip.clear();
  strip.setPixelColor(1, strip.Color(255, 0, 0));
  strip.setPixelColor(2, strip.Color(0, 255, 0));
  strip.setPixelColor(3, strip.Color(0, 0, 255));
  strip.show();
  delay(500);

  strip.clear();
  strip.setPixelColor(2, strip.Color(255, 0, 0));
  strip.setPixelColor(3, strip.Color(0, 255, 0));
  strip.setPixelColor(0, strip.Color(0, 0, 255));
  strip.show();
  delay(500);

  strip.clear();
  strip.setPixelColor(1, strip.Color(255, 0, 0));
  strip.setPixelColor(2, strip.Color(0, 255, 0));
  strip.setPixelColor(3, strip.Color(0, 0, 255));
  strip.show();
  delay(500);
}
