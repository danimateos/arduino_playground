#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Iaac-Wifi";
const char* password = "EnterIaac22@";
WiFiClient wifiClient;

const char* mqttBroker = "test.mosquitto.org";
const int mqttPort = 1883;
const char* mqttClientName = "leela";
const char* mqttUser = "";  // MQTT User Authentification
const char* mqttPass = "";  // MQTT Password Authentification
const char* my_topic = "fablabbcn/mdef/leela";
const char* partner_topic = "fablabbcn/mdef/danimateos";  // partner's topic
const char* all_topics_inside_mdef_1level = "fablabbcn/mdef/+";
const char* all_topics_recursive = "fablabbcn/mdef/#";
PubSubClient mqttClient(wifiClient);

int but = 0;   // Barduino
int led = 48;  // Barduino
bool pressed = false;

unsigned long lastMsg = 0;
char msg[50];


void mqttConnect() {

  while (!mqttClient.connected()) {

    Serial.print("Attempting MQTT connection...");

    if (mqttClient.connect(mqttClientName)) { // Alt: mqttClient.connect(mqttClientName, mqttUser, mqttPass);

      Serial.println("connected");
      mqttClient.publish(my_topic, "Good news everyone! I'm here");

      // Topic(s) subscription
      mqttClient.subscribe(partner_topic);
      //mqttClient.subscribe(all_topics_inside_mdef_1level);

    } else {

      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  String incomingMessage = "";
  for (int i = 0; i < length; i++) {
    incomingMessage += (char)payload[i];
  }

  Serial.println("Message arrived[" + String(topic) + "]: " + incomingMessage);
  if (incomingMessage == "on") {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}

void setup() {
  pinMode(but, INPUT);
  pinMode(led, OUTPUT);

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
  mqttClient.setServer(mqttBroker, mqttPort);
  mqttClient.setCallback(callback);
}



void loop() {
  // Check if we are still connected to the MQTT broker
  if (!mqttClient.connected()) {
    mqttConnect();
  }

  // Let PubSubClient library do his magic
  mqttClient.loop();

  // Add your publish code here --------------------

  if (!digitalRead(but) && !pressed) {
    digitalWrite(led, HIGH);
    Serial.println("ON");
    mqttClient.publish(my_topic, "on");
    pressed = true;
  } else if (digitalRead(but) && pressed) {
    digitalWrite(led, LOW);
    Serial.println("OFF");
    mqttClient.publish(my_topic, "off");
    pressed = false;
  }
}
