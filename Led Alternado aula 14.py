import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)
GPIO.setup(12,GPIO.OUT)
GPIO.setup(13,GPIO.OUT)
x=GPIO.PWM(12,50)
y=GPIO.PWM(13,50)
x.start(0)
y.start(100)
try:
    while 1:
        for dc in range (0,1,101):
            i=100-dc
            y.changeDutyCycle(i)
            x.changeDutyCycle(dc)
            time.sleep(0.1)
        for dc in range (100,-1,-5):
            z=100-dc
            y.changeDutyCycle(z)
            x.changeDutyCycle(dc)
            time.sleep(0.1)
except KeyboardInterrupt:
    pass
x.stop()
GPIO.cleanup()