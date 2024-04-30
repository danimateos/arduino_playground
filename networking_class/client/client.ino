#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "JosepESP32";
const char* password = "123456789";

//Your IP address or domain name with URL path
const char* serverNameButton = "http://192.168.4.1/button";

String button;

unsigned long previousMillis = 0;
const long interval = 100; 

void setup() {
  Serial.begin(115200);
  pinMode(48, OUTPUT);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval) {
     // Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED ){ 
      button = httpGETRequest(serverNameButton);
      Serial.println(button);
      if (button == "ON"){
        digitalWrite(48, HIGH);
      }
      else{
        digitalWrite(48, LOW);
      }

      // save the last HTTP GET Request
      previousMillis = currentMillis;
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  }
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your Domain name with URL path or IP address with path
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}