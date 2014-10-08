#!/usr/bin/python

DEFAULT_X = 32
DEFAULT_Y = 16

class ScreenBuffer:
    mX = 0
    mY = 0

    def __init__(self, x = DEFAULT_X, y = DEFAULT_Y):
        self.mX = x
        self.mY = y

#Tester
if __name__ == "__main__":
    screen = ScreenBuffer()
    print screen.mX
