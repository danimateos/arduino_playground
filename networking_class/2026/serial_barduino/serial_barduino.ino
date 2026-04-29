#define INDICATOR_PIN 48

unsigned long i = 0;


void setup() {
  Serial.begin(115200);
  Serial1.begin(9600, SERIAL_8N1, 9, 8);  // Rx is 9 and Tx is 8

  pinMode(INDICATOR_PIN, OUTPUT);
}

void loop() {
  digitalWrite(INDICATOR_PIN, HIGH);
  Serial.print("Hey there; I'm Bard. Running ");
  Serial.println(i);

  Serial1.println("How you doin?");

  delay(500);

  if (Serial1.available()) {
    String content = Serial1.readStringUntil('\n');
    Serial.print("My buddy replied! They said ");
    Serial.println(content);

    if (content.equals("Beep!")) {
      Serial.println("So I beep!");
      tone(46, 400, 300);
    }
  }


  digitalWrite(INDICATOR_PIN, LOW);
  delay(200);

  i++;
}
