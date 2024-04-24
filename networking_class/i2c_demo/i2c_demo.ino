#include <Wire.h>

int childAddress = 9;

void setup() {
  Serial.begin(115200);
  Wire.begin(17);
}

void loop() {
  Wire.requestFrom(childAddress, 1);  // 1 byte
}
