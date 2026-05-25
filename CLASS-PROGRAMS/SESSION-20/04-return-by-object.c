#include <stdio.h> 

struct Date { int day, month, year; }; 

void testFunc(int _day, int _month, int _year); 

struct Date getDateInstance(int _day, int _month, int _year); 

int main(void) 
{
    int i, j; 
    struct Date myDate; 

    testFunc(100, 200, 300); 

    myDate = getDateInstance(29, 11, 2025); 
    // transfer tmpObject -> myDate  
    printf("myDate:%d/%d/%d\n", myDate.day, myDate.month, myDate.year); 
    // Further required variables i and j 

    return (0); 
}

struct Date getDateInstance(int dd, int mm, int yy)
{
    struct Date myInstance; 
    
    //  myInstance.day / .month / .year -> accepted from end user 

    //  statement 

    //  transfer -> myInstance -> tmp object of caller -
    //  address of tmp object of caller is available on your stak frame 


    myInstance.day = 29; 
    myInstance.month = 11; 
    myInstance.year = 2025; 

    return myInstance; 
}

void testFunc(int aa, int bb, int cc)
{
    printf("%d, %d, %d\n", aa, bb, cc); 
}