#include <Adafruit_NeoPixel.h>
#include <Temperature_LM75_Derived.h>

TI_TMP102 temperature;

// Inputs
const int buttonPin = 0;  // Also bootselect
const int lightSensorPin = 3;
const int topTouchPin = 4;
const int rightTouchPin = 5;
const int bottomTouchPin = 6;
const int leftTouchPin = 7;

// Outputs (Barduino 4.0.2)
const int neopixelPin = 38;
Adafruit_NeoPixel strip(1, neopixelPin, NEO_GRB + NEO_KHZ800);
const int buzzerPin = 46;
const int ledPin = 48;

// Variables will change:
int ledState = LOW;  // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousBlinkMillis = 0;  // will store last time LED was updated
unsigned long previousPrintMillis = 0;  // will store last time LED was updated

// constants won't change:
const long blinkInterval = 500;  // interval at which to blink (milliseconds)
const long printInterval = 100; 

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(lightSensorPin, OUTPUT);


  Serial.begin(115200);

  strip.begin();
  strip.setBrightness(50);  // Set BRIGHTNESS to about 1/5 (max = 255)
  strip.clear();

  Wire.begin();
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousPrintMillis >= printInterval) {
    previousPrintMillis = currentMillis;

    // printTouchState();
  }

  if (currentMillis - previousBlinkMillis >= blinkInterval) {
    // save the last time you blinked the LED
    previousBlinkMillis = currentMillis;


    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
      strip.setPixelColor(0, 50, 200, 0);
      strip.show();
      tone(buzzerPin, 400);

      Serial.print("Temp is ");
      Serial.print(temperature.readTemperatureC());
      Serial.println("C");
    } else {
      ledState = LOW;
      strip.setPixelColor(0, 200, 50, 0);
      strip.show();
      noTone(buzzerPin);

      Serial.print("Light reading is ");
      Serial.println(analogRead(lightSensorPin));
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }

  printTouchState(); 
}

void printTouchState() {
    Serial.print("T");
    Serial.print(touchRead(topTouchPin));
    Serial.print(" | R");
    Serial.print(touchRead(rightTouchPin));
    Serial.print(" | B");
    Serial.print(touchRead(bottomTouchPin));
    Serial.print(" | L");
    Serial.println(touchRead(leftTouchPin));
}