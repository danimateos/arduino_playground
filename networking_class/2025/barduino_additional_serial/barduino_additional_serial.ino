String content = "";

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8N1, 12, 13); // Rx 12, Tx 13

  pinMode(48, OUTPUT);
}

void loop() {
  Serial.println("hey!");

  if (Serial.available()) {
    Serial.println("I got something! ");
    content = Serial.readStringUntil('\n');
    Serial.println(content);

    Serial1.print("I got this ");
    Serial1.println(content);
  }

  if (content == "ledon") {
    digitalWrite(48, HIGH);
  } else if (content == "ledoff") {
    digitalWrite(48, LOW);
  } else if (content == "beep") {
    tone(46, 880, 200);
  }

  content = "";

  delay(500);
}
