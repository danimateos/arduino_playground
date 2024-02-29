from machine import Pin
import time


pins = range(29)

for pin in pins:
    something = Pin(pin, Pin.OUT)
    print(f"Checking pin {pin}")
    
    for _ in range(10):
        something.value(1)
        time.sleep(.1)
        something.value(0)
        time.sleep(.1)


led_a = Pin(0, Pin.OUT)  # Bottom center LED that we installed
led_b = Pin(1, Pin.OUT)  # Bottom right LED that we installed
led_d = Pin(26, Pin.OUT)  # Top left LED that we installed

blue = Pin(25, Pin.OUT)  # Blue led in RGB array
green = Pin(16, Pin.OUT)  # Blue led in RGB array
red = Pin(17, Pin.OUT)  # Red led in RGB array
