#include "../include/Processor.h"

void Processor::ProcessOpcode(uint8_t code)
{
    uint8_t temp = this->PC->GetByte(0);
    if (temp == 0xFF)
    {
        this->PC->SetByte(0, 0x00);
        temp = this->PC->GetByte(1);
        if (temp == 0xFF)
            this->PC->SetByte(1, 0x00);
        else
            this->PC->SetByte(1, temp + 1);
    }
    else
        this->PC->SetByte(0, temp + 1);

    (*operations)[code](this, &(this->mClock), &(this->tClock));
}

void Processor::InitOpcodes()
{
    operations = new std::unordered_map<uint8_t, std::function<void(Processor* p, unsigned int* m, unsigned int* t)>>();
    (*operations)[0x00] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x01] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x02] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x03] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x04] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x05] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x06] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x07] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x08] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x09] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x0A] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x0B] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x0C] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x0D] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x0E] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x0F] = [](Processor* p, unsigned int* m, unsigned int* t) {

    };
    (*operations)[0x80] = [](Processor* p, unsigned int* m, unsigned int* t) {
        p->ADD(p->A, p->B);
    };
}
