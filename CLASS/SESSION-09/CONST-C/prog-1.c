#include <stdio.h>

//  global initialized data definition statement (read/write)
int g_num1 = 10;

//  global uninitialized data definition statement (read/write)
int g_num2;

//  global uninitialized data definition statement (read/write)
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
    g_num1 = 1000;  //ok
    g_num2 = 2000;  //ok

    //  c_num = 200;    //  compile time error 
                        //  LHS must be a modifiable value 
                        //  c_num is an lvalue but not modifiable one 
                        //  due to const qualifier
    //  Inference: const variable cannot be midified accessing by name

    //  Attempt to create a pointer back-door
    int* ptr = &c_num;  //  Succeed in C
                        //  C compiler emits a warning that it's discarding
                        //  const qualifiers but allows this assignment

    //*ptr = 200;       //  Run-Time error (segfault an Linux/Macos )
                        //  Memory violation exception on windows
                        //  global const variable goes to the read only
                        //  data section which is protected by h/w
}               

void test_2(void)
{
    //  Define a read/write local variable
    int num;

    //  Define a local const variable
    //  such a variable is semantically const!
    //  meaning that it's constness will be preserved if one tries to 
    //  access it by name , but pointer backdoor will succeed for it
    const int c_num1 = 100;

    //  c_num1 = 200;               //  compile time error 
                                    //  LHS must be a modifiable value 

    //  create a pointer back-door
    int* ptr = &c_num1;             //  Compiler warning that its discarding a const
                                    //  qualifier for c_num1
    *ptr = 200;                     //  this will work  because the const  qualifier has not
                                    //  changed storage section of c_num1 which is a stack.
                                    //  stack is a read/write section. Therefore, this back-door works.
                                    //  talk about symantically const variable : p

    static const int c_num2 = 200;  //  compiler warning: that it's discarding a const 
                                    //  qualifier for c_num2

    //*ptr = 2000;                  //  Run-time error (segfault on Linux/MacOS)
                                    //  Memory violation exception on windows 
                                    //  static const int c_num2 = 2000;
                                    //  const qualifier express a wish that this variable
                                    //  be const.  It will be symantically const at the very least.
                                    //  but static keyword pushesh memory allocation
                                    //  of c_num2 to a static section.
                                    //  As read only data section is a static section, there
                                    //  is an oppurtunity to make this variable h/w protected
                                    //  const. c++ compiler ceases the opportunity and puts in 
                                    //  rodata section. Therefore the run time.
}