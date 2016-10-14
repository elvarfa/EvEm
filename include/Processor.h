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
    NOP();
    Increment(Register A);
    Decrement(Register A);
    Load(Register A, Register B);
    Add(Register A, Register B);
    Subtract(Register A, Register B);
    Compare(Register A, Register B);
    RotateLeft(Register A);
    RotateRight(Register A);
    ShiftLeft(Register A);
    ShiftRight(Register A);
    Complement(Register) A; //Logical NOT
    OR(Register A, Register B);
    AND(Register A, Register B);
    XOR(Register A, Register B);
    Push(Register SP);
    Pop(Register SP);
    ClearCarryFlag(Register F);
    Reset(???);
};

private:
    Register A;
    Register B;
    Register C;
    Register D;
    Register E;
    Register H;
    Register L;
    Register F;
    Register PC;
    Register SP;
    unsigned int mClock;
    unsigned int tClock;

#endif	/* PROCESSOR_H */
