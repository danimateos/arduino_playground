void setup() {
  pinMode(48, OUTPUT);
}

void loop() {
  // Exercise: turn on the programmable LED on Barduino (pin 48)
  // On for the "S"s and off for the "O"s
  digitalWrite(48, HIGH);
  // SOS in Morse code is 3 long beeps - 3 short beeps - 3 long beeps
  tone(46, 440, 600);  // Long beep - 3 units
  delay(800);          // Wait
  tone(46, 440, 600);  // Long beep - 3 units
  delay(800);          // Wait
  tone(46, 440, 600);  // Long beep - 3 units
  delay(800);          // Wait
  digitalWrite(48, LOW);

  tone(46, 440, 200);  // Short beep - 1 units
  delay(400);          // Wait
  tone(46, 440, 200);  // Short beep - 1 units
  delay(400);          // Wait
  tone(46, 440, 200);  // Short beep - 1 units
  delay(400);          // Wait

  digitalWrite(48, HIGH);
  tone(46, 440, 600);  // Long beep - 3 units
  delay(800);          // Wait
  tone(46, 440, 600);  // Long beep - 3 units
  delay(800);          // Wait
  tone(46, 440, 600);  // Long beep - 3 units
  delay(800);          // Wait

}
