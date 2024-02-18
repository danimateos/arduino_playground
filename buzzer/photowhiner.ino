int led = 48;
int buzzer = 14;
int neopixel = 38;  // using barduino
int photoresistor = 3;
//TODO:  Temperature Sensor: TMP102 connected by I^2^C by GPIO08 and GPIO09.


int TOP = 4;
int RIGHT = 5;
int BOTTOM = 6;
int LEFT = 7;

int UPDATE_MILLIS = 50;

int freq;
long start, end;
int photoresistorReading;


void setup() {
  // put your setup code here, to run once:

  pinMode(TOP, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(BOTTOM, INPUT);
  pinMode(LEFT, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(neopixel, OUTPUT);
//  pinMode(led, OUTPUT);

  ledcAttachPin(led, 1); // assign led pins to channel 1
  ledcSetup(1, 12000, 8);

  Serial.begin(115200);
  Serial.println("We're on!");

  neopixelWrite(neopixel, 0, 0, 0);
}

void loop() {
  // put your main code here, to run repeatedly:

  start = millis();
  noTone(buzzer);
  photoresistorReading = 0;
  
  for (int i = 0; i < 5; i++) {
    photoresistorReading += analogRead(photoresistor);
    delay(UPDATE_MILLIS / 20);
  }
  photoresistorReading = photoresistorReading / 5;

  //analogWrite(led, photoresistorReading / 20); // Weird results
  ledcWrite(1, (photoresistorReading / 10)); // ledc: requested frequency and duty resolution can not be achieved Ah! se me queda en cero!
  tone(buzzer, photoresistorReading / 4); 

  Serial.print(analogRead(TOP));
  Serial.print(", ");
  Serial.print(analogRead(RIGHT));
  Serial.print(", ");
  Serial.print(analogRead(BOTTOM));
  Serial.print(", ");
  Serial.print(analogRead(LEFT));
  Serial.print(", ");
  Serial.println((photoresistorReading / 10));


  end = millis();

  delay(UPDATE_MILLIS - (end - start));
}
