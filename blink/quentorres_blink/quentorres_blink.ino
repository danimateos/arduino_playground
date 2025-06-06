int buttonState;

int LED = D0;
int BUTTON = D1;
float changeFactor = 1.2;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(115200);
}

void loop() {

  int duration = 250;
  int buttonState = digitalRead(BUTTON);

  while (duration > 10 && duration < 1000) {

    digitalWriteFast(LED, HIGH);
    delay(duration);

    digitalWriteFast(LED, LOW);
    delay(duration);

    int buttonState = digitalRead(BUTTON);

    if (buttonState) {
      duration /= changeFactor;
    } else {
      duration *= changeFactor;
    }

    Serial.print(buttonState);
    Serial.print(", ");
    Serial.println(duration);
  }
}
