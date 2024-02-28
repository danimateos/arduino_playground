int PHOTOTRANSISTOR = 3;

void setup() {
  pinMode(PHOTOTRANSISTOR, INPUT);
  Serial.begin(115200);
  Serial.println("HI THERE, I'M READY!");
}

void loop() {


  Serial.println(analogRead(PHOTOTRANSISTOR));
  delay(50);

}
