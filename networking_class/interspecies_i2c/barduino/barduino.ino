#include <Wire.h>

void setup() {
  Serial.begin(115200);

  Wire.begin(42);  // Slave at address 42
  Wire.onRequest(respond);
}

void loop() {
  Serial.println("waiting");
  delay(500);
}

void respond() {
  Serial.println("So happy! I received a request!");
  Wire.write('y');
  Wire.write('a');
  Wire.write('y');
}
