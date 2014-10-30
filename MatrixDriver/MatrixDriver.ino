
// Library includes for RGBmatrixPanel
#include <Adafruit_GFX.h>
#include <gamma.h>
#include <RGBmatrixPanel.h>

// Local includes
#include "Receiver.h"
#include "ScreenBuffer.h"
#include "Protocol.h"
#include "Matrix.h"

Receiver* receiver;
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, true);

void setup()
{
    // Start the serial interface.
    Serial.begin(BAUD_RATE);
    
    // Instantiate the Receiver to communicate with the master.
    receiver = Receiver::GetInstance();
    
    // Start up the matrix interface.
    matrix.begin();
    
    // Clear the screen.
    matrix.fillScreen(0);
    matrix.swapBuffers(false);
}

void loop()
{
    // Wait for master to send initialization command.
    while (!receiver->InitCommandReceived());

    while (true)
    {
        unsigned int cmd;

        cmd = receiver->ReceiveMasterCommand();

        switch (cmd)
        {
        case BB_FULLSCR_TX:
            receiver->ReceiveScreenBuffer();
            receiver->GetScreenBuffer().WriteToScreen();
            break;
        }

    }
}
