#include <iostream> 

int main(void)
{
    int n1 = 10; 
    int m1 = 0; 

    int n2 = 10; 
    int m2 = 0; 

    std::cout << "BEFORE:m1:" << m1 << ", n1:" << n1 << std::endl; 
    m1 = ++n1; 
    std::cout << "AFTER(m1 = ++n1;):m1:" << m1 << ", n1:" << n1 << std::endl; 

    std::cout << "BEFORE:m2:" << m2 << ", n2:" << n2 << std::endl; 
    m2 = n2++;  
    std::cout << "AFTER(m2 = n2++;):m2:" << m2 << ", n2:" << n2 << std::endl; 

    return (0); 
}

