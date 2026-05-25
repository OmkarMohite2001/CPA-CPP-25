#include <QObject>
#include "sender.h"
#include "receiver.h"

int main(void)
{
    Sender S(15, 5);
    Receiver R1, R2, R3, R4;

    QObject::connect(
        &S,
        SIGNAL(add(int,int)),
        &R1,
        SLOT(doAdd(int,int))
    );

    QObject::connect(
        &S,
        SIGNAL(subtract(int,int)),
        &R2,
        SLOT(doSubtract(int,int))
    );

    QObject::connect(
        &S,
        SIGNAL(multiply(int,int)),
        &R3,
        SLOT(doMultiply(int,int))
    );

    QObject::connect(
        &S,
        SIGNAL(divide(int,int)),
        &R4,
        SLOT(doDivide(int,int))
    );

    S.triggerArithmeticOperation(Sender::ADD);
    S.triggerArithmeticOperation(Sender::DIVIDE);
    S.triggerArithmeticOperation(Sender::MULTIPLY);
    S.triggerArithmeticOperation(Sender::SUBTRACT);

    return 0;
}
