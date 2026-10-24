#define LIGHT_PIN A6
#define SOUND_PIN A2
#define WINDOW_SIZE 20

int rawSound = 0;
int rawSoundSamples[WINDOW_SIZE] = { 0 };
long soundSmoothed = 0;

int rawLight = 0;
int rawLightSamples[WINDOW_SIZE] = { 0 };
long lightSmoothed = 0;


long nSamples = 0;

void setup() {
  Serial.begin(115200);

  pinMode(LIGHT_PIN, INPUT);
  pinMode(SOUND_PIN, INPUT);
}

void loop() {
  rawLight = analogRead(LIGHT_PIN);
  rawSound = analogRead(SOUND_PIN);

  // Circular buffers
  rawSoundSamples[nSamples % WINDOW_SIZE] = rawSound;
  rawLightSamples[nSamples % WINDOW_SIZE] = rawLight;

  soundSmoothed = 0;
  lightSmoothed = 0;
  for (int i = 0; i < WINDOW_SIZE; i++) {
    soundSmoothed += rawSoundSamples[i];
    lightSmoothed += rawLightSamples[i];
  }
  soundSmoothed = soundSmoothed / WINDOW_SIZE;
  lightSmoothed = lightSmoothed / WINDOW_SIZE;

  nSamples += 1;

  Serial.print("rawLight:");
  Serial.print(rawLight);
  Serial.print(" lightSmoothed:");
  Serial.print(lightSmoothed);
  Serial.print(" rawSound:");
  Serial.print(rawSound);
  Serial.print(" soundSmoothed:");
  Serial.print(soundSmoothed);
  Serial.print(" nSamples:");
  Serial.print(nSamples);
  Serial.print(" nSamples%WINDOW_SIZE:");
  Serial.println(nSamples % WINDOW_SIZE);

  delay(10);
}
