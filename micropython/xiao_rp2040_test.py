## Micropython can be installed on the Xiao RP2040
# as "MicroPython (Raspberry Pi Pico)" in Thonny
from machine import Pin, PWM

r = Pin(17, Pin.OUT)
g = Pin(16, Pin.OUT)
b = Pin(25, Pin.OUT)

# The rgb led pins are wired so that 1 if "off"
r.value(1)
g.value(1)
b.value(1)