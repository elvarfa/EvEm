#ifndef SCREEN_H
#define SCREEN_H

#include "Definitions.h"

class Screen
{
    private:
        int width;
        int height;
        uint8_t* pixels;
    public:
        Screen(int width, int height);
        virtual ~Screen();

        void Reset();
        void SetPixels(int offset, uint8_t value);
};

#endif // SCREEN_H
