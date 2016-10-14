#include "Processor.h"

Processor::Processor(Memory* pMemory)
{
    m_pMemory = pMemory;
    pMemory->SetProcessor(this)
}

Processor::~Processor()
{

}

void Processor::8Bit_Add(Register B){
    this->A += B; //Addition
    this->F = 0;

}
