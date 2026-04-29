void setup() {
  Serial.begin(115200);

  Serial1.begin(9600);  // Is Rx 00?

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  Serial.println("Hi there! I'm Xiao");

  if (Serial1.available()) {
    String content = Serial1.readStringUntil('\n');
    digitalWrite(LED_BUILTIN, HIGH);

    Serial.print("I heard from my buddy! They say ");
    Serial.println(content);

    Serial1.println("Beep!");


    delay(500);
  }

  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
}
