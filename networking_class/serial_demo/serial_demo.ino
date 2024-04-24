#include <SoftwareSerial.h>

EspSoftwareSerial::UART myPort;

void setup() {
  pinMode(48, OUTPUT);
  Serial.begin(115200);
  Serial0.begin(115200);
  delay(100);
  Serial.println("Let's begin! Falcon here");
  Serial0.println("This is coming through the rx tx pins. Everyone hates goats BTW.");

  myPort.begin(9600, SWSERIAL_8N1, 1, 2, false);  // bauds, protocol, Rx, Tx, invert 0s and 1s.
}

void loop() {
  if (Serial.available()) {
    char character = Serial.read();
    myPort.write(character);
    //Serial.write(character);
  }

  

  if (myPort.available()) {
    String reading = myPort.readString();
    if (reading == "On") {
      digitalWrite(48, HIGH);
    } else if (reading == "Off") {
      digitalWrite(48, LOW);
    }

    Serial.println(reading);
  }
}
