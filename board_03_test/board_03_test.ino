#include <Adafruit_DotStar.h>
#include <SPI.h>

#define NUMPIXELS 16  // Number of LEDs in strip
#define DATAPIN 15
#define CLOCKPIN 14
Adafruit_DotStar strip(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_GRB);

// Status indicator LED
#define LED_R 0
#define LED_G 1
#define LED_B 2

// Human input
#define BUTTON_1 3
#define BUTTON_2 6

// Sensor
#define HALL 7

void setup() {
  Serial.begin(115200);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_G, OUTPUT);

  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(HALL, INPUT);
}

void loop() {
  if (!digitalRead(BUTTON_1)) {
    Serial.println("BUTTON1");
  }


  if (!digitalRead(BUTTON_2)) {
    Serial.println("BUTTON2");
  }

  Serial.println(analogRead(HALL));

  digitalWrite(LED_R, LOW);
  digitalWrite(LED_B, HIGH);
  Serial.println("R");
  delay(200);

  digitalWrite(LED_G, LOW);
  digitalWrite(LED_R, HIGH);
  Serial.println("G");
  delay(700);

  digitalWrite(LED_B, LOW);
  digitalWrite(LED_G, HIGH);
  Serial.println("B");
  delay(700);
}
