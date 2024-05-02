import oscP5.*;
import netP5.*;
import controlP5.*;

OscP5 oscP5;
ControlP5 cp5;

void setup() {
  size(400, 400);

  oscP5 = new OscP5(this, 8000);

  cp5 = new ControlP5(this);

  cp5.addButton("sendLedOn")
    .setLabel("LED On")
    .setPosition(width/2-45, height/2-10)
    .setSize(100, 40);
}

void draw() {
  background(220);
}

void sendLedOn() {
  OscMessage moveMotorMsg = new OscMessage("/ledOn");
  oscP5.send(moveMotorMsg, new NetAddress("192.168.8.228", 8888));
  println("Mensaje /ledOn enviado a la dirección IP 192.168.8.228");
}
