String content = "";

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600, SERIAL_8N1, 13, 14);  // Rx=13, Tx=14
}

void loop() {
  Serial.println("Listening on Serial1; pin 13 listening");

  if (Serial1.available()) {
    content = Serial1.readStringUntil('\n');

    Serial.print("Content read from the other board: ");
    Serial.println(content);

    content = "";
  }

  delay(500);
}
