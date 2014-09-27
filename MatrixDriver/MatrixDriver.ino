#include "Receiver.h"
#include "ScreenBuffer.h"

Receiver* receiver;

void setup()
{
    receiver = Receiver::GetInstance();
}

void loop()
{
    while (!receiver->InitCommandReceived());

    receiver->ClearSerialQueue();

    while (true)
    {
        if (receiver->ScreenBufferAvailable())
        {
            ScreenBuffer& screenBuffer = receiver->GetScreenBuffer();
        }
    }
}
