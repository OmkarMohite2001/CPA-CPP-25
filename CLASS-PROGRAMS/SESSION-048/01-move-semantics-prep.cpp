#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 

struct cpa_array 
{
    int* p_arr; 
    int N; 
}; 

struct cpa_array* allocate_array(int size); 
void release_cpa_array(struct cpa_array** pp_array); 
void set_array_element(struct cpa_array* p_array, int index, int data); 

int main()
{
    struct cpa_array* p1 = allocate_array(5); 
    for(int i = 0; i < 5; ++i)
        set_array_element(p1, i, (i+1)*100); 

    struct cpa_array* p2 = allocate_array(8); 
    for(int i = 0; i < 8; ++i)
        set_array_element(p2, i, (i+1)*1000); 

    struct cpa_array* p3 = allocate_array(0); 

    //  Case 1: p1 is transferring ownership of its array to p3 
    //          p3 is not owning anything right now 
    p3->p_arr = p1->p_arr; 
    p3->N = p1->N; 
    p1->p_arr = NULL; 
    p1->N = 0; 

    //  Case 2: p3 is transferring ownership if its array to p2 
    //          But p2 is already owning an array 

    //  p2 will give up ownership of its array 
    free(p2->p_arr); 
    p2->p_arr = NULL; 
    p2->N = 0; 

    //  Accept ownership from p3 
    p2->p_arr = p3->p_arr; 
    p2->N = p3->N; 

    //  p3 will release the ownership 
    p3->p_arr = NULL; 
    p3->N = 0; 

    release_cpa_array(&p1); 
    release_cpa_array(&p2);
    release_cpa_array(&p3); 

    return 0; 
}

struct cpa_array* allocate_array(int size)
{

    struct cpa_array* p_array = (struct cpa_array*)malloc(sizeof(struct cpa_array)); 
    if(0 == p_array)
    {
        puts("memory allocation error"); 
        exit(-1); 
    }
    p_array->p_arr = NULL; 
    p_array->N = 0; 

    if(size > 0)
    {
        p_array->p_arr = (int*)calloc(size, sizeof(int)); 
        if(0 == p_array->p_arr)
        {
            puts("memory allocation error"); 
            exit(-1); 
        }
        p_array->N = size; 
    }

    return p_array; 
}

void set_array_element(struct cpa_array* p_array, int index, int data)
{
    p_array->p_arr[index] = data; 
}

void release_cpa_array(struct cpa_array** pp_array)
{
    if(pp_array)
    {
        struct cpa_array* p = *pp_array; 
        if(p)
        {
            if(p->p_arr)
            {
                free(p->p_arr); 
                p->p_arr = NULL; 
                p->N = 0; 
            }

            free(p); 
            p = NULL; 
        }
        *pp_array = NULL; 
    }
}