#include <iostream>
#include "csignal.h"
#include "cslot.h"

int main(void)
{
    CSignal signalEmitObjectOne;
    CSlot slotObject;

    slotObject.handlerFunction(-1000, -2000);
    slotObject.handlerFunction(600, 700);
    std::cout << "main():Emitting signal before connecting any slot" << std::endl;
    signalEmitObjectOne.trigger(100, 200);
    QObject::connect(
        &signalEmitObjectOne,
        SIGNAL(f(int,int)),
        &slotObject,
        SLOT(handlerFunction(int,int))
    );
    std::cout << "main():Emitting signal after connection slot" << std::endl;
    signalEmitObjectOne.trigger(100, 200);
    return 0;
}


