char val;
int ledPin = 48;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println(val);
  delay(500);
  Serial.println("Starting");

}

void loop() {

  while (Serial.available()) {
    val = Serial.read();
  }

  if (val == 'H') {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(50);
}
