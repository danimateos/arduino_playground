int analogLedPin = 6;
int potentiometerPin = A0;

void setup() {
  pinMode(analogLedPin, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  // Control the LED brightness with the potentiometer
  // Note that max analogRead is 1023, while
  // max analogWrite is 255.

  Serial.println("Starting the loop function");

  int reading = analogRead(potentiometerPin);
  int brightness = reading / 4;

  Serial.println(reading);
  Serial.println(brightness);

  analogWrite(analogLedPin, brightness);

  delay(5);
}
