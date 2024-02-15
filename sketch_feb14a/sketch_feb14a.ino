int led = 48;
int buzzer = 14;
int neopixel = 38;  // using barduino

int top = 4;
int right = 5;
int bottom = 6;
int left = 7;

String command;       // String input from command prompt
String temp1, temp2;  // temporary strings
char inByte;          // Byte input from command prompt
char carray[6];

void setup() {
  // put your setup code here, to run once:

  pinMode(led, OUTPUT);
  pinMode(neopixel, OUTPUT);
  pinMode(top, INPUT);
  pinMode(left, INPUT);
  pinMode(bottom, INPUT);
  pinMode(right, INPUT);

  Serial.begin(115200);
  delay(500);
  Serial.println("Hello, stranger!");

  Serial.flush();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println("Start");
  Serial.println(analogRead(left));
  analogWrite(led, 255);

  tone(buzzer, 400);

  delay(500);


  analogWrite(led, 0);
  noTone(buzzer);
  //neopixelWrite(neopixel, 24, 8, 16);
  delay(500);
}

// String takeInput() {
//   // Input serial information:
//   if (Serial.available() > 0) {
//     inByte = Serial.read();
//     // only input if a letter, number, =,?,+ are typed!
//     if ((inByte >= 65 && inByte <= 90) || (inByte >= 97 && inByte <= 122) || (inByte >= 48 && inByte <= 57) || inByte == 43 || inByte == 61 || inByte == 63) {
//       command.concat(inByte);
//     }


//     // Process command when NL/CR are entered:
//     if (inByte == 10 || inByte == 13) {

//       inByte = 0;
//     }
//   }
//   return command;
// }