int led = 48;
int buzzer = 14;
int neopixel = 38;  // using barduino

int top = 4;
int right = 5;
int bottom = 6;
int left = 7;

int freq;
long start, end;

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
  

  freq = 400;

  for (int i=0; i < 20; i++) {
    tone(buzzer, freq);
    freq *= 1.05946;
    Serial.println(freq);
    delay(10);
  }


  delay(500);


  analogWrite(led, 0);
  noTone(buzzer);
  //neopixelWrite(neopixel, 24, 8, 16);
  delay(500);
}

// An octave is a ratio of 2:1, so from 100 Hz to 200 Hz, and from 200 Hz to 400 Hz, are both octaves. A semitone is a ratio of the 12th root of 2 to 1, which is equal to 1.05946:1, so 1000 Hz and 1059.46 Hz are a semitone apart.

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