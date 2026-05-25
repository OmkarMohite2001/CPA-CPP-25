#include <iostream> 
#include <cstdio> 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

void testFunctionOne(const struct Date* pDate); 
void testFunctionTwo(const struct Date& refDate); 

int main(void) 
{
    struct Date myDate = {29, 11, 2025}; 

    testFunctionOne(&myDate); 
    testFunctionTwo(myDate); 

    return (0); 
}

void testFunctionOne(const struct Date* pDate)
{
    //  Read access allowed 
    printf("testFunctionOne():Input Date Object: %d/%d/%d\n", pDate->day, pDate->month, pDate->year); 
    //  pDate->day = 25; // Write access denied 
}

void testFunctionTwo(const struct Date& refDate)
{
    //  Read access allowed 
    printf("testFunctionTwo():Input Date Object: %d/%d/%d\n", refDate.day, refDate.month, refDate.year); 
    //  refDate.day = 25;   // Write access denied       
}

