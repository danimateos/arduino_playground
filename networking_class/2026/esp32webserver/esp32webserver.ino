#include "WiFi.h"
#include "ESPAsyncWebServer.h"


int LED_PIN = 48;

// Set your access point network credentials
const char* ssid = "coolest-access-point";
const char* password = "123456789";


// Create AsyncWebServer object on port 80
AsyncWebServer server(80);


void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();


  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  pinMode(LED_PIN, OUTPUT);

  server.on("/someroute", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", "Whatever yourself");
  });

  server.on("/ledon", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(LED_PIN, HIGH);
    request->send_P(200, "text/plain", "Heard you, turning the damn thing on");
  });

  server.on("/ledoff", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(LED_PIN, LOW);
    request->send_P(200, "text/plain", "k bye");
  });

  
  // Start server
  server.begin();
}

void loop() {
}
