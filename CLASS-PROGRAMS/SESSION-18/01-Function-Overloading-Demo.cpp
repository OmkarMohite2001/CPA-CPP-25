/* 
    Theory Part: 
        One Definition Rule: (Simplified Version): 
            There can only be one definition of any variable name in any given scope. 
            There can be more than one declaration but definition must be unique. 
*/

#include <iostream> 

void test(int, int); 
void test(int, float, int);
void test(int, const char*); 

int main(void)
{
    test(100, 200); 
    test(1000, 1.1f, 2000); 
    test(200, "Hello,World"); 

    return (0); 
}

void test(int a, int b)
{
    std::cout << "In test(int, int)" << std::endl; 
}

void test(int p, float q, int r)
{
    std::cout << "In test(int, float, int)" << std::endl; 
}

void test(int x, const char* msg)
{
    std::cout << "In test(int, const char*)" << std::endl; 
}
