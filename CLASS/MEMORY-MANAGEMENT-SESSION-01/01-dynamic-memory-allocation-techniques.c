#include <stdio.h>  //  for declaration of printf()
#include <stdlib.h> //  for declaration of malloc(),    free(), exit()
#include <string.h> //  for declaratioon of memset()

struct Date
{
    int dat;
    int month;
    int year;
};

struct array 
{
    int* a;
    int N;
};

void dynamic_builtinin(void);
void dynamic_user_defined_date(void);
void dynamic_user_defined_array(void);

int main(void)
{
    dynamic_builtinin();
    dynamic_user_defined_array();
    dynamic_user_defined_date();

    return 0;
}
void dynamic_builtinin(void)
{
    //  step 1 : Declare a pointer and initialize it ti NULL
    int* ptr = NULL;

    //  step 2 : Allocate dynamic memory using malloc() and
    //           do the validateion check

    ptr = (int*)malloc(sizeof(int));
    if(ptr == NULL)
    {
        puts("*out of memory");
        exit(EXIT_FAILURE);
    }

    //  step 3 : Initialize allocated instance to 0

    memset(ptr,0,sizeof(int));

    //  step 4 :    Read/Write an dynamically allocateed instance
    *ptr = 100;     //  write operation
    int n = *ptr;   //  read operation
    printf("*ptr = %d\n",*ptr);

    //  step 6 :    when dynamic instance is no longer wanted
    //              release it and make pointer NULL

    free(ptr);
    ptr = NULL;
}

void dynamic_user_defined_date(void)
{
    //  step 1
    struct Date* newDate = NULL;

    //  step 2

    newDate = (struct Date*) malloc (sizeof(struct Date));
    if(newDate == NULL)
    {
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }
    //  step 3
    memset(newDate,0,sizeof(struct Date));

    //  step 4/5

    newDate->dat = 26;
    newDate->month = 05;
    newDate-> year = 2026;

    printf("%d/%d/%d\n",newDate->dat,newDate->month,newDate->year);

    //  step 6
    free(newDate);
    newDate = NULL;
}
void dynamic_user_defined_array(void)
{
    struct array* p_array = NULL;
    p_array = (struct array*)malloc(sizeof(struct array));

    if(NULL == p_array)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }
    p_array->N = 8;
    p_array->a = (int*)malloc(p_array->N * sizeof(int));

    if(NULL == p_array->a)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    int i;
    for(i = 0; i < p_array->N; ++i)
    {
        p_array->a[i] = (i + 1) * 10;
    }
    puts("showing array : ");
    for(i = 0; i < p_array->N; ++i)
    {
        printf("p_array->a [%d] : %d\n",i,p_array->a[i]);
    }

    free(p_array->a);
    p_array->a = NULL;

    free(p_array);
    p_array = NULL;
}