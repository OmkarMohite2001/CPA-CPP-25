#include <iostream> 

void test1(void); 
void test2(std::initializer_list<int> i_list); 

int main(void)
{
    test1(); 
    test2({100, 200, 300, 400}); 
    return (0); 
}

void test1(void)
{
    std::cout << "test1():Entered" << std::endl; 
    std::initializer_list<int> i_list{100, 200, 300, 400}; 

    for(
        std::initializer_list<int>::iterator iter = i_list.begin(); 
        iter != i_list.end(); 
        ++iter
    )
        std::cout << "*iter =" << *iter << std::endl; 
    
    std::cout << "test1():Leaving" << std::endl; 
}

void test2(std::initializer_list<int> i_list)
{
     std::cout << "test2():Entered" << std::endl; 
     for(
        std::initializer_list<int>::iterator iter = i_list.begin(); 
        iter != i_list.end(); 
        ++iter
    )
        std::cout << "*iter =" << *iter << std::endl; 

    std::cout << "test2():Leaving" << std::endl; 
}