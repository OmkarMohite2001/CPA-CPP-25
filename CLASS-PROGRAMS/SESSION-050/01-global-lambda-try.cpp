#include <iostream> 

int v1 = 100, v2 = 200; 

auto result = [](int a, int b) -> int
        {
            return a + b; 
        }(v1, v2); 

class Date 
{
    public: 
        Date() 
        {
            std::cout << "Hello Date" << std::endl; 
        }
}; 

Date D; 

int main()
{
    std::cout << "Hello,World" << ", result:" << result << std::endl; 
    return 0; 
}