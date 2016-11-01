#include "../include/Processor.h"
#include "../include/Memory.h"
#include <string>

int main()
{
    int v = 0;

    Processor p(new Memory());
    while (p.IsRunning())
    {
        p.ProcessOpcode(p.FetchInstruction());
    }

    p.A->SetByte(0, 0x01);
    p.B->SetByte(0, 0x01);
    p.ProcessOpcode(0x80);

    printf("" + p.A->GetByte(0));

    return 0;
}
