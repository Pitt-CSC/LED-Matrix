///////////////////////////////////////////////////////////
// Receiver.hpp
//
// This file declares a Receiver class used to receive
// messages and data from an external master controller.
///////////////////////////////////////////////////////////

#if !defined(RECEIVER_HPP)
#define RECERIVER_HPP

class Receiver
{
public:
    // Get pointer to the single instance of Receiver.
    static Receiver* GetInstance();

    // Check if the master controller has sent a full screen buffer.
    static bool ScreenBufferAvailable();

    // Construct a screen buffer from the received data.
    static ScreenBuffer& GetScreenBuffer();

    // Check if the master controller has sent an init command.
    static bool InitCommandReceived();

    // Clear the queue of data received from the master.
    static void ClearSerialQueue();

private:
    // Constructor and destructor kept private to allow
    // one instance.
    Receiver(){};
    ~Receiver(){};

    // Pointer to the single instance of Receiver.
    static Receiver* mInstance;
};

#endif
