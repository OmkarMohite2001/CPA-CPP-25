// the following syntax cannot be allowed 
const int num = 100; 

void test(void)
{
    num = 200; 
}

void test2(void)
{
    int num1 = 100; 
    const int num2 = 200; 

    num1 = 1000; 
    num2 = 2000; 
}