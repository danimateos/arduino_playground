#include <Wire.h>

String content = "";

void setup() {
  Serial.begin(115200);

  Wire.begin();  // master
}

void loop() {
  Serial.println("waiting");

  if (Serial.available()) {
    content = Serial.readStringUntil('\n');
    Serial.print("read: ");
    Serial.println(content);

    content = "";
    Wire.requestFrom(42, 3);

    while (Wire.available()) {
      content = Wire.readString();
      Serial.println(content);
    }
  }

  delay(500);
}
