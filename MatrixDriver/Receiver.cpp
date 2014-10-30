///////////////////////////////////////////////////////////
// Receiver.hpp
// *
// This is the implementation file for the Receiver class.
///////////////////////////////////////////////////////////

#include <Arduino.h>
#include "Receiver.h"
#include "ScreenBuffer.h"
#include "Protocol.h"

// Set the singleton pointer to 0 to show that it has not
// been initialized.
Receiver* Receiver::mInstance = 0;

Receiver::Receiver()
{

    for (int y = 0; y < mInstance->mScreenBuffer.Y; y++)
    {
        for (int x = 0; x < mInstance->mScreenBuffer.X; x++)
        {
            mInstance->mScreenBuffer.pixels[x][y] = {0x0, 0x0, 0x0};
        }
    }
}

Receiver* Receiver::GetInstance()
{
    // If the singleton has not been initialized yet,
    // initialize it.
    if (mInstance == 0)
    {
        mInstance = new Receiver();
    }
    
    return mInstance;
}

// Receive a complete screen buffer from the master.
// Screen buffers are sent and received byte by byte, where each
// byte is a primary color value for one pixel. Each pixel has
// three color values for red, green, and blue. Pixels are received
// starting from the top left (x=0, y=0), continuing down the same
// row (x is incremented until == 32), and then continuing on the next
// row until each row has been updated (y is incremented until == 16).
bool Receiver::ReceiveScreenBuffer()
{
    bool success = true;

    // Tell the master that we are ready to receive the data.
    Serial.write(ARD_CONFIRM);

    // Wait until we start receiving data.
    while (Serial.available() == 0);

    // Ensure that the master has sent the TX start byte.
    if (Serial.read() == BB_TX_FSCR)
    {
        for (int y = 0; y < mInstance->mScreenBuffer.Y; y++)
        {
            for (int x = 0; x < mInstance->mScreenBuffer.X; x++)
            {
                unsigned int r, g, b;

                // Between each byte, perform a conditional wait
                // in case we grab data from the serial queue faster
                // than the master sends it.
                while (Serial.available() == 0);
                r = Serial.read();
                while (Serial.available() == 0);
                g = Serial.read();
                while (Serial.available() == 0);
                b = Serial.read();

                // Copy the pixel data into the screen buffer.
                mInstance->mScreenBuffer.pixels[x][y].r = r;
                mInstance->mScreenBuffer.pixels[x][y].g = g;
                mInstance->mScreenBuffer.pixels[x][y].b = b;
            }
        }

        // Ensure that the master has sent the TX end byte.
        if (Serial.read() != BB_FSCR_END)
        {
            // Error: Did not receive BB_FSCR_END
            success = false;
        }
    }
    else
    {
        // Error: Did not receive BB_TX_FSCR
        success = false;
    }

    return success;
}

unsigned char Receiver::ReceiveMasterCommand()
{
    unsigned char cmd;

    if (Serial.available() != 0)
    {
        cmd = Serial.read();
    }
    else
    {
        cmd = 0;
    }

    return cmd;
}

bool Receiver::InitCommandReceived()
{
    bool initialized = false;

    if (Serial.available() != 0)
    {
        if (Serial.read() == BB_INIT_ARD)
        {
            Serial.write(ARD_CONFIRM);
            initialized = true;
        }
    }

    return initialized;
}

void Receiver::ClearSerialQueue()
{
}
