///////////////////////////////////////////////////////////
// ScreenBuffer.h
//
// This file defines a ScreenBuffer struct used to store
// an entire frame's pixel data.
///////////////////////////////////////////////////////////

#if !defined(SCREENBUFFER_H)
#define SCREENBUFFER_H

struct Pixel
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct ScreenBuffer
{
    static const int X = 32;
    static const int Y = 16;
    Pixel pixels[X][Y];

    void WriteToScreen();
};

#endif // #if !defined(SCREENBUFFER_H)
