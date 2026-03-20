void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, buddy!");

  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);


  delay(400); // this speeds up the simulation
  Serial.println("hey!"); 
      digitalWrite(2, LOW);
  delay(400);
  Serial.println("ho!");
  tone(40, 440, 500);


}
