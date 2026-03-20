const int POT_PIN = 11;

void setup() {
  pinMode(POT_PIN, INPUT);

  Serial.begin(115200);
}

void loop() {
  int reading = analogRead(POT_PIN);

  float voltage = (reading * 3.3) / 4095.0;
  Serial.println(voltage);

  delay(20);
}
