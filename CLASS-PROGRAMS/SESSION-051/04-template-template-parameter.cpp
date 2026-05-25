#include <iostream> 
#include <typeinfo> 
#include <vector> 

/* Define class template 1 with two type parameters */

template <typename T1, typename T2> 
class CT1 
{
    public: 
        CT1() 
        {
            std::cout << "Class Template CT1 instantiated by " << typeid(T1).name() 
                        << " and " << typeid(T2).name() << std::endl; 
        }
}; 

template <typename T3, typename T4> 
class CT2 
{
    public: 
        CT2() 
        {
            std::cout << "Class Template CT2 instantiated by " << typeid(T3).name() 
                        << " and " << typeid(T4).name() << std::endl; 
        }
}; 

template <typename P, typename Q> 
class CT3
{
    public: 
        CT3() 
        {
            std::cout << "Class Template CT3 instantiated by " << typeid(P).name() 
                        << " and " << typeid(Q).name() << std::endl; 
        }
}; 

template <int N, template <typename, typename>  class TTP>
class MCT
{
    public: 
        MCT() 
        {
            std::cout << "N:" << N << std::endl; 
            TTP<int, double> Obj; 
        }
}; 

void template_template_parameter(); 

int main()
{
    template_template_parameter(); 
    return 0; 
}

void template_template_parameter() 
{
    MCT<100, CT1> mct_obj1; 
    MCT<200, CT2> mct_obj2; 
    MCT<300, CT3> mct_obj3; 
}


