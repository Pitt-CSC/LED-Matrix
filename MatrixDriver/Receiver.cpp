///////////////////////////////////////////////////////////
// Receiver.hpp
//
// This is the implementation file for the Receiver class.
///////////////////////////////////////////////////////////

#include "Receiver.hpp"
#include "ScreenBuffer.hpp"

// Set the singleton pointer to 0 to show that it has not
// been initialized.
Receiver* Receiver::mInstance = 0;

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

// Check if the required amount of bits have been written to the
// serial queue.
bool Receiver::ScreenBufferAvailable()
{
}

ScreenBuffer& Receiver::GetScreenBuffer()
{
}

bool Receiver::InitCommandReceived()
{
}

void Receiver::ClearSerialQueue()
{
}


/*
// Example how to use it.
int main()
{
    Receiver* receiver = Receiver::GetInstance();
    ScreenBuffer& screenBuffer;

    while (!receiver->InitCommandReceived());

    receiver->ClearSerialQueue();

    while (true)
    {
        if (receiver->ScreenBufferAvailable())
        {
            screenBuffer = receiver->GetScreenBuffer();
        }
    }
}
*/
