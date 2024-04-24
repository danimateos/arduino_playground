#include <Wire.h>

int childAddress = 17;

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
  char response = Wire.requestFrom(childAddress, 1);  // 1 byte

  Serial.write(response);

  Wire.beginTransmission(childAddress);
  Wire.write("hey there kid");
  Wire.endTransmission();
}
