int LED = 48;
int NEOPIXEL = 38;  // using barduino

int TOP = 4;
int RIGHT = 5;
int BOTTOM = 6;
int LEFT = 7;

int UPDATE_MILLIS = 50;

int top, right, bottom, left = 0;

int start;
int r, g, b = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(NEOPIXEL, OUTPUT);
  pinMode(TOP, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(BOTTOM, INPUT);
  pinMode(LEFT, INPUT);

  Serial.begin(115200);
  Serial.println("Hello, stranger!");

  start = millis();

  r = 0;
  g = 0;
  b = 0;

  updateColor();
}

void loop() {

  readState();

  if (millis() - start >= UPDATE_MILLIS) {
    start = millis();
    printState();
    updateColor();
  }
}



void readState() {
  top = touchRead(TOP);
  right = touchRead(RIGHT);
  bottom = touchRead(BOTTOM);
  left = touchRead(LEFT);
}

void printState() {
  Serial.print(top);
  Serial.print(", ");
  Serial.print(right);
  Serial.print(", ");
  Serial.print(bottom);
  Serial.print(", ");
  Serial.println(left);
}

void updateColor() {

  if (top > 200000) {
    r += 5;
  }

  if (bottom > 200000) {
    r -= 5;
  }

  if (left > 200000) {
    b -= 5;
  }
  if (right > 200000) {
    b += 5;
  }

  r = cap(r, 0, 255);
  g = cap(g, 0, 255);
  b = cap(b, 0, 255);

  neopixelWrite(NEOPIXEL, r, g, b);
}

int cap(int value, int min, int max) {
  if (value < min) return min;
  if (value > max) return max;

  return value;
}
