// Seeed XIAO RP2040
int LED = D0;
int BUTTON = D1;
int previousState, currentState, ledState;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);

  previousState = 0;
  currentState = 0;
  ledState = 0;
}

void loop() {
  Serial.print(previousState);
  Serial.print(", ");
  Serial.println(currentState);

  previousState = currentState;
  currentState = digitalRead(BUTTON);



  if (previousState == 1 && currentState == 0) {
    release();
  } else if (previousState == 0 && currentState == 1) {
    press();
  }

  delay(50);
}

void release() {
  // Placeholder
  Serial.println("RELEASE!");  
}

void press() {
  Serial.println("PRESS!");
  ledState = !ledState;
  digitalWrite(LED, ledState);
}