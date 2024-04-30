#include <WiFi.h>
#include <PubSubClient.h>

#include <Adafruit_NeoPixel.h>

const char* ssid = "Iaac-Wifi";
const char* password = "";
WiFiClient wifiClient;

const char* mqttBroker = "mqtt-staging.smartcitizen.me";
const char* mqttClientName = "danimateos";
const char* mqttUser = "";  // MQTT User Authentification
const char* mqttPass = "";              // MQTT Password Authentification
const char* my_topic = "lab/fabacademy/danimateos";
const char* class_topic = "lab/fabacademy/class";
const char* partners_topic = "lab/fabacademy/emily";
PubSubClient mqttClient(wifiClient);

int but = 0;
int led = 48;
bool pressed = false;

#define NEOPIXL_PIN 38
#define NUMPIXELS 1

Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXL_PIN, NEO_GRB + NEO_KHZ800);

int hue = 0;

void mqttConnect() {

  while (!mqttClient.connected()) {

    Serial.print("Attempting MQTT connection...");

    if (mqttClient.connect(mqttClientName, mqttUser, mqttPass)) {

      Serial.println("connected");
      mqttClient.publish("hello", mqttClientName);

      // Topic(s) subscription
      mqttClient.subscribe(class_topic);
      mqttClient.subscribe(my_topic);

    } else {

      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  String incommingMessage = "";
  for (int i = 0; i < length; i++) {
    incommingMessage += (char)payload[i];
  }
  Serial.println("Message arrived[" + String(topic) + "]" + incommingMessage);
  int hue = incommingMessage.toInt();
  if (hue == 0) {
    pixels.clear();
  } else {
    pixels.setPixelColor(0, pixels.ColorHSV(hue, 255, 255));
  }
  pixels.show();  // Send the updated pixel colors to the hardware.
}

void setup() {
  pinMode(but, INPUT);
  pinMode(led, OUTPUT);

  pixels.begin();

  Serial.begin(115200);
  Serial.println("Hello");

  // Connect to wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // MQTT setup
  mqttClient.setServer(mqttBroker, 1883);
  mqttClient.setCallback(callback);
}

unsigned long lastMsg = 0;
char msg[50];

void loop() {
  // Check if we are still connected to the MQTT broker
  if (!mqttClient.connected()) {
    mqttConnect();
  }

  // Let PubSubClient library do his magic
  mqttClient.loop();

  // Add your publish code here --------------------

  if (Serial.available() > 0) {
    hue = Serial.parseInt();
    String name = (Serial.readStringUntil('\n'));
    name = "lab/fabacademy/" + name;
    Serial.println(hue);
    Serial.println(name);
    mqttClient.publish(name.c_str(), String(hue).c_str());
  }
}
