#define buttonPin 9

void setup() {
  pinMode(buttonPin, INPUT);

  Serial.begin(115200);
}

void loop() {

  int value = digitalRead(buttonPin);

  if (value == HIGH) {
    Serial.println("The button is pressed");
  } else {
    Serial.println("The button is unpressed");
  }

  delay(50);
}
