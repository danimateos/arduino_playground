#define LED_PIN 4
#define BUTTON_PIN 6

bool currentButtonState = false;
bool previousButtonState = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  previousButtonState = currentButtonState;  // What was current last turn of the loop is previous this time
  currentButtonState = digitalRead(BUTTON_PIN);

  if (currentButtonState == HIGH && previousButtonState == LOW) {  // Rising edge
    // Read the pin, invert the value, write it back (toggle)
    digitalWrite(LED_PIN, !digitalRead(LED_PIN)); 
  }

  delay(25);  // Debounce button press
}