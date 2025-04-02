#include <FastCapacitiveSensor.h>
// https://github.com/Nyanyan/FastCapacitiveSensor

FastCapacitiveSensor sensor1;
#define SEND_PIN 1
#define RECEIVE_PIN 2

  
void setup() {
  pinMode(SEND_PIN, OUTPUT);
  pinMode(RECEIVE_PIN, INPUT);
  Serial.begin(9600);
  sensor1.begin(SEND_PIN, RECEIVE_PIN, 3.3, 10, 10, 0.2);
}

void loop() {
  long start = millis();

  Serial.print(sensor1.touch());

  Serial.print("\t");              // tab character for debug window spacing
  Serial.println(millis() - start);  // check on performance in milliseconds
  delay(10);                       // arbitrary delay to limit data to serial port
}
