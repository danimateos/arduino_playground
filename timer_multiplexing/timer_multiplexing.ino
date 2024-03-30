const int r1 = 0;
const int r2 = 1;
const int r3 = 2;
const int r4 = 3;

const int c1 = 4;
const int c2 = 5;
const int c3 = 6;
const int c4 = 7;

const int nRows = 4;
const int nCols = 4;

int rows[nRows] = { r1, r2, r3, r4 };
int cols[nCols] = { c1, c2, c3, c4 };
int all_pins[nRows + nCols] = { r1, r2, r3, r4, c1, c2, c3, c4 };
bool pattern[nRows * nCols];

bool primes[nRows * nCols] = { true, true, true, false, true, false, true, false, false, false, true, false, true, false, false, false };
bool testPattern[nCols] = {true, false, true, true};

long iteration = 0;
long start, end;
int nCycles = 1000;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(all_pins[i], OUTPUT);
  }

  Serial.begin(115200);

  // See p 378 of the datasheet
  PORT_IOBUS->Group[0].OUTCLR;  // https://forum.arduino.cc/t/what-is-the-fastest-way-to-read-write-gpios-on-samd21-boards/907133/9
  start = micros();
  Serial.println("Let us play");
}

void loop() {

  
  rowShow(r3, testPattern);


  iteration += 1;

  if (iteration % nCycles == 0) {
    end = micros();

    long averageTime = (end - start) / nCycles;
    Serial.println(averageTime);
    start = micros();
  }
}

void rowShow(int row, bool pattern[]) {
  allOff();
  digitalWrite(row, HIGH);

  for (int i = 0; i < nCols; i++) {
    if (pattern[i]) {
      digitalWrite(cols[i], HIGH);
    }
  }
}


void allOff() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(all_pins[i], LOW);
  }
}

void allOn() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(all_pins[i], HIGH);
  }
}
