from machine import Pin, PWM, Timer, UART
import time

import micropython
micropython.alloc_emergency_exception_buf(100)


## Barduino
# Barduino pin 14 is connected to the buzzer
r1 = Pin(11, Pin.OUT)
r2 = Pin(12, Pin.OUT)
r3 = Pin(13, Pin.OUT)  
r4 = Pin(15, Pin.OUT)

c1 = Pin(16, Pin.OUT)
c2 = Pin(17, Pin.OUT)
c3 = Pin(18, Pin.OUT)
c4 = Pin(21, Pin.OUT)

rows = (r1, r2, r3, r4)
cols = (c1, c2, c3, c4)
all_pins = rows + cols


def all_off():
    for pin in all_pins:
        pin.off()
    

def cols_on():
    for col in cols:
        col.on()
        
        
def rows_on():
    for row in rows:
        row.on()

def cols_off():
    for col in cols:
        col.off()
        
        
def rows_off():
    for row in rows:
        row.off()
        
        
def row_pattern(rows, pattern, duration):
    
    Timer(1).deinit()
    all_off()

    this_row = rows[0]
    other_rows = rows[1:]
    these_lights = pattern[:4]
    other_lights = pattern[4:]
    
    this_row.on()
    for on, col in zip(these_lights, cols):
        if on:
            col.on()
        
        
    def next_step(t):
        
        all_off()
        print(other_lights)
        if len(other_rows) > 0:
            row_pattern(other_rows, other_lights, duration)
    
    timer = Timer(1).init(period=duration, mode=Timer.ONE_SHOT, callback=lambda t: next_step(t))        
    
    
def show(pattern, duration, refresh_rate):
    
    millis = 1000 // refresh_rate
    
    Timer(0).init(freq=refresh_rate, mode=Timer.PERIODIC, callback = lambda t: row_pattern(rows, pattern, millis // 4)) # shortcut; might lead to inaccuracy
    
    Timer(2).init(period=duration, mode=Timer.ONE_SHOT, callback = lambda t: Timer(0).deinit())
                  
                  
                  
                  
def pos_to_row_col(n):
    
    row = rows[n % 4]
    col = cols[n // 4]
    

# 1 to 16
primes = (True, True, True, False, True, False, True, False,
          False, False, True, False, True, False, False, False)


show(primes, 2000, refresh_rate = 10)
    
    
    