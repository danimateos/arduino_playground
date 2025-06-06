int step = 10;
int dir = 11;

void setup() {
  Serial.begin(115200);

  pinMode(step, OUTPUT);
  pinMode(dir, OUTPUT);

  digitalWrite(dir, LOW);
}

void loop() {
  Serial.println("step!");


  digitalWrite(step, HIGH);
  delay(1);

  digitalWrite(step, LOW);
  delay(20);

  digitalWrite(step, HIGH);
  delay(1);

  digitalWrite(step, LOW);
  delay(20);

  digitalWrite(step, HIGH);
  delay(1);

  digitalWrite(step, LOW);
  delay(20);

  digitalWrite(step, HIGH);
  delay(1);

  digitalWrite(step, LOW);
  delay(20);

  delay(250);
}
