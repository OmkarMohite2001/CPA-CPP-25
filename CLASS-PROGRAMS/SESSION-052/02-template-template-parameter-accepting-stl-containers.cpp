#include <iostream> 
#include <typeinfo> 
#include <string> 
#include <vector> 
#include <deque> 
#include <forward_list>
#include <list> 

template <typename INST_TYPE, template <typename T, typename allocator = std::allocator<T>> class TTP> 
class TestClass 
{
    public: 
        TestClass() 
        {
            std::cout << "typeid(TTP<INST_TYPE>).name():" << typeid(TTP<INST_TYPE>).name() << std::endl;  

            TTP<int> myObj1; 
            TTP<double> myObj2; 
            TTP<INST_TYPE> myObj3; 
        }
}; 

void test(); 

int main()
{
    test(); 
    return 0; 
}

void test() 
{
    TestClass<int, std::vector> t1; 
    TestClass<double, std::list> t2; 
    TestClass<std::string, std::deque> t3; 
    TestClass<short, std::forward_list> t4; 
}
