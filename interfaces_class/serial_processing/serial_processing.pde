import processing.serial.*;

Serial myPort;
int val;

void setup() {
  size(200, 200);
  String portName  = "/dev/cu.usbmodem1401";  //Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  print(portName);
}


void draw() {
  background(255);

  if (mouseOverRect() == true) {
    fill(204);
    myPort.write('H');
  } else {
    fill(0);
    myPort.write('L');
  }

  rect(50, 50, 100, 100);
}

boolean mouseOverRect() {
  return (mouseX >= 50 && mouseX <= 150) && (mouseY >= 50 && mouseY <= 150);
}
