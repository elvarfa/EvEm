#include "../include/Screen.h"

Screen::Screen(int width, int height)
{
    this->width = width;
    this->height = height;
    this->pixels = new uint8_t[width * height * 4];
    this->Reset();
}

Screen::~Screen()
{
    delete[] this->pixels;
}

void Screen::SetPixels(int offset, uint8_t value)
{
    this->pixels[offset * 4] = value;
    this->pixels[offset * 4 + 1] = value;
    this->pixels[offset * 4 + 2] = value;
    this->pixels[offset * 4 + 3] = value;
}

void Screen::Reset()
{
    for (int i = 0; i < width * height * 4; i++)
        this->pixels[i] = 0xFF;
}
