#define DELAY_MS 150
#define N_LEDS 4
// This would work exactly the same, but it would
// use a tiny little bit of extra memory:
// const int N_LEDS = 4; 

int ledPins[N_LEDS] = {3, 4, 5, 9};

void setup() {
  Serial.begin(115200);

  // A for loop would be more elegant but copy-pasting worked fine
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  
  for (int i = 0; i < N_LEDS; i++) {
    Serial.println(ledPins[i]);

    digitalWrite(ledPins[i], HIGH);
    delay(DELAY_MS);
    digitalWrite(ledPins[i], LOW);
  }

  for (int i = N_LEDS - 1; i > 0; i--) {
    Serial.println(ledPins[i]);

    digitalWrite(ledPins[i], HIGH);
    delay(DELAY_MS);
    digitalWrite(ledPins[i], LOW);
  }

  delay(25);

}
