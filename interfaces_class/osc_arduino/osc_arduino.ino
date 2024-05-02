#include <OSCMessage.h>
#include <OSCBundle.h>
#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "GL-AR300M-0f0-NOR";
const char* password = "goodlife";

WiFiUDP Udp;
OSCMessage oscMessage;
OSCBundle oscBundle;

int ledPin = 48;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Conected to WiFi");

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Udp.begin(8888);

  pinMode(ledPin, OUTPUT);
}

void loop() {

  receiveOSCMessage();
}

void receiveOSCMessage() {
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    while (packetSize--) {
      oscMessage.fill(Udp.read());
    }

    if (!oscMessage.hasError()) {
      if (oscMessage.fullMatch("/ledOn")) {
        Serial.println("OSC Me: /ledOn");
        digitalWrite(ledPin, HIGH);  // turn the LED on (HIGH is the voltage level)
        delay(300);                  // wait
        digitalWrite(ledPin, LOW);   // turn the LED off by making the voltage LOW
        delay(300);                  // wait
      }
    }
    oscMessage.empty();
  }
}
