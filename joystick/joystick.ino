// Barduino

const int VCC_PIN = 15;
const int X_PIN = 14;
const int Y_PIN = 13;
const int SWITCH = 12;
const int UPDATE_FREQUENCY = 100;  // Hz

int x, y, start;
int switch_;
long step;

void setup() {
  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
  pinMode(SWITCH, INPUT);
  pinMode(VCC_PIN, OUTPUT);
  digitalWrite(VCC_PIN, HIGH);

  read();
  Serial.begin(115200);
  Serial.println("starting da game");
  start = millis();
  step = 0;
}

void loop() {


  if (start > 1000 / UPDATE_FREQUENCY) {
    start = millis();

    read();

    if (step % 10 == 0) {
      show();
    }

    step += 1;
  }
}


void read() {
  x = analogRead(X_PIN);
  y = analogRead(Y_PIN);
  switch_ = digitalRead(SWITCH);
}

void show() {
  Serial.print("X:");
  Serial.print(x);
  Serial.print(" Y:");
  Serial.print(y);
  Serial.print(" Switch:");
  Serial.println(switch_);
}
