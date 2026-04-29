// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 18

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 8  // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 200  // Time (in milliseconds) to pause between pixels

void setup() {

  strip.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  strip.clear();  // Set all pixel colors to 'off'


  for (int i = 0; i < 5 * NUMPIXELS; i++) {

    strip.clear();
    strip.setPixelColor((i + 0) % NUMPIXELS, strip.Color(0, 150, 0));
    strip.setPixelColor((i + 1) % NUMPIXELS, strip.Color(150, 150, 0));
    strip.setPixelColor((i + 2) % NUMPIXELS, strip.Color(150, 0, 0));
  
    strip.show();     // Send the updated pixel colors to the hardware.
    delay(DELAYVAL);  // Pause before next pass through loop
  }




  strip.clear();

  strip.show();

  delay(DELAYVAL);  // Pause before next pass through loop
}
