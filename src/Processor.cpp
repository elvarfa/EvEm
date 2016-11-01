#include "../include/Processor.h"
#include "../include/Register.h"

Processor::Processor(Memory* memory)
{

    this->memory = memory;
    //pMemory->SetProcessor(this);
    InitOpcodes();
}

Processor::~Processor()
{
    delete operations;
    delete A;
    delete B;
    delete C;
    delete D;
    delete E;
    delete H;
    delete L;
    delete F;
    delete PC;
    delete SP;
}

// Loading into register r the contents of memory address (0xFFn).
void Processor::Load(Register* r, uint8_t n) {

}

/*Loads into register r the contents of the internal RAM or register specified
by the 16-bit immediate operand nn.*/
void Processor::Load(Register* r, uint16_t nn) {

}

/* Loads into register r the contents of internal RAM, port register, or mode
register at the address in the range 0xFF00-0xFFFF specified by register X.
Loads r <-- ($FF00+X).*/
void Processor::Load(Register* r, Register* X) {

}

/*Loads into register r the contents of memory specified by the contents of
register pair xy, simultaneously incrememnt the contents of HL.*/
void Processor::Load_Increment(Register* r, Register* X, Register* Y) {

}

/*Loads into register r the contents of memory specified by the contents of
register pair xy, simultaneously decrementing the contents of HL.*/
void Processor::Load_Decrement(Register* r, Register* X, Register* Y) {

}

/*From Register*/

// Loads into register r the contents of register X.
void Processor::Load_Register(Register* r, Register* X) {

}

/*Immediate Value*/

// Loads into register r the immediate value of n.
void Processor::Load_Immediate(Register* r, uint8_t n) {

}

/*To Memory*/

/*From Register*/

/*Loading from register r into memory address (0xFF00-0xFFFF) determined by
the value of n.*/
void Processor::Store(Register* r, uint8_t n) {

}

/*Stores the contents of register A at the internal RAM or register specified
by the 16-bit immediate operand nn.*/
void Processor::Store(Register* r, uint16_t nn) {

}

// Loads r -- > ($FF00+X)
void Processor::Store(Register* r, Register* X){

}

// Stores the contents of register r in memory specified by register pair xy.
void Processor::Store(Register* r, Register* X, Register* Y) {

}

/*Store the contents of register r in the memory specified by register pair xy,
simultaneously increment the contents of xy.*/
void Processor::Store_Increment(Register* r, Register* X, Register* Y){

}

/*Store the contents of register r in the memory specified by register pair xy,
simultaneously decrement the contents of xy.*/
void Processor::Store_Decrement(Register* r, Register* X, Register* Y) {

}

/*Immediate Value*/

// Loads 8-bit immediate data n into memory specified by register pair xy.
void Processor::Store(Register* X, Register* Y, uint8_t n) {

}

/*
/   16-bit loads
*/

/*To Register*/

/*Immediate Data*/

// Load two bytes of immediate data to register pair xy.
void Processor::Load(uint8_t n, uint8_t m, Register* X, Register* Y){

}

/*From Stack Pointer*/

// The 8-bit operand e is added to SP and the result is stored in HL.
void Processor::Load(Register* SP, Register* X, Register* Y, uint8_t e) {

}

/*To Memory*/

/*From Stack Pointer*/

/*Stores the lower byte of SP at address nn specified by the 16-bit immediate
operand nn and the upper byte of SP at address nn + 1.*/
void Processor::Store_SP(Register* SP, uint16_t nn){

}

/*To Stack Pointer*/

/*From Registers*/

// Load the contents of register pair HL(not the memory location) in stack pointer SP.
void Processor::Load(Register* X, Register* Y, Register* SP) {

}


/*Not sure how to classify push and pop....*/

/*Pushes the contents of register pair qq onto the memory stack. First 1 is
subtracted from SP and the contents of the higherportion of qq are placed on
the stack. The contents of the lower portion of qq are then placed on the
stack. The contents of SP are automatically decremented by 2.*/
void Processor::Push(Register* SP, Register* X, Register* Y){

}

/*Pops the contents from the memory stack and into register pair qq. First
the contents of memory, specified by the contents of SP are loaded in the
lower portion of qq. Next, the contents of SP are incremented by 1 and the
contents of the memory they specify are loaded in the upper portion of qq.
The contents of SP are automatically incremented by 2.*/
void Processor::Pop(Register* SP, Register* X, Register* Y) {

}


