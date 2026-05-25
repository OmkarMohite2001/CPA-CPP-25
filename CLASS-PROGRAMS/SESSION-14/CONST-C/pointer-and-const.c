#include <stdio.h> 
#include <stdlib.h> 

/* 
    Pointer:    int* p = NULL;   // variable p is a pointer 

    int num_1; 
    p = &num_1; // variable p is a pointer, num_1 is a pointee 
                // because address of variable num_1 is stored in p 

    int num_2; 
    p = &num_2; // variable p is a pointer and num_2 is a pointee 
                // because address of variable num_2 is stored in p 

    p = (int*)malloc(sizeof(int)); 

    // variable p is a pointer 
    // integer variable allocated on heap section by malloc() function 
    // is a pointee because its address is returned by malloc() and 
    // stored pointer p. 
*/

void pointer_to_const_demo(void); 
void const_pointer_demo(void); 
void const_pointer_to_pointer_to_const_demo(void); 

int main(void)
{
    pointer_to_const_demo(); 
    const_pointer_demo(); 
    const_pointer_to_pointer_to_const_demo(); 

    return (0); 
}

void pointer_to_const_demo(void)
{
    int num = 10;   // local data definition statement
                    // allocates local integer on the stack frame 

    const int* p = &num;    // local data definition statement 
                            // allocates pointer p on the stack frame 
                            // stores the address of local integer 
                            // which is allocated on the same stack frame 

    //  Declaration reading: p is a pointer to const int 
    //  In this syntax, the pointer variable itself is not constant 
    //  meaning that we can reassign p to point to some other integer 
    //  than num. 

    //  But the pointee is treated as const. Therefore, it is not allowed 
    //  to use expression *p on LHS. If we do so, we will be greeted with 
    //  the following error. 
    // *p = 500;   // CTE: LHS must a MODIFIALBE LVALUE. 

    printf("num = %d\n", num);  // 10 
    num = 500; 
    printf("num = %d\n", num);  // 500 

    /* 
        You can put address of non-const integer, 
        semantically const integer or 
        actual const integer in pointer to const 

        // global scope 
        int num1 = 100;         // data section R/W (non-const)
        int num2;               // BSS section R/W  (non-const)
        const int num3 = 200;   // RODATA section Read only (const)

        void test(void)
        {
            int num4 = 300;         // STACK R/W    (non-const)
            int num5;               // STACK R/W    (non-const)
            const int num6 = 400;   // STACK R/W    (semantically const)
                                    // Read only if accessed through variable named num6 
                                    // But backdoor will work 
            static const int num7 = 500;    // RODATA Read only 

            const int* p;   // p itself is not const, therefore, pointer to const can be left 
                            // unintialized

            p = &num1; 
            p = &num2; 
            p = &num3; 
            p = &num4; 
            p = &num5; 
            p = &num6; 
            p = &num7;   
        }
    */
}

void const_pointer_demo(void)
{
    /* 
        In this function we want to attach constness to 
        pointer variable itself so that it cannot point 
        any other memory location than what is set 
        at the time of initialization 

        int num;                // non-const integer 
        const int cnum = 10;    // const integer
        
        // Declaration reading 
        // p1 is a CONST POINTER to int 
        // initialized to the base address of num 
        int* const p1 = &num; 

        p1 = &num2;     // CTE: expression must be a modifiable l-value
        int* const p2 = &cnum; 
        int* p = &cnum; 

    */
}

void const_pointer_to_pointer_to_const_demo(void)
{
    int num = 10; 

    const int* const p = &num; 

    int num2; 
    // p = &num2;  // CTE 
    // *p = 20;    // CTE 
}

/* 

int num1 = 100; // data 
int num2; // bss 
const int gc_num = 200; // rodata  

void test(void)
{
    int num3 = 300;     // stack 
    int num4;           // stack 

    const int lc_num = 500;     // stack 

    static const int lc_num_2 = 600; // rodata 

    int* p = &num1;     // Compile & Run : OKAY 
    p = &num2 ;         // Compile & Run : OKAY 
    p = &num3;          // Compile & Run : OKAY 
    p = &num4;          // Compile & Run : OKAY 

    p = &gc_num;        // Compile: Warning: Discarding const 
    *p = 500;            // Run : Segmentation Fault (if write on pointee is attmpeted)

    p = &lc_num_2;      // Compile: Warning: Discarding const 
    *p = 500;           // Run : Segmentation Fault (if write on pointee is attmpeted)

    p = &lc_num;        // Compile: Warning: Discarding const 
    *p = 500;           // Run: OKAY (even if write on pointee is attmpeted)   
}

int n; 

int* p;                     // NON-CONST POINTER TO NON-CONST INT
const int* p;               // NON-CONST POINTER TO CONST INT 
int* const p = &n;          // CONST POINTER TO NON-CONST INT 
const int* const p = &n;    // CONST POINTER TO CONST INT 

COMPILE TIME WARNING 
POINTER TO NON-CONST INT  = ADDRESS OF CONST MEMORY BLOCK (ADDRESS OF CONST INT)

*(POINTER TO NON-CONST INT CONTAINING CONST DECLARED POINTEE)

CONST POINTEE = HARDWARE PROTECTED CONST;   // RUN TIME SEGFAULT 
CONST POINTEE = SEMANTICALLY CONST;         // WORK 

DIFFERENCE IN C/C++: 

POINTER TO NON-CONST INT  = ADDRESS OF CONST MEMORY BLOCK (ADDRESS OF CONST INT)

// C Compiler issues warning and discards const of pointee on its own (implicitly)
// C++ Compiler issues an error: 
    const T* (RHS type) cannot be implicitly (on its own) T*(LHS TYPE)

    const int cnum = 100; 

    int* p = (int*)&cnum; // EXPLITICT TYPE CASTING SYNTAX OF C LANG (WILL WORK IN C++ AS WELL DUE TO BACKWARD COMPATIBILTY)

    int* p = const_cast<int*>(&cnum); // EXPLICIT TYPE CASTING OF C++ LANG (C++ SPECIFIC SYNTAX)
*/

