#include <iostream> 

int     testFunctionOne(void); 
int*    testFunctionTwo(void);
int&    testFunctionThree(void); 
int&    testFunctionFour(void); 
void    test(void); 

int main(void)
{
    test(); 
    return 0;     
}

void test(void)
{
    int returnValue; 
    int* pRet; 

    returnValue = testFunctionOne(); 
    printf("Return Value of testFunctionOne() = %d\n", returnValue); 

    pRet = testFunctionTwo(); 
    printf("Data returned by testFunctionTwo() = %d\n", *pRet); 
    //  pRet need not be free because testFunctionTwo() return the 
    //  address of local static variable and not dynamically allocated integer 

    int& ref1 = testFunctionThree(); 
    printf("Data returned by testFunctionThree() = %d\n", ref1); 
    //  We need not delete &ref1 because testFunctionThree() returns the 
    //  reference to local static integer and not dynamically allocated integer 

    int& ref2 = testFunctionFour(); 
    printf("Data returned by testFunctionFour() = %d\n", ref2); 
    //  We need to delete &ref2 because testFuntionFour() returns the dynamically 
    //  allocated integer variable 
    delete &ref2; 
}

int testFunctionOne(void)
{
    int num = 100; 
    return num; 
}

int* testFunctionTwo(void)
{
    static int num = 200; 
    return &num; 
}

int& testFunctionThree(void)
{
    static int num = 500; 
    return num; 
} 

int& testFunctionFour(void)
{
    int* p = new int(600); 
    return *p; 
}

/* 

    v = myFunc();
    
    Desired type of v should be the return type annotation of myFunc()
*/

