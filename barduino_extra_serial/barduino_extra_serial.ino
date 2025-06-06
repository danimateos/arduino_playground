void setup() {
  Serial.begin(115200);                       // Would use Rx/Tx labelled pins on the Barduino if we don't select "USB CDC on Boot Enabled"
  Serial1.begin(9600, SERIAL_8N1, 12, 13);    // Rx = 12, Tx = 13
  Serial2.begin(115200, SERIAL_8N1, 14, 15);  // Rx = 14, Tx = 15
}

void loop() {
  Serial.println("200");
  Serial1.println("Let's see the message with an oscilloscope or logic analyzer");
  Serial2.println("And how sending a message with a different length, or at a different speed, changes the signals");

  delay(300);
}
