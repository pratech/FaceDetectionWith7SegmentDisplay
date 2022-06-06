import serial
import time
arduino = serial.Serial(port='COM3', baudrate=9600, timeout=.01)
def write_read(x):
 
    str_1_encoded = bytes(x,'UTF-8')
    arduino.write(str_1_encoded)
    time.sleep(0.05)
    #data = arduino.readline()
    #return data
while True:
    num = input("Enter a number: ") # Taking input from user
    value = write_read(num)
    print(value) # printing the value