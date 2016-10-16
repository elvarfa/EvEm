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

void Processor::PopXY(Register X, Register Y){

}

void Processor::Store(Memory Loc, Register X){

}

void Processor::Store(Memory Loc){

}

void Processor::Store(Register X){

}

void Processor::Store(){

}

void Processor::StoreValue(uint8_t n){

}

void Processor::ADD(Register X){

}
void Processor::ADD(uint8_t n){

}
void Processor::ADD(){

}

void Processor::ADC(Register X){

}

void Processor::ADC(uint8_t n){

}
void Processor::ADC(){

}

void Processor::SUB(Register X){

}

void Processor::SUB(uint8_t n){

}

void Processor::SUB(){

}

void Processor::SBC(Register X){

}

void Processor::SBC(uint8_t n){

}

void Processor::SBC(){

}

void Processor::AND(Register X){

}

void Processor::AND(uint8_t n){

}

void Processor::AND(){

}

void Processor::OR(Register X){

}

void Processor::OR(uint8_t n){

}

void Processor::OR(){

}

void Processor::XOR(Register X){

}

void Processor::XOR(uint8_t n){

}

void Processor::XOR(){

}

void Processor::CP(Register X){

}
void Processor::CP(uint8_t n){

}

void Processor::CP(){

}

void Processor::INC(Register X){

}

void Processor::INC(){

}

void Processor::DEC(Register X){

}

void Processor::DEC(){

}

void Processor::RLCA(){

}

void Processor::RLC(Register X){

}

void Processor::RLC(){

}

void Processor::RLA(){

}

void Processor::RL(Register X){

}

void Processor::RL(){

}

void Processor::RRCA(){

}

void Processor::RRC(Register X){

}

void Processor::RRC(){

}

void Processor::RRA(){

}

void Processor::RR(Register X){

}

void Processor::RR(){

}

void Processor::SLA(Register X){

}

void Processor::SLA(){

}

void Processor::SRA(Register X){

}

void Processor::SRA(){

}

void Processor::SRL(Register X){

}

void Processor::SRL(){

}

void Processor::BIT(Bit b, Register X){

}

void Processor::BIT(Bit b){

}

void Processor::SET(Bit b, Register X){

}

void Processor::SET(Bit b){

}

void Processor::RES(Bit b, Register X){

}

void Processor::RES(Bit b){

}

void Processor::DAA(){

}

void Processor::CPL(){

}

void Processor::SWAP(Register X){

}

void Processor::SWAP(){

}

void Processor::CCF(){

}

void Processor::SCF(){

}

void Processor::NOP(){

}

void Processor::HALT(){

}

void Processor::STOP(){

}

void Processor::DI(){

}

void Processor::EI(){

}
