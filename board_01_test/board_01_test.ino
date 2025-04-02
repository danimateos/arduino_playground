// BOARD 01

int LEDR = 14;
int LEDG = 15;
int LEDB = 16;

void setup() {


  for (int i = 0; i < 17; i++) {  // pin 17 (physical 6) is UPDI
    pinMode(i, OUTPUT);
  }
  Serial.begin(115200);  // I can't get serial through a programmer?
}

void loop() {

  led_cycle();
  // for (int i = 0; i < 5; i++) {
  //   for (int j = 0; j < 5; j++) {
  //     digitalWrite(i * 4 + j, HIGH);
  //   }

  //   delay(500);

  //   for (int j = 0; j < 5; j++) {
  //     digitalWrite(i * 4 + j, LOW);
  //   }
  // }
}

void led_cycle() {
  digitalWrite(LEDB, LOW);
  digitalWrite(LEDR, HIGH);
  Serial.println("test");
  delay(1000);

  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, HIGH);
  delay(1000);

  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, HIGH);
  delay(1000);
}
