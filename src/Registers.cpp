#include "Registers.h"

Registers::Registers(int sizeInBytes)
{
    size = sizeInHex;
    storage = new uint8_t[sizeInBytes];
}

Registers::~Registers()
{

}
