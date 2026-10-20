#define LED_PIN 4
#define BUZZER_PIN 5
#define BUTTON_PIN 6

bool currentButtonState = false;
bool previousButtonState = false;

int presses = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);  // baud rate
}

void loop() {
  previousButtonState = currentButtonState;  // What was current last turn of the loop is previous this time
  currentButtonState = digitalRead(BUTTON_PIN);

  if (currentButtonState == true && previousButtonState == false) {  // Rising edge
    // Read the pin, invert the value, write it back (toggle)
    digitalWrite(LED_PIN, !digitalRead(LED_PIN)); 

    tone(BUZZER_PIN, 440, 300);
    presses++; // presses = presses + 1;  

  }

  Serial.println(presses);
  delay(25);  // Debounce button press
}




