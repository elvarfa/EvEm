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
    8Bit_Add(Register B);
    8Bit_Add_Mem();
    8Bit_Add_unsigned(uint8_t n);
    8Bit_Add_signed(int8_t n);
    16Bit_Add(Register A, Register B);
    16Bit_Add_SP();
    8Bit_Sub(Register B);
    8Bit_Sub_Mem();
    8Bit_Sub_unsigned(uint8_t n);
    Compare(Register A, Register B);
    RotateLeft(Register A);
    RotateRight(Register A);
    ShiftLeft(Register A);
    ShiftLeft_HL();
    ShiftRight(Register A);
    ShiftRight_HL();
    Complement(Register A); //Logical NOT
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
