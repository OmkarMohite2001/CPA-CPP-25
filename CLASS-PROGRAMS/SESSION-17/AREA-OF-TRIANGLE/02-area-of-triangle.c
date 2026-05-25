#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define SUCCESS                     1 
#define TR_INVALID_SIDE_LENGTH      -1 
#define TR_INVALID_SIDE_COMBINATION -2 

typedef double side_t; 
typedef double perimeter_t; 
typedef double semi_perimeter_t; 
typedef double area_t; 
typedef struct triangle triangle_t; 
typedef int status_t;

struct triangle
{
    side_t s1, s2, s3; 
}; 

triangle_t* allocate_new_triangle(side_t s1, side_t s2, side_t s3, status_t* p_status); 

perimeter_t get_perimeter(triangle_t* p_triangle); 
semi_perimeter_t get_semi_perimeter(triangle_t* p_triangle); 
area_t get_area(triangle_t* p_triangle); 

void destroy_triangle(triangle_t** pp_triangle);

static status_t check_triangle_sides(side_t s1, side_t s2, side_t s3); 

//--------------------------------CLIENT CODE - START--------------------------------
void test_triangle(void); 

int main(void)
{
    test_triangle(); 
    return (EXIT_SUCCESS); 
}

void test_triangle(void)
{

}
//--------------------------------CLIENT CODE - END--------------------------------

triangle_t* allocate_new_triangle(side_t s1, side_t s2, side_t s3, status_t* p_status)
{
    triangle_t* p_new_triangle = NULL; 

    *p_status = check_triangle_sides(s1, s2, s3); 
    if(*p_status != SUCCESS)
        return (NULL); 

    p_new_triangle = (triangle_t*)malloc(sizeof(triangle_t)); 
    if(NULL == p_new_triangle)
    {
        fprintf(stderr, "malloc():fatal:out of memory, exiting...\n"); 
        exit(EXIT_FAILURE); 
    }

    p_new_triangle->s1 = s1; 
    p_new_triangle->s2 = s2; 
    p_new_triangle->s3 = s3; 

    return (p_new_triangle); 
}

perimeter_t get_perimeter(triangle_t* p_triangle)
{
    if(NULL == p_triangle)
    {
        fprintf(stderr, "get_perimeter():invalid triangle, exiting...\n"); 
        exit(EXIT_SUCCESS); 
    }

    return (p_triangle->s1 + p_triangle->s2 + p_triangle->s3); 
}

semi_perimeter_t get_semi_perimeter(triangle_t* p_triangle)
{
    if(NULL == p_triangle)
    {
        fprintf(stderr, "get_semi_perimeter():invalid triangle, exiting...\n"); 
        exit(EXIT_SUCCESS); 
    }
    
    return ((p_triangle->s1 + p_triangle->s2 + p_triangle->s3) / 2.0); 
}

area_t get_area(triangle_t* p_triangle)
{
    semi_perimeter_t s; 
    
    if(NULL == p_triangle)
    {
        fprintf(stderr, "get_area():invalid triangle, exiting...\n"); 
        exit(EXIT_SUCCESS); 
    }

    s = get_semi_perimeter(p_triangle); 
    return (sqrt(s * (s - p_triangle->s1) * (s - p_triangle->s2) * (s - p_triangle->s3))); 
}

void destroy_triangle(triangle_t** pp_triangle)
{
    if(NULL == pp_triangle || NULL == *pp_triangle)
    {
        fprintf(stderr, "destroy_triangle():invalid triangle, exiting...\n"); 
        exit(EXIT_SUCCESS); 
    }

    free(*pp_triangle); 
    *pp_triangle = NULL; 
}

static status_t check_triangle_sides(side_t s1, side_t s2, side_t s3)
{
    if(s1 <= 0.0 || s2 <= 0.0 || s3 <= 0.0)
        return (TR_INVALID_SIDE_LENGTH); 

    if((s1 + s2 <= s3) || (s2 + s3 <= s1) || (s3 + s1 <= s2))
        return (TR_INVALID_SIDE_COMBINATION); 

    return (SUCCESS); 
}