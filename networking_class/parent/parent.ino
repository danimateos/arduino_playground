// Import required libraries
#include "WiFi.h"
#include "ESPAsyncWebServer.h"


// Set your access point network credentials
const char* ssid = "awesomest-access-point";
const char* password = "123456789";


// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

String readBut() {
  if (digitalRead(0)){
    return "OFF";
  }
  else{
    return "ON";
  }
}
  




void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  Serial.println();

  pinMode(0, INPUT);
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.on("/button", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBut().c_str());
  });
  
  // Start server
  server.begin();
}
 
void loop(){
  
}