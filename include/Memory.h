#ifndef MEMORY_H
#define MEMORY_H

#include "Definitions.h"

class Memory
{
    private:
        bool inBIOS;
        uint8_t storage[65535];
    public:
        Memory();
        virtual ~Memory();

        inline void SetBIOS(bool on)
        {
            inBIOS = on;
        };

        inline uint8_t GetByte(uint16_t index)
        {
            return storage[Indexer(index)];
        };

        inline uint16_t GetWord(uint16_t index)
        {
            index = Indexer(index);
            return (((uint16_t)storage[index]) << 8) | storage[index + 1];
        };

        inline void SetByte(uint16_t index, uint8_t value)
        {
            storage[Indexer(index)] = value;
        };

        inline void SetWord(uint16_t index, uint16_t value)
        {
            index = Indexer(index);
            storage[index] = ((uint8_t)value);
            storage[index + 1] = ((uint8_t)(value >> 8));
        };
    private:
        inline uint16_t Indexer(uint16_t index)
        {
            // Cheat by using the shadowed ram as our BIOS storage.
            if (inBIOS && index < 0x1000)
                return index + 0xE000;

            // Shadow RAM, maps to 0xC000 - 0xDE00/.
            if (index >= 0xE000 && index < 0xFE00)
                return index - 0x2000;

            // IO memory.
            // if (index >= 0xFF00 && index < 0xFF80)

            return index;
        };
};

#endif // MEMORY_H
