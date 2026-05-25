#include <stdio.h> 

void test() 
{
    int* p = NULL; 
    int num; 

    num = 100;

    char* s = "Hello"; 
}

/* 
    num = 100; 

    movl    $100, num 

    MOV-OPCODE  100     numaddr

    [PREFIX]    [OPCODE]    [MOD R/M]   [SIB]   [IMMEDIATE] [DISPLACEMENT]
    1 byte      1-3 byte    1 byte      1 byte  4 byte      4 byte 
*/

/* test.c */

int num; 

void test() 
{
    num = 100; 
}

//  # gcc -c -o test.o test.c 
//  # objdump -D test.o > test.disasm 
//  test.disasm  -> 0x64   0x00    0x00    0x00 