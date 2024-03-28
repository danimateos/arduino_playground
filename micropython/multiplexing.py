from machine import Pin, PWM
import time


r1 = Pin(12, Pin.OUT)
r2 = Pin(13, Pin.OUT)
r3 = Pin(14, Pin.OUT)
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
        
        
def row_pattern(row, pattern, duration):
    
    all_off()
    row.on()
    
    for on, col in zip(pattern, cols):
        if on:
            col.on()
        
    
    time.sleep(duration)
    rows_off()
    cols_off()
    
    
def pattern(pattern, duration, refresh_rate=60):

    for frame in range(duration * refresh_rate):
    
        for row_p, row in zip(pattern, rows):
            row_pattern(row, row_p, (1 / refresh_rate) / 4)  # 4 roqs
    
    
def pos_to_row_col(n):
    
    row = rows[n % 4]
    col = cols[n // 4]
    

primes = [[True, True, True, False],
          [True, False, True, False],
          [False, False, True, False],
          [True, False, False, False]]


    
    
    