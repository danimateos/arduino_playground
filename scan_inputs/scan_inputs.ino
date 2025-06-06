// Barduino

// Sensor is 44E 402
// https://forum.arduino.cc/t/how-do-i-use-this-hall-sensor-44e-402/328142/5

// Connections
// Sensor - to GND
// Sensor center pin to board 02's 3V3
// 10k resistor between sensor S and center pin
// Sensor S to Barduino's pin 1
const int HZ = 200;
const int INTERFACE_HZ = 20;  // Needs to be an even split of HZ
const int INDICATOR_PIN = 21;
int reading_d, reading_a, detections;
long start, now, step;
int first = 10;
int last = 20;

void setup() {
  for (int i = first; i <= last; i++) {
    pinMode(i, INPUT);
  }


  pinMode(INDICATOR_PIN, OUTPUT);

  Serial.begin(115200);
  Serial.println("Ready to go!");
  start = millis();

  step = 0;

  digitalWrite(INDICATOR_PIN, HIGH);
}

void loop() {
  now = millis();


  if (now - start > 1000.0 / HZ) {
    step += 1;
    start = now;

    if (step % (HZ / INTERFACE_HZ) == 0) {
      show();
    }
  }
}


void show() {


  char buffer[150];
  for (int i = first; i <= last; i++) {
    sprintf(buffer, " Reading_%02d:%d", i, analogRead(i));
    Serial.print(buffer);
  }
  Serial.println("");
}