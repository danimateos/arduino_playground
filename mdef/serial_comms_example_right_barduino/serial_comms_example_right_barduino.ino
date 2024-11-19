// Barduino 2
String inputBuffer;

void setup() {
    pinMode(48, OUTPUT);

  Serial.begin(115200);
  Serial0.begin(115200);
  Serial1.begin(115200);

}

void loop() {

  // Read from hardware serial (USB, with "USB CDC on boot" enabled)
  while (Serial.available()) {
    inputBuffer = Serial.readStringUntil('\n');
    Serial.println(inputBuffer);
  }

  // If we read something, broadcast it over Serial1 to the sister board
  if (inputBuffer != "") {
    Serial1.println("I'M BARDUINITO THE LESSER");
    Serial1.println("HEAR YE MY WHINING");
    Serial1.println(inputBuffer);
    inputBuffer = "";
  }

  while (Serial0.available()) {
    inputBuffer = Serial0.readStringUntil('\n');
    Serial.println("SERIAL 0");
    Serial.println(inputBuffer);
  }

  while (Serial1.available()) {
    inputBuffer = Serial1.readStringUntil('\n');
    Serial.println("SERIAL 1");
    Serial.println(inputBuffer);
  }

  digitalWrite(48, HIGH);
  delay(200);
  digitalWrite(48, LOW);
  delay(100);
  digitalWrite(48, HIGH);
  delay(200);
  digitalWrite(48, LOW);
  delay(500);
  Serial.println(".");

}
