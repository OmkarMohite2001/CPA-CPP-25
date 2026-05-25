#include <iostream> 

//  Pass by reference value 
void swap(int* p_num1, int* p_num2); 
//  Pass by reference 
void swap(int& refNum1, int& refNum2); 

int main(void)
{
    int m = 100, n = 200; 
    int p = 1000, q = 2000;
    
    std::cout << "Before Swap:m =" << m << ", n = " << n << std::endl; 
    swap(&m, &n); 
    std::cout << "After Swap(Pass by reference value version):m = " << m 
                << ", n = " << n << std::endl; 

    std::cout << "Before Swap:p =" << p << ", q = " << q << std::endl; 
    swap(p, q); 
    std::cout << "After Swap(Pass by reference version):p = " << p
                << ", q = " << q << std::endl; 

    return 0; 
}

void swap(int* p_num1, int* p_num2)
{
    int tmp; 
    
    // std::cout << "Pass by reference value version of swap()" << std::endl; 
    tmp = *p_num1; 
    *p_num1 = *p_num2; 
    *p_num2 = tmp; 
}

void swap(int& refNum1, int& refNum2)
{
    int tmp; 

    //std::cout << "Pass by referece version of swap()" << std::endl; 
    tmp = refNum1; 
    refNum1 = refNum2; 
    refNum2 = tmp; 
}