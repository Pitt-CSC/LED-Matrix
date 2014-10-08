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

# This class is used to send the data in a ScreenBuffer across UART
# byte by byte.
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
    mScreenBuffer = ""

    # Constructor
    # Initializes the ScreenBuffer and sets up the UART serial interface.
    def __init__(self):
        self.mScreenBuffer = ScreenBuffer()

        UART.setup(Sender.mUart)

        self.mSerial = serial.Serial(port = mUartDev, buadrate = mBaudRate)
        self.mSerial.close()
        self.mSerial.open()
        if self.mSerial.isOpen():
            self.mSerial.write("Beaglebone serial is open.")

    # Destructor
    # Cleans up data and closes the UART serial interface after
    # sending a blank ScreenBuffer.
    def __del__(self):
        # Get a blank ScreenBuffer.
        self.mScreenBuffer = ScreenBuffer()
        self.SendScreenBuffer()

        self.mSerial.close()


    # Set a new ScreenBuffer.
    def SetScreenBuffer(self, screenBuffer):
        del self.mScreenBuffer
        self.mScreenBuffer = screenBuffer

    # Send the data from a ScreenBuffer over UART.
    def Display(self):
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
    sender.Display()
    print sender.mScreenBuffer.mX
    del sender