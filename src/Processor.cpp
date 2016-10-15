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

void Processor::LoadFrom(Register X){

}

void Processor::LoadFrom(){

}

void Processor::LoadTo(Register X){

}

void Processor::LoadTo(){

}

void Processor::DirectLoad(uint16_t n){

}

void Processor::DirectLoad(Register X, Register Y, uint16_t n){

}

void Processor::DirectLoadSP(uint16_t n){

}

void Processor::ImmediateLoad(Register X, uint8_t n){

}

void Processor::ImmediateLoad(Register X, Register Y, uint16_t n){

}
