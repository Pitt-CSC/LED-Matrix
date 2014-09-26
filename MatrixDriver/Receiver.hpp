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

private:
    // Constructor and destructor kept private to allow
    // one instance.
    Receiver(){};
    ~Receiver(){};

    // Pointer to the single instance of Receiver.
    static Receiver* mInstance;
};

#endif
