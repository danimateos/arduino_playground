#define ELECTRODE 4

int reading = 0;

void setup() {
  pinMode(ELECTRODE, INPUT);

  Serial.begin(115200);
}

void loop() {
  reading = touchRead(ELECTRODE);

  Serial.println(reading);
  delay(10);
}
