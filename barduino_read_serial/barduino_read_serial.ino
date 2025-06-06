void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("waiting");

  while (Serial.available()) {
    Serial.print("I read a ");
    Serial.println(Serial.read());
  }

  delay(500);
}
