#include <Adafruit_NeoPixel.h>

#define ONBOARD_NEOPIXEL 8  // Flora
int buttonPin = 9;

Adafruit_NeoPixel onboard = Adafruit_NeoPixel(1, ONBOARD_NEOPIXEL, NEO_GRB);

void setup() {
  onboard.begin();
  onboard.setBrightness(30);
  onboard.show();

  pinMode(buttonPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  int buttonPressed = digitalRead(buttonPin);
  Serial.println(buttonPressed);

  // onboard NeoPixel must be blue by default, change to red when button pressed

  onboard.setPixelColor(0, onboard.Color(255 * buttonPressed, 0, 255 * (1 - buttonPressed)));
  onboard.show();

  delay(10);
}
