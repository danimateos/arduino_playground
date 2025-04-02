#include <SPI.h>
#include <AD9833.h>


const float refFreq = 25000000.0;  // On-board crystal reference frequency

const int SINE = 0x2000;      // Define AD9833's waveform register value.
const int SQUARE = 0x2028;    // When we update the frequency, we need to
const int TRIANGLE = 0x2002;  // define the waveform when we end writing.

int wave = 0;
int waveType = SINE;
int wavePin = 7;

const int FSYNC = 10;  // Standard SPI pins for the AD9833 waveform generator.
const int CLK = 13;  // CLK and DATA pins are shared with the TFT display.
const int DATA = 11;



void setup() {
  // put your setup code here, to run once:
  AD9833reset();
  SPI.begin();

  AD9833setFrequency(440, SINE);  // Set the frequency and Sine Wave output
}

void loop() {
  // put your main code here, to run repeatedly:
}


// From https://www.vwlowen.co.uk/arduino/AD9833-waveform-generator/AD9833-waveform-generator.htm
void AD9833reset() {
  WriteRegister(0x100);  // Write '1' to AD9833 Control register bit D8.
  delay(10);
}

// Set the frequency and waveform registers in the AD9833.
void AD9833setFrequency(long frequency, int Waveform) {

  long FreqWord = (frequency * pow(2, 28)) / refFreq;

  int MSB = (int)((FreqWord & 0xFFFC000) >> 14);  //Only lower 14 bits are used for data
  int LSB = (int)(FreqWord & 0x3FFF);

  //Set control bits 15 ande 14 to 0 and 1, respectively, for frequency register 0
  LSB |= 0x4000;
  MSB |= 0x4000;

  WriteRegister(0x2100);
  WriteRegister(LSB);       // Write lower 16 bits to AD9833 registers
  WriteRegister(MSB);       // Write upper 16 bits to AD9833 registers.
  WriteRegister(0xC000);    // Phase register
  WriteRegister(Waveform);  // Exit & Reset to SINE, SQUARE or TRIANGLE
}

void WriteRegister(int dat) {

  // Display and AD9833 use different SPI MODES so it has to be set for the AD9833 here.
  SPI.setDataMode(SPI_MODE2);

  digitalWrite(FSYNC, LOW);  // Set FSYNC low before writing to AD9833 registers
  delayMicroseconds(10);     // Give AD9833 time to get ready to receive data.

  SPI.transfer(highByte(dat));  // Each AD9833 register is 32 bits wide and each 16
  SPI.transfer(lowByte(dat));   // bits has to be transferred as 2 x 8-bit bytes.

  digitalWrite(FSYNC, HIGH);  //Write done. Set FSYNC high
}
