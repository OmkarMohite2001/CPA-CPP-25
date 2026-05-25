#include <iostream> 

void test(void); 

int main(void)
{
    test(); 
    return (0); 
}

void test(void)
{
    int* p1 = new int(100); 
    int& ref1 = *p1; 
    
    std::cout << "*p1 = " << *p1 << std::endl;  // 100 
    ref1 = 500; 
    std::cout << "*p1 = " << *p1 << std::endl;  // 500; 

    delete &ref1; 
    p1 = 0; 

    int& ref2 = *(new int(100)); 
    std::cout << "initial value of ref2:" << ref2 << std::endl; 
    ref2 = 5600; 
    std::cout << "modified value of ref2:" << ref2 << std::endl; 

    delete &ref2; 
}

/* 
    type(p1) == int* 
    type(*p1) == int 
    int& ref1 = *p1; 

    type(new int(100)) == int* 
    type(*(new int(100))) == int 

    int& ref = 

*/