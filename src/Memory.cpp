#include "../include/Memory.h"

Memory::Memory(GPU* gpu)
{
    this->gpu = gpu;
    inBIOS = false;
}

Memory::~Memory()
{
}


uint8_t Memory::GetByte(uint16_t index)
{
    index = Indexer(index);
    if (index >= 0xFF00 && index < 0xFF80)
    {
        switch(index & 0x00F0)
        {
            case 0x40:
            case 0x50:
            case 0x60:
            case 0x70:
                this->gpu->GetVram(index);
                break;
        }
    }

    return storage[Indexer(index)];
};

uint16_t Memory::GetWord(uint16_t index)
{
    index = Indexer(index);
    if (index >= 0xFF00 && index < 0xFF80)
    {
        switch(index & 0x00F0)
        {
            case 0x40:
            case 0x50:
            case 0x60:
            case 0x70:
                return (((uint16_t)this->gpu->GetVram(index)) << 8) | this->gpu->GetVram(index + 1);
        }
    }

    return (((uint16_t)storage[index]) << 8) | storage[index + 1];
};

void Memory::SetByte(uint16_t index, uint8_t value)
{
    index = Indexer(index);
    if (index >= 0xFF00 && index < 0xFF80)
    {
        switch(index & 0x00F0)
        {
            case 0x40:
            case 0x50:
            case 0x60:
            case 0x70:
                this->gpu->SetVram(index, value);
                return;
        }
    }

    storage[index] = value;
};

void Memory::SetWord(uint16_t index, uint16_t value)
{
    index = Indexer(index);
    if (index >= 0xFF00 && index < 0xFF80)
    {
        switch(index & 0x00F0)
        {
            case 0x40:
            case 0x50:
            case 0x60:
            case 0x70:
                this->gpu->SetVram(index, (uint8_t)value);
                this->gpu->SetVram(index + 1, (uint8_t)(value >> 8));
                return;
        }
    }

    storage[index] = ((uint8_t)value);
    storage[index + 1] = ((uint8_t)(value >> 8));
};

uint16_t Memory::Indexer(uint16_t index)
{
    // Cheat by using the shadowed ram as our BIOS storage.
    if (inBIOS && index < 0x1000)
        return index + 0xE000;

    // Shadow RAM, maps to 0xC000 - 0xDE00/.
    if (index >= 0xE000 && index < 0xFE00)
        return index - 0x2000;

    return index;
};
