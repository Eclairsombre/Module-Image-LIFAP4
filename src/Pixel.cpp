#include "Pixel.h"
#include <iostream>

Pixel::Pixel()
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

Pixel::Pixel(unsigned char rr, unsigned char gg, unsigned char bb)
{
    this->r = (int)rr;
    this->g = (int)gg;
    this->b = (int)bb;
}

void Pixel::afficherPixel() const
{
    std::cout << "r: " << (int)r << ", g: " << (int)g << ", b: " << (int)b << std::endl;
}