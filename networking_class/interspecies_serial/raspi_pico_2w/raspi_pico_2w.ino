String content = "";

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);              // Pins: Tx GP00, assuming GP01 is Rx?
  Serial2.begin(9600, SERIAL_8N1);  // Pins: TX GP08
}

void loop() {
  Serial.println("Listening on Serial; type through Arduino IDE to send");
  
  if (Serial.available()) {
    content = Serial.readStringUntil('\n');

    Serial.print("Content read: ");
    Serial.println(content);
    Serial.println("Sending to Serial1");

    Serial1.println(content);
    content = "";
  }

  Serial2.println("oooo");
  delay(500);
}
