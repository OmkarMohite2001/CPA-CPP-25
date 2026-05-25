#include <iostream> 
#include <typeinfo> 
#include <vector> 
#include <string> 

/* This program will trace the progression of types of template parameters */

/*  TYPE I : Template Non-Type Parameter - Can be integer can be string 
    template parameter  ->  Integral type 
    template argument   ->  Statically evaluable integer expression 
*/

template <int N> 
class Test1
{
    public: 
        Test1() 
        {
            std::cout << "In Test::Test():N" << N << std::endl; 
        }
}; 

/* 
    Type II:    Template Type Parameter 
    template parameter  :   a paramter whose annotation is keyword 'typename' 
    template argument   :   a concrete data-type -> one whose object can be readily crated 
                            this data type can also be obtained by instantiating existing class templates 
*/
template <typename T> 
class Test2 
{
    public: 
        Test2() 
        {
            std::cout << "Template Test2 Instantiated with type:" << typeid(T).name() << std::endl; 
        }
}; 


void test_non_type_parameter(); 
void test_type_parameter(); 

int main()
{
    test_non_type_parameter(); 
    test_type_parameter(); 
    return 0; 
}

void test_non_type_parameter() 
{
    Test1<100> t1; 
    Test1<200> t2; 
}

void test_type_parameter() 
{
    Test2<int> t1; 
    Test2<float> t2; 
    Test2<char*> t3; 
    Test2<std::vector<int>> t4;     // std::vector is an existing class template 
                                    //  We instantiate it by int to create a concrete class 
                                    //  std::vector<int> which is used to instantiate 
                                    //  class template Test2; 
}
