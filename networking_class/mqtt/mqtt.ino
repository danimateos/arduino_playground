#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Iaac-Wifi";
const char* password = "";
WiFiClient wifiClient;

const char* mqttBroker = "mqtt-staging.smartcitizen.me";
const char* mqttClientName = "danimateos";
const char* mqttUser = "";  // MQTT User Authentification
const char* mqttPass = "";              // MQTT Password Authentification
const char* my_topic = "lab/fabacademy/danimateos";
const char* class_topic = "lab/fabacademy/emily"; // partner's topic
const char* all_topics_inside_fab_1level = "lab/fabacademy/+"; 
const char* all_topics_recursive = "lab/fabacademy/#"; 
PubSubClient mqttClient(wifiClient);

int but = 0;
int led = 48;
bool pressed = false;

void mqttConnect() {

  while (!mqttClient.connected()) {

    Serial.print("Attempting MQTT connection...");

    if (mqttClient.connect(mqttClientName, mqttUser, mqttPass)) {

      Serial.println("connected");
      mqttClient.publish("hi to all goats! I'm a converted turkey", mqttClientName);

      // Topic(s) subscription
      mqttClient.subscribe(class_topic);
      //mqttClient.subscribe(name_topic);

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
  if (incommingMessage == "on") {
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

  // unsigned long max = 0;
  // int max_i;
  // for (int i=0; i<4; i++){
  //   values[i] = touchRead(i+4);
  //   //Serial.print(values[i]);
  //   //Serial.print(",");
  //   if (values[i] > max){
  //     max = values[i];
  //     max_i = i;
  //   }
  // }
  // //Serial.println("");
  // if (max > threshold && dir != direction[max_i]){
  //   dir = direction[max_i];
  //   Serial.println(dir);
  //   mqttClient.publish(draw_topic, dir.c_str());
  // }
  // else if (max <= threshold){
  //   dir="";
  // }
}
