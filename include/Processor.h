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

/*
/   Instruction Sets
*/

    /*
    /   8 and 16-bit Loads
    */

        /*
        /   Register to register
        */

        LoadFromA(Register X);                              //Loads the contents of register A into register X.
        LoadToA(Register X);                                //Loads the contents of register X into register A.
        LoadFromMem();                                      //Loads the contents of memory address (HL) into register A.
        LoadToMem();                                        //Loads the contents of register A into memory address (HL).

        /*
        /   Direct loading of registers
        */

        DirectLoadA(uint16_t n);                              //Loads from memory location ($uint16_t) into register A.
        DirectLoadXY(Register X, Register Y, uint16_t n);     //Loads from memory locations ($uint16_t) and
                                                            //($uint16_t+4) into registers X and Y.
        DirectLoadSP(uint16_t n);                             //Loads from memory location ($uint16_t) into Stack Pointer.

        /*
        /   Immediate loading of registers
        /   Can be used to load any specific register or register pair with a specific fixed value.
        */

        ImmediateLoadX(Register X, uint8_t n);                //Loads register X with the value $uint8_t.
        ImmediateLoadXY(Register X, Register Y, uint16_t n);  //Loads registers X and Y with the value $uint16_t.

        /*
        /   Stack loading of registers
        */

        PopXY(Register X, Register Y);

        /*
        /   Storing registers in memory
        */

        StoreXInMemory(Memory Loc, Register X);     //Loads the contents of register X into memory location ($Loc).
        StoreAInMemory(Memory Loc);                 //Loads the contents of register A into memory location ($Loc).
        StoreXAtHL(Register X);                     //Loads the contents of register X into memory location (HL).
        StoreAAtHL();                               //Loads the contents of register A into memory location (HL).
        StoreValueAtHL(uint8_t n);                  //Loads the value n into memory location (HL).

    /*
    /   8-bit Arithmetic and Logical Instructions
    */

        /*
        /
        */



    NOP();
    Increment(Register A);
    Decrement(Register A);
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
