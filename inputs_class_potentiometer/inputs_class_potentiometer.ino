void setup() {
  // put your setup code here, to run once:
  pinMode(17, INPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  int lecture = analogRead(17);
  Serial.println(lecture);
  delay(50);
}
