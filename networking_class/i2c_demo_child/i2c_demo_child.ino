#include <Wire.h>

int childAddress = 17;
int buzzer = 14;
int led = 48;
int freq = 440;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(115200);
  Wire.begin(childAddress);
  Wire.onRequest(buzz);
  Wire.onReceive(receiveEvent);
}

void loop() {
  delay(100);
  noTone(buzzer);
}

void requestEvent() {
  Wire.write('G');
  Wire.write('O');
  Wire.write('A');
  Wire.write('T');
}

void buzz() {
  Serial.println("Got request");
  freq = 400;

  for (int i = 0; i < 20; i++) {
    tone(buzzer, freq);
    freq *= 1.05946;
    delay(10);
  }
}

void receiveEvent(int bytes) {
}