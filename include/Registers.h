#ifndef REGISTERS_H
#define REGISTERS_H


class Registers
{
    private:
        int size;
        uint8_t* storage;
    public:
        Registers(int sizeInBytes);
        virtual ~Registers();

    protected:

    private:
};

#endif // REGISTERS_H
