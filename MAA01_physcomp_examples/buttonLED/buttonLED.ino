#define LED_PIN 4
#define BUTTON_PIN 6

bool buttonState;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);

  digitalWrite(LED_PIN, buttonState);
}
