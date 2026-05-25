#include <stdio.h> 

// global initialized data definition statement (read/write)
int g_num_1 = 10; 

// global uninitialized data definition statement (read/write)
int g_num_2; 

//  global const data definition statement 
//  data definition statements qualified by the keyword const must 
//  be initialized 
const int c_num = 100; 

void test_1(void); 
void test_2(void); 

int main(void)
{
    test_1();
    test_2();

    return (0); 
}

void test_1(void)
{
    g_num_1 = 1000;     // ok 
    g_num_2 = 2000;     // ok 
    // c_num = 200;     // compile time error 
                        // LHS must be a modifiable lvalue 
                        // c_num is an lvalue but not modifiable one 
                        // due to const qualifier 
    // Inference: const variable cannot be modified accessing by name 

    //  Attempt to create a pointer back-door 
    int* ptr = &c_num;  //  Succeeds in C 
                        //  C compiler emits a warning that its discarding 
                        //  const qualifier but allows this assignment

    //*ptr = 200;       //  Run-time error (segfault on Linux/MacOS)
                        //  Memory violation exception on windows 
                        //  global const variable goes to the read only 
                        //  data section which is protected by h/w
}

void test_2(void)
{
    //  define a read/write local variable 
    int num; 

    //  Define a local const variable. 
    //  Such variable is semantically const!
    //  Meaning that its constness will be preserved if one tries to 
    //  access it by name, but pointer backdoor will succeed for it 
    const int c_num_1 = 100; 

    // c_num_1 = 200;           //  Compile time error 
                                //  LHS must be a modifiable lvalue 

    //  Create a pointer back-door 
    int* ptr = &c_num_1;        //  Compiler warning: that its discarding a const 
                                //  qualifier for c_num_1 
    *ptr = 200;                 //  This will work because the const qualifier has not 
                                //  changed the storage section of c_num_1 which is a stack.
                                //  stack is a read/write section. Therefore, this back-door works.
                                //  Talk about semantically const variable :-P
    
    static const int c_num_2 = 200; 

    // c_num_2 = 2000;          //  Compile time error 
                                //  LHS must be a modifiable lvalue 

    //  Create a pointer back door 
    ptr = &c_num_2;             //  Compiler warning: that its discarding a const 
                                //  qualifier for c_num_2 

    //*ptr = 2000;              //  Run-time error (segfault on Linux/MacOS)
                                //  Memory violation exception on windows 
                                //  static const int c_num_2 = 2000; 
                                //  const qualifier expresses a wish that this variable 
                                //  be const. It will be semantically const at the very 
                                //  least. But static keyword pushes memory allocation 
                                //  of c_num_2 to a static section. 
                                //  As read only data section is a static section, there
                                //  is an opportunity to make this variable h/w protected 
                                //  const. C++ compiler ceases the opportunity and puts in 
                                //  rodata section. Therefore the run-time error. 
}

/* 
void test()
{
    int num1 = 10;  // stack 
    int num2;       // stack 
    const int num3 = 30;    // stack 
}

void test()
{
    static int num1 = 10;  // data 
    static int num2;       // bss  
    static const int num3 = 30;    // rodata 
}
*/