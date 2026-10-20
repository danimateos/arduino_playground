// Pin 4 is not PWM-capable so we'll
// connect to 6 with a Grove cable.
#define LED_PIN 6
#define POTENTIOMETER_PIN A0

int reading = 0;
int brightness = 0;

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
}

void loop() {
  reading = analogRead(POTENTIOMETER_PIN);
  brightness = map(reading, 0, 1023, 255, 0);

  Serial.println(reading);
  analogWrite(LED_PIN, brightness);
}
