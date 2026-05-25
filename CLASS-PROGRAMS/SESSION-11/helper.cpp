#include <iostream> 

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 

    public: 
        Date(int _d, int _m, int _y)
        {
            day = _d; 
            month = _m; 
            year = _y; 
        }

        Date() 
        {
            day = 1; 
            month = 1; 
            year = 1970; 
        }
}; 

Date myDate1(26, 10, 2025);     // Global initialized data definition statement 
                                // memory allocation : static, BSS

Date myDate2;   // Global uninitialzied DDS 
                // memory allocatoin : static, BSS 

const Date myDate3(17, 10, 2026);   // READ ONLY DATA SECTION 

void test(void)
{
    Date myDate4;                           // STACK 
    static Date myDate5;                    // BSS 
    static Date myDate6(26, 10, 2026);      // BSS 
    static const Date myDate7(27, 6, 1999); // RODATA 

    Date* pDate = new Date(1, 1, 1980);     // HEAP 
}

////////////////////////////////////////
// INITIALIZATION 
// int num = 10; 

//.section .data 
//    num: 
//    .int    10 
////////////////////////////////////////
//int num; 

//void test(void)
//{
//    num = 10;     // ASSIGNMENT 
//}
////////////////////////////////////////
//.section .bss 
//    .comm   num, 4, 4 

//.section .text
//.globl test 
//test: 
//   movl $10, num 
////////////////////////////////////////

class T 
{
    // non-static DDS
    // static DDS 
    // non static functions 
    // static functions 
    // enums 
    // typedefs 
    // inner classes 
}; 

class X 
{
    private: 
        int num; 
        static int x; 
        void f()
        {

        }
    protected: 
        int num2; 
        static int y; 
        static int func(int p, int q)
        {

        }
    public:
        int num3; 
        static int z; 
}; 

X objX; 

struct X 
{
    int num; 
    int num2; 
    int num3; 
}; 