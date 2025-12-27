int ledPin = 4;

void setup() {
  pinMode(ledPin, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  // Write out a program that blinks "SOS" in Morse Code
  // Three short blinks, three long blinks, three short

  Serial.println("Hey there baby I'm gonna looooop");

  Serial.println("S");
  for (int i = 0; i < 3; i++) {
    Serial.println(i);

    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }

  Serial.println("O");
  for (int i = 0; i < 3; i++) {
    Serial.println(i);

    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(500);
  }

  Serial.println("S");
  for (int i = 0; i < 3; i++) {
    Serial.println(i);

    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }

  delay(2000);
}
