#include<stdio.h>

//Project wide global variable 
int global_num = 100;

//file wide or translation unit wide global variable 
static int s_num = 200;

//Project wide global function
void test_function(void)
{
    printf("Entered test_function() in file: %s\n",__FILE__);
    printf("global_num = %d , s_num = %d\n",global_num,s_num);
    test_function_2();
    printf("Leaving Test Function()\n");

}

//File wide or Translation unit wide global function
static void test_function_02(void)
{
    printf("Entered test_function_2() which is static in file %s\n",__FILE__);
    printf("Leaving test_function_2() which is static");
}