#include "STest.hpp"
#include <iostream> 

void STest::myHandler(int x, int y)
{
    std::cout << "this:" << std::hex << this << std::endl; 
    std::cout << "x:" << x << ", y:" << y << std::endl; 
} 