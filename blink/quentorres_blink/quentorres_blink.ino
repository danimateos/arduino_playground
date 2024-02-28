int buttonState;

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, INPUT);
  Serial.begin(115200);
}

void loop() {

  int duration = 300;
  int buttonState = digitalRead(D1);

  while (duration > 10 && duration < 1000) {

    digitalWriteFast(D0, HIGH);
    delay(duration);

    digitalWriteFast(D0, LOW);
    delay(duration);

    int buttonState = digitalRead(D1);

    if (buttonState) {
      duration /= 1.1;
    } else {
      duration *= 1.1;
    }

    Serial.print(buttonState);
    Serial.print(", ");
    Serial.println(duration);
  }
}
