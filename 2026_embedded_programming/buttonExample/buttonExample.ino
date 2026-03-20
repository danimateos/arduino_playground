int buttonPin = 0;
int ledPin = 48;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  bool isButtonPressed = !digitalRead(buttonPin);

  Serial.println(isButtonPressed);
  if (isButtonPressed) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
