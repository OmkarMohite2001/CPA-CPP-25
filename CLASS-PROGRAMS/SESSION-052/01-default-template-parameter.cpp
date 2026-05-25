#include <iostream> 
#include <vector> 
#include <typeinfo> 

template <int N = 10> 
class Stack 
{
    private: 
        int* p; 
        size_t size; 
    public: 
        Stack() 
        {
            size = N; 
            p = new int[size]; 
        }

        ~Stack()
        {
            delete[] p; 
            p = 0; 
        }
}; 

void test_stack() 
{
    Stack<> S1;     //   Stack of 10 ints 
    Stack<100> S2;  //   Stack of 100 ints 

}

template <typename T1, typename T2 = int> 
class CT 
{
    public: 
        CT() 
        {
            std::cout << "typeid(T1).name():" << typeid(T1).name()
                    << std::endl; 
            std::cout << "typeid(T2).name():" << typeid(T2).name() 
                    << std::endl;  
        }
}; 

void test_CT() 
{
    CT<int> obj1; 
    CT<int, double> obj2; 
}

template <typename T, template <typename, typename> class TTP = CT> 
class CT2 
{

}; 

template <typename P, typename Q> 
class TestTemplate
{

}; 

void test_TTP() 
{
    CT2<int, TestTemplate> obj; 
}