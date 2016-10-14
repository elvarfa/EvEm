#ifndef PROCESSOR_H
#define	PROCESSOR_H

#include "definitions.h"
#include "SixteenBitRegister.h"
#include "boot_roms.h"

class Memory;

class Processor
{
public:
    Processor(Memory* pMemory);
    ~Processor();
};

#endif	/* PROCESSOR_H */
