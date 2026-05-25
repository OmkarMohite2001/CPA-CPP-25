#include <iostream> 

void test(void); 

int main(void)
{
    test(); 
    return (0); 
}

void test(void)
{
    int num = 100; 
    int& ref = num; 

    printf("num = %d\n", num); 
    printf("ref = %d\n", ref); 

    ref = 500; 

    printf("num = %d\n", ref); 
    printf("&num = %p, &ref = %p\n", &num, &ref); 
}