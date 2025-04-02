#define PIN 17

int prevReading = 0;
int reading = 0;
int timesPressed = 0;

void setup() {
  pinMode(PIN, INPUT);

  Serial.begin(115200);
}

void loop() {
  prevReading = reading;
  reading = digitalRead(PIN);

  if (prevReading == 1 && reading == 0) {
    timesPressed = timesPressed + 1;
  }

  Serial.print("reading:");
  Serial.print(reading);
  Serial.print(" timesPressed:");
  Serial.println(timesPressed);
}
