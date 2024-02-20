int start, end;
int reading_a, reading_b;
bool state;
int button;

// Barduino. Button pressed is 0
// int LED = 48; 
// int BUTTON = 0;

// Seeed XIAO RP2040. Button pressed is 1
int LED = 26; 
int BUTTON = 27;


void setup() {
  Serial.begin(115200);

  pinMode(BUTTON, INPUT);

  pinMode(LED, OUTPUT);

  state = LOW;
  start = millis();
}

void loop() {

  button = digitalRead(BUTTON); // 1 is unpressed

  Serial.println(button);

  // Blink if pressed, non blocking
  if (millis() - start >= 50 && button) {
    state = !state;
    digitalWrite(LED, state);
    start = millis();
  }

  
}
