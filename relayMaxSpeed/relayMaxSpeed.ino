int buttonPin = 0;
int relayPin = 12;
int buzzerPin = 46;

int maxFrequency = 200;
int minFrequency = 20;
int frequency = minFrequency;
int buttonState = LOW;
int prevState = LOW;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  Serial.begin(115200);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && prevState == HIGH) {
    // button has been pressed
    frequency += 10;
    tone(buzzerPin, 400, .2);
  }

  prevState = buttonState;

  if (frequency > maxFrequency) {
    frequency = minFrequency;
  }
  
  Serial.println(frequency);


  digitalWrite(relayPin, HIGH);
  delay((1000 / frequency) / 2);
  digitalWrite(relayPin, LOW);
  delay((1000 / frequency) / 2);
}
