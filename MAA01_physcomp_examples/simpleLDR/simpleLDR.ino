#define LIGHT_SENSOR_PIN A6
#define BUZZER_PIN 5

void setup() {
  Serial.begin(115200);

  pinMode(LIGHT_SENSOR_PIN, INPUT);
}

void loop() {

  int reading = analogRead(LIGHT_SENSOR_PIN);

  Serial.println(reading);

  // Buzzes when it's in darkness (reading < 100)
  if (reading < 100) {
    tone(BUZZER_PIN, 440);
  } else {
    noTone(BUZZER_PIN);
  }

  delay(20);
}
