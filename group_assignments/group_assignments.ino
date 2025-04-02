// board_02
int LED = 0;
int BUTTON = 1;
int start;
bool state;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(115200);

  start = millis();
  state = false;
}

void loop() {
  int now = millis();

  if (now - start > 100) {
    int pressed = digitalRead(BUTTON);
    Serial.println(pressed);
    Serial.println(state);
    if (pressed) {
      digitalWrite(LED, state);
    }

    start = now;
    state = !state;
  }
}
