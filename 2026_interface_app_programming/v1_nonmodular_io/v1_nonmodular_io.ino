const int PIN_LED = 48;
const int PIN_BUTTON = 0;

// --- State Variables  ---
bool ledState = false;
int lastButtonState = LOW;
int currentButtonState = LOW;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);  // Physical button

  Serial.begin(9600);  // Communication with the App (via BT or USB)
  Serial.println("System Started. Waiting for events...");
}
void loop() {
  readInput();
  showOutput();
}

// CAPTURE INPUT EVENTS (Sensors/Buttons)
void readInput() {
  lastButtonState = currentButtonState;
  currentButtonState = digitalRead(PIN_BUTTON);

  // Event: The user pressed the physical button
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;  // Toggle state
    Serial.println("Event: Physical button pressed");
    delay(20);  // Simple debounce to avoid noise
  }
}

// UPDATE OUTPUTS (Reflect the state in the hardware)
void showOutput() {
  digitalWrite(PIN_LED, ledState);
}