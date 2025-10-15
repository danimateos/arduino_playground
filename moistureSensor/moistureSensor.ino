
int moistAnalog = 15;
int moistDigital = 16;

void setup() {
  pinMode(moistAnalog, INPUT);
  pinMode(moistDigital, INPUT);

  Serial.begin(115200);
}

void loop() {
  Serial.print(analogRead(moistAnalog));
  Serial.print(" ");
  Serial.println(digitalRead(moistDigital));
}
