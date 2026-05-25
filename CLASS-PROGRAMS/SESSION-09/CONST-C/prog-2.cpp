#include <stdio.h> 

void test(void); 

int main(void) 
{
    test(); 
    return (0); 
}

void test(void)
{
    const int local_constant_num = 100; 
    int* ptr = NULL; 

    ptr = const_cast<int*>(&local_constant_num);  // WARNING 

    printf("BEFORE:local_constant_num = %d, *ptr = %d\n", 
        local_constant_num, *ptr);  // 100, 100
    
    *ptr = 200; 
    
    printf("AFTER:local_constant_num = %d, *ptr = %d\n", 
        local_constant_num, *ptr); // 100, 200
}