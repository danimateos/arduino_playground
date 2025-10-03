from machine import Pin, PWM, TouchPad
import time


CALIBRATION_VALUE = 300000


def main():
    
    left_pin = Pin(12, Pin.OUT)
    right_pin = Pin(13, Pin.OUT)
    servo = Servo(14)
    led_pin = Pin(48, Pin.OUT)

    top = TouchPad(Pin(7, Pin.IN))
    right = TouchPad(Pin(4, Pin.IN))
    bottom = TouchPad(Pin(5, Pin.IN))
    left = TouchPad(Pin(6, Pin.IN))
    
    

    while(True):
        time.sleep(0.1)
    
#         print(f"T {top.read()} R {right.read()} B {bottom.read()} L {left.read()}")

        turn_speed = calculate_turn(left, right)
        turn(turn_speed, left_pin, right_pin)
        
        angle = calculate_pitch(top, bottom)
        pitch(angle, servo)
        
        
        
        print(f"turn_speed {turn_speed*100} pitch {angle}")
        
       
def turn(turn_speed, left, right):
    
    if turn_speed < -0.2:
        right.off()
        left.on()
    elif turn_speed > 0.2:
        left.off()
        right.on()
    else:
        left.off()
        right.off()
         
    

def pitch(angle, servo):
    servo.move(angle)


def calculate_turn(left_pad, right_pad):
    
    left_corrected = min(left_pad.read() / 300000, 1)
    right_corrected = min(right_pad.read() / 300000, 1)
    
    diff = right_corrected - left_corrected

    if abs(diff) < 0.2:
        return 0
    else:
        return diff
    
    
def calculate_pitch(top_pad, bottom_pad):
    
    top_corrected = min((top_pad.read()-30000) / 300000, 1)
    bottom_corrected = min((bottom_pad.read() -30000) / 300000, 1)

    limit_below = -10
    limit_above = 90
    angle = top_corrected * limit_above + bottom_corrected * limit_below
    
    return angle
    

class Servo:
    # these defaults work for the standard TowerPro SG90
    __servo_pwm_freq = 50
    __min_u10_duty = 26 - 0 # offset for correction
    __max_u10_duty = 123- 0  # offset for correction
    min_angle = 0
    max_angle = 180
    current_angle = 0.001


    def __init__(self, pin):
        self.__initialise(pin)


    def update_settings(self, servo_pwm_freq, min_u10_duty, max_u10_duty, min_angle, max_angle, pin):
        self.__servo_pwm_freq = servo_pwm_freq
        self.__min_u10_duty = min_u10_duty
        self.__max_u10_duty = max_u10_duty
        self.min_angle = min_angle
        self.max_angle = max_angle
        self.__initialise(pin)


    def move(self, angle):
        # round to 2 decimal places, so we have a chance of reducing unwanted servo adjustments
        angle = round(angle, 2)
        # do we need to move?
        if angle == self.current_angle:
            return
        self.current_angle = angle
        # calculate the new duty cycle and move the motor
        duty_u10 = self.__angle_to_u10_duty(angle)
        self.__motor.duty(duty_u10)

    def __angle_to_u10_duty(self, angle):
        return int((angle - self.min_angle) * self.__angle_conversion_factor) + self.__min_u10_duty


    def __initialise(self, pin):
        self.current_angle = -0.001
        self.__angle_conversion_factor = (self.__max_u10_duty - self.__min_u10_duty) / (self.max_angle - self.min_angle)
        self.__motor = PWM(Pin(pin))
        self.__motor.freq(self.__servo_pwm_freq)


main()
