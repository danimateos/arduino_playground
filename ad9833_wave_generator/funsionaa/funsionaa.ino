//= == == == == == == == == == == == =
//AD9833 Signal Generator
//========================
#include <SPI.h>
#include <AD9833.h>

  //----------------------------
  AD9833 gen(9);
long f;
int sw1, sw2;

//---

SPIClass *vspi = NULL;

//========================================
void setup() {
  pinMode(3, INPUT);
  pinMode(4, INPUT);

  vspi = new SPIClass(0);
  vspi->begin();

  gen.begin();
  // gen.enableOutput(true);
}
//========================================
void loop() {
  f = map(analogRead(A6), 0, 1023, 1000, 5000);
  sw1 = digitalRead(4);
  sw2 = digitalRead(3);

  //if (sw1 == LOW && sw2 == LOW) gen.applySignal(SINE_WAVE, REG0, f);
  //if (sw1 == LOW && sw2 == HIGH) gen.applySignal(TRIANGLE_WAVE, REG0, f);
  //if (sw1 == HIGH && sw2 == LOW) gen.applySignal(SQUARE_WAVE, REG0, f);
  //if (sw1 == HIGH && sw2 == HIGH) gen.applySignal(HALF_SQUARE_WAVE, REG0, f);
}