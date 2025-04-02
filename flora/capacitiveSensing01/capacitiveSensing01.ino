#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel onboard = Adafruit_NeoPixel(1, 8, NEO_GRB);
CapacitiveSensor sensor = CapacitiveSensor(9, 10);


void setup() {
  Serial.begin(9600);

  onboard.begin();
  onboard.show();
}

void loop() {
  long start = millis();

  long measure = sensor.capacitiveSensor(10);


  long brightness = min(measure, 40000) / 400; // Hand calibrated for a 10 MΩ resistor and a fork I had lying around.
  onboard.setPixelColor(0, 255 * brightness / 100, 0, 0);
  onboard.show();

  Serial.print("measure:");
  Serial.print(measure);
  Serial.print(",brightness:");
  Serial.print(brightness);
  Serial.print(",time:");
  Serial.println(millis() - start);

  int toDelay = 50 - (start - millis());
  delay(max(toDelay, 0));
}
