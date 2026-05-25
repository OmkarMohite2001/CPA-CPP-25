#include <iostream> 
#include <typeinfo>

void print_types() 
{
}

template <typename T, typename... Args> 
void print_types(T first, Args... rest) 
{
    std::cout << "type:" << typeid(T).name() << std::endl; 
    if(sizeof...(rest) > 0)
        print_types(rest...); 
}

int main()
{
    print_types(1.0, 100, 'a', 3.2f); 
    return 0; 
}