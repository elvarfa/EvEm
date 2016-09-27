#include "Processor.h"

Processor* pt

Processor::Processor(Memory* pMemory)
{
    m_pMemory = pMemory;
    pMemory->SetProcessor()
}

Processor::~Processor()
{

}

void Processor::Init()
{

}

void Processor::Reset(bool bCGB, bool bootROM)
{

}

u8 Processor::Tick()
{

}

void Processor::RequestInterrupt(Interrupts interrupt)
{

}

void Processor::ResetTIMACycles()
{

}

void Processor::ResetDIVCycles()
{

}

bool Processor::Halted() const
{

}

bool Processor::CGBSpeed() const
{

}

void Processor::AddCycles(unsigned int cycles)
{

}

bool Processor::InterruptIsAboutToRaise()
{

}

bool Processor::BootROMfinished() const
{

}
