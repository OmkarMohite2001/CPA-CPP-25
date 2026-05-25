#include <iostream> 
#include <memory> 

void test(); 

int main()
{
    test(); 
    return 0; 
}

void test() 
{
    std::shared_ptr<int> sp1 = std::shared_ptr<int>(new int(100)); 
    std::cout << sp1.use_count() << std::endl; 
}

