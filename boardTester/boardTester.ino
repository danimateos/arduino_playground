int digitalPins = 14;
int analogPins[] = { A0, A1, A2, A3, A4, A5, A6 };
int pwmPins[] = { 3, 5, 6, 9, 10, 11 };

int blinkMillis = 250;
int blinkTimes = 4;
int totalBlinkTime = blinkMillis * 2 * blinkTimes;  // hi and lo

int fadeMillis = 1000;
int totalCycleTime = totalBlinkTime + fadeMillis * 2;  // in and out
int cycleStart = 0;

void setup() {
  for (int i = 0; i < digitalPins; i++) {
    pinMode(i, OUTPUT);
  }

  for (int i = 0; i < sizeof(analogPins) / sizeof(analogPins[0]); i++) {
    pinMode(analogPins[i], INPUT);
  }

  Serial.begin(115200);
}

void loop() {

  int now = millis();
  int elapsed = now - cycleStart;

  if (elapsed > totalCycleTime) {
    Serial.println("Restart");
    cycleStart = now;                     // Back to beginning
  } else if (elapsed > totalBlinkTime) {  // Time to fade
    Serial.println("Fade");
    int centerPoint = totalBlinkTime + fadeMillis;                  // The high point of brightness
    int fadeValue = 255 * abs(elapsed - centerPoint) / fadeMillis;  // How far from High point?
    for (int i = 0; i < sizeof(pwmPins) / sizeof(pwmPins[0]); i++) {
      analogWrite(pwmPins[i], fadeValue);
    }
  } else {  // Blinking Time
    Serial.print("Blink");
    int value = (now % (blinkMillis * 2)) > blinkMillis;
    Serial.print(" ");
    Serial.println(value);
    for (int i = 2; i < digitalPins; i++) {  // Skip 0 and 1 (RX, Tx)
      digitalWrite(i, value);
    }
  }
 
  for (int i = 0; i < sizeof(analogPins) / sizeof(analogPins[0]); i++) {
    Serial.print("Analog pin ");
    Serial.print(analogPins[i]);
    Serial.print(" reads ");
    Serial.println(analogRead(analogPins[i]));
  }

  delay(10);
}
