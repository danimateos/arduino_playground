#define inputPin 9

int value;

void setup() {
  pinMode(inputPin, INPUT);
  Serial.begin(115200);

  value = 0;
}

void loop() {
  value = value + 1;

  Serial.println(value);
  Serial.println(analogRead(inputPin));

  delay(50);
}
