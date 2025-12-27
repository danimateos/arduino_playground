int potentiometerPin = A0;

void setup() {
  pinMode(potentiometerPin, INPUT);

  Serial.begin(115200);
}

void loop() {
  int reading = analogRead(potentiometerPin);

  Serial.println(reading);
  delay(5);
}
