#define BUTTON_PIN 6

bool currentButtonState = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT);

  Serial.begin(115200);
}

void loop() {
  currentButtonState = digitalRead(BUTTON_PIN);

  Serial.println(currentButtonState);

  delay(25);  // This time we delay to avoid overwhelming the channel
}