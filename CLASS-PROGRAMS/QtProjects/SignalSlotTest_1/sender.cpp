#include "sender.h"

Sender::Sender(int initDataOne, int initDataTwo) : QObject(), dataOne(initDataOne),
    dataTwo(initDataTwo)
{
}

void Sender::triggerArithmeticOperation(Sender::ARITHMETIC_OPERATION_TYPE aoType)
{
    switch(aoType)
    {
    case ADD:
        emit add(this->dataOne, this->dataTwo);
        break;

    case SUBTRACT:
        emit subtract(this->dataOne, this->dataTwo);
        break;

    case MULTIPLY:
        emit multiply(this->dataOne, this->dataTwo);
        break;

    case DIVIDE:
        emit divide(this->dataOne, this->dataTwo);
        break;
    }
}
