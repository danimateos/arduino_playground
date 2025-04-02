#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */
#define FEED_PIN 10
#define SENSOR_PIN_A 9


CapacitiveSensor sensorA = CapacitiveSensor(FEED_PIN, SENSOR_PIN_A);  // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired


void setup() {
  //  sensorA.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(115200);
}

void loop() {
  long start = millis();
  long total1 = sensorA.capacitiveSensor(30);
  // long total2 =  sensorB.capacitiveSensor(30);

  Serial.print(millis() - start);  // check on performance in milliseconds
  Serial.print("\t");              // tab character for debug windown spacing

  Serial.print(total1);  // print sensor output 1
  //Serial.print("\t");
  //Serial.print(total2);  // print sensor output 2

  Serial.println("");

  delay(10);  // arbitrary delay to limit data to serial port
}
