#include <CapacitiveSensor.h>

CapacitiveSensor sensor = CapacitiveSensor(9, 10);


void setup() {
  Serial.begin(9600);
}

void loop() {
  long start = millis();

  long measure = sensor.capacitiveSensor(30);
  Serial.print("measure ");
  Serial.print(measure);
  Serial.print(", time ");

  Serial.println(millis() - start);

  delay(50);
}
