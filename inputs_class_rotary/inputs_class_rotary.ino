#define SW 17
#define DT 16
#define CLK 15

int sw = 0;
int prevSw = 0;
int dt = 0;
int prevDt = 0;
int clk = 0;
int prevClk = 0;

int position = 0;

void setup() {
  pinMode(SW, INPUT);
  pinMode(DT, INPUT);
  pinMode(CLK, INPUT);

  Serial.begin(115200);
}

void loop() {

  prevSw = sw;
  prevDt = dt;
  prevClk = clk;

  sw = digitalRead(SW);
  dt = digitalRead(DT);    // one of the contacts
  clk = digitalRead(CLK);  // the other one

  if (prevDt != dt) {  // one click advance
    Serial.println("Advance!");
    if (dt == clk) {
      position--;
      // dt is trailing clk; counter-clockwise

    } else {
      position++;
    }
  }
  Serial.println(position);


  // Serial.print("sw:");
  // Serial.print(sw);
  // Serial.print(" dt:");
  // Serial.print(dt);
  // Serial.print(" clk:");
  // Serial.println(clk);


  delay(1);
}
