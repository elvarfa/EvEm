#ifndef REGISTER_H
#define REGISTER_H


class Register
{
    private:
        int size;
        uint8_t* storage;
    public:
        Register(int sizeInBytes);
        virtual ~Register();

    protected:

    private:
};

#endif // REGISTER_H
