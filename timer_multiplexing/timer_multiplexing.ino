const int r1 = 0;
const int r2 = 1; 
const int r3 = 2; 
const int r4 = 3;

const int c1 = 4;
const int c2 = 5; 
const int c3 = 6; 
const int c4 = 7;

int rows[] = {r1, r2, r3, r4};
int cols[] = {c1, c2, c3, c4};
int all_pins[] = {r1, r2, r3, r4, c1, c2, c3, c4};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(all_pins[i], OUTPUT);
  }
  
  digitalWrite(r1, HIGH);
  digitalWrite(c2, HIGH);
  digitalWrite(c4, HIGH);
  
  Serial.begin(115200);
}

void loop() {
  Serial.println(digitalRead(r1));
  delay(1000);
}





void all_off() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(all_pins[i], LOW);
  }
}

void all_on() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(all_pins[i], HIGH);
  }
}
