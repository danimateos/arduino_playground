#include <ESP32Servo.h>  
s
// Barduino
const int SERVO = 11;  
const int POTENTIOMETER = 1;

Servo Servo;

int start, now;
int v_in;
long step;

void setup() {
  pinMode(POTENTIOMETER, INPUT);
  pinMode(SERVO, OUTPUT);
  Serial.begin(115200);

  Servo.attach(SERVO);

  start = millis();
  step = 0;  // will it overflow?
}

void loop() {

  now = millis();

  if (now - start >= 20) {  // Act every 20ms
    read();                 // update potentiometer readout
    step += 1;
    start = now;

    if (step % 5 == 0) {  // Only send commands every 5 steps (100ms)
      Serial.print("Step: ");
      Serial.println(step);

      float target = 180 * (v_in / 4095.0);
      Serial.print("target: ");
      Serial.println(target);

      Servo.write(target);
    }
  }
}

void read() {
  v_in = analogRead(POTENTIOMETER);
  // Serial.println(v_in);
}