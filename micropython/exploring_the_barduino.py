from machine import Pin, PWM
import time
# https://micropython-on-wemos-d1-mini.readthedocs.io/en/latest/basics.html#beepers

c = 262
d = 294
e_f = 311
e = 330
f = 349
g = 392
a = 440
b = 494
C = 523

buzzer_pin = Pin(14, Pin.OUT)
led_pin = Pin(48, Pin.OUT)

buzzer = PWM(buzzer_pin, freq=e, duty=512)


tempo = 112
blank_space = .05
melody = [(e, 4),
          (e, 4),
          (e, 4),
          (c, 3),
          (g, 1),
          (e, 4),         
          (c, 3),
          (g, 1),          
          (e, 8),          
          (b, 4),          
          (b, 4),
          (b, 4),          
          (C, 3),
          (g, 1),
          (e_f, 4),
          (c, 3),
          (g, 1),
          (e, 4),         
          (c, 3),
          (g, 1),          
          (f, 8)]
          
for tone, duration in melody:
    print(f'tone:{tone} duration:{duration}')
    
    # buzzer.freq(tone)
    PWM(buzzer_pin, freq=tone, duty=512)
    led_pin.value(1)
    time.sleep((60 / tempo) * duration / 4 - blank_space)
    
    buzzer.duty(0)
    led_pin.value(0)
    time.sleep(blank_space)




