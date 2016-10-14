#include "Processor.h"

Processor::Processor(Memory* pMemory)
{
    m_pMemory = pMemory;
    pMemory->SetProcessor(this)
}

Processor::~Processor()
{

}
