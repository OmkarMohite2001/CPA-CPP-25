#include <stdio.h> 
#include <stdlib.h> 

struct Date
{
    int day; 
    int month; 
    int year; 
}; 

void testFunctionOne(struct Date* pDate);   //  input by address  
struct Date* testFunctionTwo(void);         //  return by address 

void testFunctionThree(struct Date dateInstance);   // accept by value 
struct Date testeFunctionFour(void);                //  return by value 

int main(void)
{
    struct Date myDate = {29, 11, 2025}; 
    struct Date* pDate = NULL; 

    testFunctionOne(&myDate); 

    pDate = testFunctionTwo(); 

    return (0); 
}

void testFunctionOne(struct Date* pDate)
{
    //  print date using pDate
}

struct Date* testFunctionTwo() 
{
    //  Either return an instance of local static instance of struct Date 
    //  or return dynamically allocated instance of struct Date 

    //  1) Issue:   Not thread-safe (therefore no reentrant safe)
    //  2) Issue:   Documentation must specify that it is returning
    //              a dynamic instance of struct Date so that caller can 
    //              free it. 

    //  if returned by value then for large structure it may trigger a 
    //  prohibitive level of data movement 
    //  see the prototypes of : testFunctionThree(), testFunctionFour()
}

//  Single threaded application: 
// Program logic does not require  a new instance per call  
//  Option number 1: 
//  return type: struct Date* 
//  return value: address of local static instance of struct Date 
///////////////////////////////////////////////////

//  Multi-threaded application 
//  and/or
//  program logic requires a new instance of struct 
//  Option 2 
//  return type: struct Date* 
//  return value: address of dynamic instance of struct Date 

////////////////////////////////////////////////////////////////

//  Multithreaded application / Single threaded application 
//  I dont want caller to manage the release of dynamic instance 
//  size of structure is not prohiobilitively large 

//  return type: struct Date
//  return value: local non-static instance of struct Date 


struct Date testFunctionFour(void) 
{
    struct Date myDate; 

    //  myDate.day -> accepted from end user 
    //  myDate.month -> accepted from end user 
    //  myDate.year -> accepted from end user 

    return (myDate); 
}


void callerOf_testFunctionFour() 
{
    struct Date returnValue; 

    returnValue = testFunctionFour(); 
}

// refer to program number 04 