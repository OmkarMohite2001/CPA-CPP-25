#include <iostream>
#include <functional>

void test(); 

int main()
{
    test(); 
    return 0; 
}

void test() 
{
    std::function<int(int, int)> func = [](int a, int b) -> int 
                                        {
                                            return a + b; 
                                        }; 

    int val = func(100, 200); 
    std::cout << "val:" << val << std::endl; // 300 
}

/* 
    namespace std 
    {
        template <typename T> 
        {
            private: 
                T* pfn; 
        }; 
    }

*/