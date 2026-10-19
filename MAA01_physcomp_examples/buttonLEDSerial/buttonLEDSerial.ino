#define BUTTON 6
#define LED 4

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(115200);  // baud rate
}

void loop() {
  bool buttonState = digitalRead(BUTTON);

  if (buttonState == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  Serial.println(buttonState);
  delay(10);
}
