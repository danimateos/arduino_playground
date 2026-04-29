#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN 38
#define NUM_PIXELS   1

Adafruit_NeoPixel strip(NUM_PIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

uint8_t r = 255, g = 0, b = 0; // initial color

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>NeoPixel</title>
  <style>
    body { font-family: sans-serif; display: flex; flex-direction: column;
           align-items: center; justify-content: center; height: 100vh; margin: 0;
           background: #111; color: #eee; }
    #preview { width: 80px; height: 80px; border-radius: 50%;
               margin-bottom: 1.5rem; border: 3px solid #333;
               background: rgb(255,0,0); transition: background 0.15s; }
    input[type=color] { width: 200px; height: 56px; border: none;
                        border-radius: 12px; cursor: pointer; background: none; }
    p { font-size: 13px; color: #888; margin-top: 1rem; }
  </style>
</head>
<body>
  <div id="preview"></div>
  <input type="color" id="picker" value="#ff0000">
  <p id="status">Connecting...</p>

  <script>
    const ws = new WebSocket(`ws://${location.host}/ws`);
    const picker = document.getElementById('picker');
    const preview = document.getElementById('preview');
    const status = document.getElementById('status');

    ws.onopen = () => { status.textContent = 'Connected'; };
    ws.onclose = () => { status.textContent = 'Disconnected'; };

    ws.onmessage = (e) => {
      // sync picker and preview if another client changed the color
      const d = JSON.parse(e.data);
      const hex = '#' + [d.r, d.g, d.b]
        .map(v => v.toString(16).padStart(2, '0')).join('');
      picker.value = hex;
      preview.style.background = hex;
    };

    picker.addEventListener('input', () => {
      const hex = picker.value;
      preview.style.background = hex;
      const r = parseInt(hex.slice(1,3), 16);
      const g = parseInt(hex.slice(3,5), 16);
      const b = parseInt(hex.slice(5,7), 16);
      if (ws.readyState === WebSocket.OPEN)
        ws.send(JSON.stringify({ r, g, b }));
    });
  </script>
</body>
</html>
)rawliteral";

void onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client,
               AwsEventType type, void *arg, uint8_t *data, size_t len) {

  if (type == WS_EVT_CONNECT) {
    // send current color to new client
    String msg = "{\"r\":" + String(r) + ",\"g\":" + String(g) + ",\"b\":" + String(b) + "}";
    client->text(msg);

  } else if (type == WS_EVT_DATA) {
    String msg = String((char*)data).substring(0, len);
    // parse {"r":255,"g":128,"b":0}
    r = msg.substring(msg.indexOf("\"r\":")+4, msg.indexOf(",\"g\"")).toInt();
    g = msg.substring(msg.indexOf("\"g\":")+4, msg.indexOf(",\"b\"")).toInt();
    b = msg.substring(msg.indexOf("\"b\":")+4, msg.indexOf("}"  )).toInt();

    strip.setPixelColor(0, strip.Color(r, g, b));
    strip.show();

    // broadcast to all other clients so they stay in sync
    String out = "{\"r\":" + String(r) + ",\"g\":" + String(g) + ",\"b\":" + String(b) + "}";
    ws.textAll(out);
  }
}

void setup() {
  Serial.begin(115200);

  strip.begin();
  strip.setPixelColor(0, strip.Color(r, g, b));
  strip.show();

  // Soft AP — no router needed
  WiFi.softAP("NeoPixel-AP", "12345678");
  Serial.println("AP IP: " + WiFi.softAPIP().toString()); // always 192.168.4.1

  ws.onEvent(onWsEvent);
  server.addHandler(&ws);
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *req){
    req->send_P(200, "text/html", index_html);
  });
  server.begin();
}

void loop() {
  ws.cleanupClients();
}