#include <stdio.h>

void test_function(void);

int main(void)
{
    int i;
    for(i = 0;i<5;i++)
    {
        test_function();
    }
    return 0;
}
void test_function(void)
{
    int local_num = 0;
    static int static_num = 0;
    int counter;

    printf("Entered test_function()\n ");
    printf("test_function(): initial state : local_num = %d, static_num = %d \n",local_num,static_num);

    for(counter = 0; counter < 3 ; ++counter)
    {
        local_num = local_num + 2;
        static_num = static_num +2;
    }

    printf("test_function(): Final state at the time of leaving the function:local_num = %d, static_num = %d\n",static_num,local_num);
    printf("Leaving test_function()\n");
}

//comments : static variable applied to local data defination statements makes changes in the following:
//  1)Time of allocation 
//  2)Frequency of allocation
//  3)Storage section
//  4)Life-time

//      Local variable      local static variable
//  1)  dynamic             static
//  2)  per function call   once
//  3)  stack               data/bss
//  4)  function call       program

//  Use Case
//  Two ways to look at it
//  1)  If You want to create a local variable which retains it's state access multiple calls to the function
//      then you can make use of local static variable
//  2)  Local static variable provides a shared space for communnication across multiple calls of the same function.
//      (Unique point view!)(Inner-instance communication)