void Processor::ADD(Register* X, Register* Y){
    if (X->GetSize() == 1 && Y->GetSize() == 1)
    {
        uint16_t sum = (uint16_t)X->GetByte(0) + (uint16_t)Y->GetByte(0);
        if(sum > 255)
            this->F->SetHex(1, 0x1);

        X->SetByte(0, (uint8_t)(sum & 0x00FF));
    }
}

void Processor::ADD(Register* X, Register* Y, Register* Z, Register* W) {
    uint16_t xy = ((uint16_t)X->GetByte(0)) << 8;
    xy |= ((uint16_t)Y->GetByte(0));
    uint16_t zw = ((uint16_t)Z->GetByte(0)) << 8;
    zw |= ((uint16_t)W->GetByte(0));
    uint32_t sum = (uint32_t)xy + (uint32_t)zw;
    if(sum>65536)
        this->F->SetHex(1, 0x1);

    X->SetByte(0, (sum & 0xFF00) >> 8);
    Y->SetByte(0, sum & 0x00FF);

}

void Processor::ADD(Register* X, Register* Y, Register* ZW){
    uint16_t xy = ((uint16_t)X->GetByte(0)) << 8;
    xy |= ((uint16_t)Y->GetByte(0));
    uint16_t zw = ((uint16_t)ZW->GetHex(0));
    uint32_t sum = (uint32_t)xy +(uint32_t)zw;
    if(sum>65536)
        this->F->SetHex(1, 0x1);
}

void Processor::ADD(Register* X, uint8_t n){
    uint16_t sum = (uint16_t)X->GetByte(0) + n;
    if(sum > 255)
        this->F->SetHex(1, 0x1);

    X->SetByte(0, (uint8_t)(sum / 256));
}

void Processor::ADD(int8_t n){

}

void Processor::ADC(Register* X){

}

void Processor::ADC(uint8_t n){

}

void Processor::ADC(){

}

void Processor::SUB(Register* X){

}

void Processor::SUB(uint8_t n){

}

void Processor::SUB(){

}

void Processor::SBC(Register* X){

}

void Processor::SBC(uint8_t n){

}

void Processor::SBC(){

}

void Processor::AND(Register* X){

}

void Processor::AND(uint8_t n){

}

void Processor::AND(){

}

void Processor::OR(Register* X){

}

void Processor::OR(uint8_t n){

}

void Processor::OR(){

}

void Processor::XOR(Register* X){

}

void Processor::XOR(uint8_t n){

}

void Processor::XOR(){

}

void Processor::CP(Register* X){

}
void Processor::CP(uint8_t n){

}

void Processor::CP(){

}

void Processor::INC(Register* X){

}

void Processor::INC(){

}

void Processor::DEC(Register* X){

}

void Processor::DEC(){

}

void Processor::RLCA(){

}

void Processor::RLC(Register* X){

}

void Processor::RLC(){

}

void Processor::RLA(){

}

void Processor::RL(Register* X){

}

void Processor::RL(){

}

void Processor::RRCA(){

}

void Processor::RRC(Register* X){

}

void Processor::RRC(){

}

void Processor::RRA(){

}

void Processor::RR(Register* X){

}

void Processor::RR(){

}

void Processor::SLA(Register* X){

}

void Processor::SLA(){

}

void Processor::SRA(Register* X){

}

void Processor::SRA(){

}

void Processor::SRL(Register* X){

}

void Processor::SRL(){

}

/*void Processor::BIT(Bit b, Register* X){

}

void Processor::BIT(Bit b){

}

void Processor::SET(Bit b, Register* X){

}

void Processor::SET(Bit b){

}

void Processor::RES(Bit b, Register* X){

}

void Processor::RES(Bit b){

}*/

void Processor::DAA(){

}

void Processor::CPL(){

}

void Processor::SWAP(Register* X){

}

void Processor::SWAP(){

}

void Processor::CCF(){

}

void Processor::SCF(){

}

void Processor::NOP(){
    //No operation
}

void Processor::HALT(){

}

void Processor::STOP(){

}

void Processor::DI(){

}

void Processor::EI(){

}
