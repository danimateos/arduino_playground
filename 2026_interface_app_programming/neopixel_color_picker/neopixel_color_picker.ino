#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN 38
#define NUM_PIXELS   1

Adafruit_NeoPixel strip(NUM_PIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

uint8_t r = 255, g = 0, b = 0;
bool ledEnabled = true;

// ======================================================
// HTML PAGE
// ======================================================
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>NeoPixel Control</title>

<style>
body{
  margin:0;
  background:#001030;
  color:white;
  font-family:Arial,Helvetica,sans-serif;
  display:flex;
  flex-direction:column;
  align-items:center;
  justify-content:center;
  height:100vh;
  user-select:none;
}

#wheelWrap{
  position:relative;
  width:300px;
  height:300px;
}

#wheel{
  width:300px;
  height:300px;
  border-radius:50%;
  touch-action:none;
  box-shadow:0 0 12px rgba(255,255,255,.25);
}

#cursor{
  position:absolute;
  width:18px;
  height:18px;
  border:3px solid #fff;
  border-radius:50%;
  box-shadow:0 0 5px #000;
  pointer-events:none;
  transform:translate(-50%,-50%);
}

#sliderWrap{
  margin-top:25px;
  width:300px;
}

#brightness{
  width:100%;
  appearance:none;
  height:18px;
  border-radius:12px;
  outline:none;
  background:linear-gradient(to right,#000,#ff0000);
}

#brightness::-webkit-slider-thumb{
  appearance:none;
  width:24px;
  height:24px;
  border-radius:50%;
  background:white;
  border:2px solid #222;
}

button{
  margin-top:25px;
  padding:12px 26px;
  font-size:16px;
  border:none;
  border-radius:12px;
  background:#18a0fb;
  color:white;
  cursor:pointer;
}

button.off{
  background:#c0392b;
}

#status{
  margin-top:14px;
  font-size:14px;
  color:#ccc;
}
</style>
</head>

<body>

<div id="wheelWrap">
  <canvas id="wheel" width="300" height="300"></canvas>
  <div id="cursor"></div>
</div>

<div id="sliderWrap">
  <input type="range" id="brightness" min="0" max="100" value="100">
</div>

<button id="toggleBtn">Disconnect</button>
<div id="status">Connecting...</div>

<script>
let ws;
let connected=false;

const canvas = document.getElementById("wheel");
const ctx = canvas.getContext("2d");
const cursor = document.getElementById("cursor");
const brightness = document.getElementById("brightness");
const statusTxt = document.getElementById("status");
const toggleBtn = document.getElementById("toggleBtn");

const size = 300;
const radius = 150;
const center = 150;

let hue = 0;
let sat = 1;
let val = 1;

// =======================
// Draw HSV Wheel
// =======================
function drawWheel(){
  const img = ctx.createImageData(size,size);

  for(let y=0;y<size;y++){
    for(let x=0;x<size;x++){
      const dx = x-center;
      const dy = y-center;
      const dist = Math.sqrt(dx*dx+dy*dy);

      const idx = (y*size+x)*4;

      if(dist<=radius){
        let angle = Math.atan2(dy,dx);
        if(angle<0) angle += Math.PI*2;

        const h = angle*180/Math.PI;
        const s = dist/radius;

        const rgb = hsvToRgb(h,s,1);

        img.data[idx+0]=rgb.r;
        img.data[idx+1]=rgb.g;
        img.data[idx+2]=rgb.b;
        img.data[idx+3]=255;
      }else{
        img.data[idx+3]=0;
      }
    }
  }
  ctx.putImageData(img,0,0);
}
drawWheel();

// =======================
// HSV to RGB
// =======================
function hsvToRgb(h,s,v){
  let c=v*s;
  let x=c*(1-Math.abs((h/60)%2-1));
  let m=v-c;

  let r=0,g=0,b=0;

  if(h<60){r=c;g=x;b=0;}
  else if(h<120){r=x;g=c;b=0;}
  else if(h<180){r=0;g=c;b=x;}
  else if(h<240){r=0;g=x;b=c;}
  else if(h<300){r=x;g=0;b=c;}
  else {r=c;g=0;b=x;}

  return {
    r:Math.round((r+m)*255),
    g:Math.round((g+m)*255),
    b:Math.round((b+m)*255)
  };
}

