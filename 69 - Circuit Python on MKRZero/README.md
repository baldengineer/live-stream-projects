## 69 - CircuitPython on MKR Zero

### see variables in a class
In the REPL (open COM port at 115200--does baud rate matter?)
```python
import board
dir(board)
```

* Are the ATSAMD's pins mapped to variables in CircuitPython?
** e.g. PB08 is L which is built-in LED

### onboard LED for MKR Zero
```L = LED // Clever!```

## check available memory
```python
import gc
gc.mem_free()
```


## VL53L0X - change blink rate based on distance
```python
import board
import busio
import adafruit_vl53l0x
import digitalio
import time

# for the Proximity Sensor
i2c = busio.I2C(board.SCL, board.SDA)
sensor = adafruit_vl53l0x.VL53L0X(i2c)

# For the on-board LED
led = digitalio.DigitalInOut(board.L)
led.direction = digitalio.Direction.OUTPUT

# soft timer 
previous_monotonic = time.monotonic()
led_state = True
interval = 500

def my_map(x, in_min, in_max, out_min, out_max):
    return int((x-in_min) * (out_max-out_min) / (in_max-in_min) + out_min)

while True:
	now = time.monotonic()
	if (now - previous_monotonic >= (interval/1000)):
		previous_monotonic = now
		if (led_state == True):
			led_state = False
		else:
			led_state = True
		led.value = led_state
		current = sensor.range
		#print('Range: {}mm'.format(sensor.range))
		interval = my_map(sensor.range, 10, 250, 100, 1000)
		print('Range: {}mm - mapped: {}'.format(current, interval))
```



## Livestream
These notes are part of Bald Engineer Live. An [electronics live stream](https://twitch.tv/baldengineer) that covers soldering, programming, and blinking LEDs.