int soundSensorPin = 18;
int samples = 0;
int nSamplesForSmoothing = 25;
int msBetweenSamples = 2;
int reading = 0;

void setup() {
  pinMode(soundSensorPin, INPUT);

  Serial.begin(115200);
}

void loop() {
  if (samples < nSamplesForSmoothing) {
    reading += analogRead(soundSensorPin);
    samples += 1;
  } else {
    Serial.println(reading / samples);
    samples = 0;
    reading = 0;
  }

  delay(msBetweenSamples);
}
