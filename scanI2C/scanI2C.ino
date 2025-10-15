#include <Wire.h>

void setup() {
  Wire.begin(8, 9);  // SDA, SCL
  Serial.begin(115200);
  Serial.println("toxoto");
}

void loop() {
  Serial.println("Scanning addresses");

  for (int address = 1; address <= 127; address++) {
    Wire.beginTransmission(address);
    int returnCode = Wire.endTransmission();

    if (returnCode == 0) {
      Serial.print("Device found at address 0x");
      Serial.println(address, HEX);
    } else if (returnCode == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) { Serial.print("0"); }
      Serial.println(address, HEX);
    }
  }
}
