String message;

void setup() {
  Serial.begin(115200);
  Serial0.begin(115200);
}

void loop() {
  Serial.println("hey!!!!");

  // Receive from computer
  while (Serial.available()) {
    message = Serial.readStringUntil('\n');
  }

  // Write to screen what was received from the computer
  if (message != "") {
    Serial.print("The message was: ");
    Serial.println(message);
    // Send to the other board
    Serial0.println(message);
    message = "";
  }


  delay(500);
}
