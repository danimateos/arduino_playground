#define N_NOTES 7
#define DURATION 150
#define BUZZER 5

// Exercise: adapt this code so that it plays another simple melody
// Twist: if you feel adventurous, include note durations ("values")
// https://en.wikipedia.org/wiki/Note_value

int melody[N_NOTES] = { 330, 330, 330, 262, 330, 392, 196 };  // frequencies in hertz

void setup() {
  Serial.begin(115200);
}

void loop() {
  for (int i = 0; i < N_NOTES; i++) {
    Serial.println("inside the loop");
    tone(BUZZER, melody[i], DURATION);
    Serial.println(i);
    Serial.println(melody[i]);
    delay(DURATION + 25);
  }

  Serial.println("outside of the loop");
  delay(500);
}