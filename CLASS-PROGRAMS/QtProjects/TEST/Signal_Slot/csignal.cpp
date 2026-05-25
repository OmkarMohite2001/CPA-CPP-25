#include <iostream>
#include "csignal.h"

CSignal::CSignal(): QObject()
{
}

void CSignal::trigger(int dataOne, int dataTwo)
{
    std::cout << "----Entered CSignal::trigger()----" << std::endl;
    std::cout << "CSignal::trigger():Emitting signal f() using dataOne and dataTwo as data----" << std::endl;
    std::cout << "CSignal::trigger():dataOne:" << dataOne << "\tdataTwo:" << dataTwo << std::endl;
    emit f(dataOne, dataTwo);
    std::cout << "CSignal::trigger():At this point the SLOT has already executed----" << std::endl;
    std::cout << "----Leaving CSignal::trigger()----" << std::endl;
}
