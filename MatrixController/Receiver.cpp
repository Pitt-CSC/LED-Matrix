///////////////////////////////////////////////////////////
// Receiver.hpp
//
// This is the implementation file for the Receiver class.
///////////////////////////////////////////////////////////

#include "Receiver.hpp"

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

/*
 * Example how to use it.
int main()
{
    Receiver* r = Receiver::GetInstance();

    r->function();
}
*/
