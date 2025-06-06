#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>

#define GxEPD2_DRIVER_CLASS GxEPD2_420_GDEY042T81

GxEPD2_BW<GxEPD2_DRIVER_CLASS, GxEPD2_DRIVER_CLASS::HEIGHT> display(
  GxEPD2_DRIVER_CLASS(/*CS=*/18, /*DC=*/17, /*RST=*/16, /*BUSY=*/15)
);

void setup() {
  Serial.begin(115200);
  display.init();
  display.setRotation(1);
  display.setFullWindow();

  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setCursor(10, 30);
    display.setTextSize(2);
    display.print("ePaper is working!");
  } while (display.nextPage());

  Serial.println("Display updated");
}

void loop() {
  // no loop action for now
}
