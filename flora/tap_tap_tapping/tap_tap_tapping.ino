#define MOSFET_PIN 9
#define BPM 90
#define TIME_ON 300

int black = 60000 / BPM;  // 60000 ms in a minute

void setup() {
  Serial.begin(9600);
}

void loop() {

  digitalWrite(MOSFET_PIN, HIGH);
  delay(TIME_ON);
  digitalWrite(MOSFET_PIN, LOW);
  delay(black - TIME_ON);

  digitalWrite(MOSFET_PIN, HIGH);
  delay(TIME_ON);
  digitalWrite(MOSFET_PIN, LOW);
  delay(black - TIME_ON);

  digitalWrite(MOSFET_PIN, HIGH);
  delay(TIME_ON);
  digitalWrite(MOSFET_PIN, LOW);
  delay(black / 2 - TIME_ON);

  digitalWrite(MOSFET_PIN, HIGH);
  delay(TIME_ON);
  digitalWrite(MOSFET_PIN, LOW);
  delay(black - TIME_ON);

  digitalWrite(MOSFET_PIN, HIGH);
  delay(TIME_ON);
  digitalWrite(MOSFET_PIN, LOW);
  delay(black / 2 - TIME_ON);

  digitalWrite(MOSFET_PIN, HIGH);
  delay(TIME_ON);
  digitalWrite(MOSFET_PIN, LOW);
  delay(black - TIME_ON);

  digitalWrite(MOSFET_PIN, HIGH);
  delay(TIME_ON);
  digitalWrite(MOSFET_PIN, LOW);
  delay(black - TIME_ON);

  digitalWrite(MOSFET_PIN, HIGH);
  delay(TIME_ON);
  digitalWrite(MOSFET_PIN, LOW);
  delay(black - TIME_ON);

  delay(black);
}
