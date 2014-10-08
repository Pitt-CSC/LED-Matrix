#####################################################################
# ScreenBuffer.py
#
# This file contains a Python class called ScreenBuffer which holds
# the pixel color values of a screen.
#####################################################################

#!/usr/bin/python
import Adafruit_BBIO.UART as UART
import serial
from ScreenBuffer import ScreenBuffer

UART.setup(uart)

class Sender:
    # The UART which we use.
    # RX -> P9_26
    # TX -> P9_24
    mUart = "UART1"
    mUartDev = "/dev/tty01"
    mBaudRate = 9600

    # Serial object which interfaces to the UART.
    mSerial = ""

    # The current screen buffer to send.
    mScreenBuffer = ScreenBuffer()

    # Constructor
    def __init__(self):
        self.mScreenBuffer = ScreenBuffer()

        UART.setup(Sender.mUart)

        mSerial = serial.Serial(port = mUartDev, buadrate = mBaudRate)
        mSerial.close()
        mSerial.open()
        if serial.isOpen():
            mSerial.write("Beaglebone serial is open.")

    # Set the ScreenBuffer to send.
    def SetScreenBuffer(self, screenBuffer):
        self.mScreenBuffer = screenBuffer

    # Send the data from a ScreenBuffer over UART.
    def SendScreenBuffer(self):
        pass
        # Pseudo-code implementation
        #! mSerial.write(TX begin command)
        #! wait for acknowledgement message to be received
        #! for each character in mScreen
        #!     mSerial.write(character)
        #! mSerial.write(TX end command)

# Tester
if __name__ == "__main__":
    sender = Sender()
    print sender.mScreenBuffer.mX
    screenBuffer = ScreenBuffer(10, 10)
    sender.SetScreenBuffer(screenBuffer)
    print sender.mScreenBuffer.mX

