void test(void)
{
    int num = 10; 

    const int& ref1 = num; 
    const int& ref2 = 400; 

    int& ref = ref1;    // would work if we wanted to make it work 
    int& ref = ref2;    // wont work
    
    //  therefore general rule: 
    //  non-const reference variable of type T will not 
    //  accept const reference variable of type T as its initializer 

    int n1 = ref1; //   int n1 = num; 
    int n2 = ref2; //   int n2 = 400; 
}

/* 
    const char* msg = "Yogeshwar"; 

    .section .rodata 

    .LC0: 
    .string "Yogeshwar"

    .section .data 

    .globl  msg 
    .type   msg, @object
    .size   msg, 4  
    .align  4
    msg: 
    .int    .LC0 
    
    .section .text 

    movl    msg, %eax   

    *(msg + i)

    movl    msg, %ebx 
    movl    i, %eax 
    movb    (%ebx, %eax, 1), %dl

*/