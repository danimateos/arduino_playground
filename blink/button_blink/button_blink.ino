int start, end;
int reading_a, reading_b;
bool state;
int button;

int TEMPERATURE_SENSOR_A = 8;
int TEMPERATURE_SENSOR_B = 9;
int LED = 48;
int BUTTON = 0;

void setup() {
  Serial.begin(115200);

  pinMode(TEMPERATURE_SENSOR_A, INPUT);
  pinMode(TEMPERATURE_SENSOR_B, INPUT);
  pinMode(BUTTON, INPUT);

  pinMode(LED, OUTPUT);

  state = LOW;
  start = millis();
}

void loop() {

  reading_a = analogRead(TEMPERATURE_SENSOR_A);  // no idea how this is used.
  reading_b = analogRead(TEMPERATURE_SENSOR_B);  // no idea how this is used.
  button = digitalRead(BUTTON); // 1 is unpressed

  Serial.println(button);

  // Blink if pressed, non blocking
  if (millis() - start >= 50 && !button) {
    state = !state;
    digitalWrite(LED, state);
    start = millis();
  }

  
}
