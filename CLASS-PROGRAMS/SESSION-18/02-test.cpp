#include <iostream> 

void test(int, short); 
void test(short, int); 
void test(int, int); 

int main(void)
{
    test(1, 1); 
    return (0); 
}

void test(int a, short b)
{
    std::cout << "In test(int, short)" << std::endl; 
} 

void test(short p, int q)
{
    std::cout << "In test(short, int)" << std::endl; 
} 

void test(int a, int b)
{
    std::cout << "In test(int, int)" << std::endl;
}