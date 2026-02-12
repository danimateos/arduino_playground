from machine import I2C


# Barduino has an onboard LM75 temperature sensor connected to the I2C bus
i2c = I2C()

print(i2c.scan())

i2c.readfrom(72, 2)