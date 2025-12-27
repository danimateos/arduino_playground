import machine, neopixel
from time import sleep

n = 10
neopixel_pin = 12
strip = neopixel.NeoPixel(machine.Pin(neopixel_pin), n)

for i in range(n):
    strip.fill((0,0,0))
    strip[i] = (i * 20, 0, 150)
    strip.write()
    sleep(.2)

strip.fill((0,0,0))
strip.write()