// =======================
// Update slider color
// =======================
function updateSlider(){
  const rgb = hsvToRgb(hue,sat,1);
  brightness.style.background =
   `linear-gradient(to right,#000,rgb(${rgb.r},${rgb.g},${rgb.b}))`;
}

// =======================
// Update cursor position
// =======================
function updateCursor(){
  const rad = sat * radius;
  const ang = hue*Math.PI/180;
  const x = center + Math.cos(ang)*rad;
  const y = center + Math.sin(ang)*rad;

  cursor.style.left = x+"px";
  cursor.style.top  = y+"px";
}

// =======================
// Send color
// =======================
function sendColor(){
  const rgb = hsvToRgb(hue,sat,val);

  if(ws && ws.readyState===1){
    ws.send(JSON.stringify({
      r:rgb.r,
      g:rgb.g,
      b:rgb.b
    }));
  }
}

// =======================
// Pick color from wheel
// =======================
function handlePick(e){
  const rect = canvas.getBoundingClientRect();
  const x = e.clientX - rect.left;
  const y = e.clientY - rect.top;

  const dx = x-center;
  const dy = y-center;
  const dist = Math.sqrt(dx*dx+dy*dy);

  if(dist>radius) return;

  let ang = Math.atan2(dy,dx);
  if(ang<0) ang += Math.PI*2;

  hue = ang*180/Math.PI;
  sat = dist/radius;

  updateCursor();
  updateSlider();
  sendColor();
}

let dragging=false;

canvas.addEventListener("mousedown",(e)=>{
  dragging=true;
  handlePick(e);
});

window.addEventListener("mousemove",(e)=>{
  if(dragging) handlePick(e);
});

window.addEventListener("mouseup",()=>dragging=false);

// touch
canvas.addEventListener("touchstart",(e)=>{
  dragging=true;
  handlePick(e.touches[0]);
});

window.addEventListener("touchmove",(e)=>{
  if(dragging) handlePick(e.touches[0]);
});

window.addEventListener("touchend",()=>dragging=false);

// brightness
brightness.addEventListener("input",()=>{
  val = brightness.value / 100;
  sendColor();
});

// =======================
// WebSocket
// =======================
function connectWS(){
  ws = new WebSocket(`ws://${location.host}/ws`);

  ws.onopen=()=>{
    connected=true;
    statusTxt.textContent="Connected";
    toggleBtn.textContent="Disconnect";
    toggleBtn.classList.remove("off");
  };

  ws.onclose=()=>{
    connected=false;
    statusTxt.textContent="Disconnected";
    toggleBtn.textContent="Connect";
    toggleBtn.classList.add("off");
  };
}

toggleBtn.onclick=()=>{
  if(connected){
    ws.close();
  }else{
    connectWS();
  }
};

connectWS();
updateCursor();
updateSlider();

</script>
</body>
</html>
)rawliteral";

// ======================================================
// WEBSOCKET
// ======================================================
void onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client,
               AwsEventType type, void *arg, uint8_t *data, size_t len) {

  if (type == WS_EVT_DATA) {

    String msg = String((char*)data).substring(0, len);

    r = msg.substring(msg.indexOf("\"r\":")+4, msg.indexOf(",\"g\"")).toInt();
    g = msg.substring(msg.indexOf("\"g\":")+4, msg.indexOf(",\"b\"")).toInt();
    b = msg.substring(msg.indexOf("\"b\":")+4, msg.indexOf("}")).toInt();

    if (ledEnabled) {
      strip.setPixelColor(0, strip.Color(r,g,b));
      strip.show();
    }
  }
}

// ======================================================
// SETUP
// ======================================================
void setup() {
  Serial.begin(115200);

  strip.begin();
  strip.clear();
  strip.show();

  WiFi.softAP("NeoPixel-AP", "12345678");
  Serial.println(WiFi.softAPIP());

  ws.onEvent(onWsEvent);
  server.addHandler(&ws);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *req){
    req->send_P(200, "text/html", index_html);
  });

  server.begin();
}

// ======================================================
void loop() {
  ws.cleanupClients();
}