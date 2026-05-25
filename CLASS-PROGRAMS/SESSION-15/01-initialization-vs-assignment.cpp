/* 
    .section .data 
        num1: 
        .int    10 
*/

int num1 = 10;  // initialization syntax (memory allocation + setting initial value)

/* 
    .section .bss 
        .comm num2, 4, 4 
*/
int num2;       // Memory allocation 

void test(void)
{
    // movl $20, num 
    num2 = 20;  // setting initial value 
    
    int num3 = 30;  // initialization syntax (memory allocation + setting initial value)
    int num4;       // memory allocation 

    num4 = 40;      // setting initial value 
}

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

struct Date myDate = {9, 11, 2025}; 
struct Date examDate; 

void test2(void)
{
    examDate.day = 15; 
    examDate.month = 12; 
    examDate.year = 2025; 
}

class Date
{
    private: 
        int day;
        int month; 
        int year; 
    public: 
        Date(int dd, int mm, int yy){} 
}; 

Date myDate1(9, 11, 2025); 
Date examDate1; 

void test3(void)
{
    examDate1.day = 15; // ERROR due to private protection 
}