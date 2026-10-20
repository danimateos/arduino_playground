#define POT_PIN A0

void setup() {
  Serial.begin(115200);

  pinMode(POT_PIN, INPUT);
}

void loop() {
  int reading = analogRead(POT_PIN);
  int volume = map(reading, 0, 1023, 0, 100);
  int constrainedVolume = constrain(volume, 0, 30);

  Serial.println(reading);
  Serial.println(volume);
  Serial.println(constrainedVolume);

  delay(100);
}
