int buttonPin = 0;
int relayPin = 12;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  digitalWrite(relayPin, digitalRead(buttonPin));
}
