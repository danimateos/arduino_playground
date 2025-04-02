long runs = 0;
int led = D10;

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("heyyy there... I see ");
  Serial.print(runs);
  Serial.println(" elephants");

  runs += 1;

  blink(runs % 10);

  delay(500);
}

void blink(int times) {

  for (int i = 0; i < times; i++) {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(50);
  }
}
