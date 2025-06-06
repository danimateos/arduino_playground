int buttonPin = 10;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);
  Serial1.begin(9600);  // Pins: Tx GP00, assuming GP01 is Rx?
}

void loop() {
  Serial.println("listening to button");

  if (digitalRead(buttonPin) == LOW) {
    Serial.println("Button pressed!");
    Serial1.print("beep");
    Serial1.print('\n');
  }


  delay(500);

}
