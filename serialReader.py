import serial

arduinoSerial = serial.Serial(
    port='/dev/ttyACM1',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=0)

print("connected to: " + arduinoSerial.portstr)

while True:
    if arduinoSerial.inWaiting() > 0:
        c = arduinoSerial.readline().rstrip().decode("utf-8")
        print('Received ' + c)
        arduinoSerial.write('OK\n'.encode())
        arduinoSerial.flushOutput()

arduinoSerial.close()
