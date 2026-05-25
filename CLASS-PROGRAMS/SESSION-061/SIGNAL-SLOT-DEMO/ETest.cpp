#include "ETest.hpp"

void ETest::raiseEvent() 
{
    emit myEvent(100, 200); 
}