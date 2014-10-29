#include "Receiver.h"
#include "ScreenBuffer.h"
#include "Protocol.h"

Receiver* receiver;

void setup()
{
    receiver = Receiver::GetInstance();
}

void loop()
{
    // Wait for master to send initialization command.
    while (!receiver->InitCommandReceived());

    receiver->ClearSerialQueue();

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
