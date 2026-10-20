#define N_NOTES 7

#define BUZZER 5

// Exercise: adapt this code so that it plays another simple melody
// Twist: if you feel adventurous, include note durations ("values")
// https://en.wikipedia.org/wiki/Note_value

int melody[N_NOTES] = { 330, 330, 330, 262, 330, 392, 196 };  // frequencies in hertz
int durations[N_NOTES] = { 150, 300, 300, 150, 300, 600, 300 };

void setup() {
  Serial.begin(115200);
}

void loop() {
  for (int i = 0; i < N_NOTES; i++) {
    Serial.println("inside the loop");
    tone(BUZZER, melody[i], durations[i]);
    Serial.println(i);
    Serial.println(melody[i]);
    delay(durations[i] + 25);
  }

  Serial.println("outside of the loop");
  delay(500);
}