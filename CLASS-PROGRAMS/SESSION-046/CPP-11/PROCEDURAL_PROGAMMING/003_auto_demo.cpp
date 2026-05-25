#include <iostream> 
#include <vector> 

class Date{
    private: 
        int day, month, year; 
    public: 
        Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy){
        }

        Date() : day(1), month(1), year(1970){
        }

        friend std::ostream& operator<<(std::ostream& os, const Date& obj){
            os << obj.day << "-" << obj.month << "-" << obj.year << std::endl; 
            return os; 
        }
}; 

auto x = 100;   // global variable 

/* This example will be covered after covering lambda extensions of C++ 11 */
template <typename T1, typename T2> 
auto func = [](T1 a, T2 b) -> decltype (a*b){
    decltype(a*b) val = a*b; 
    return val; 
}; 

void test_1(void); 
void test_2(void);

int main(void){
    std::cout << "main():enter" << std::endl; 
    test_1(); 
    test_2(); 
    auto rs = func<int, float>(45, 56.78); 
    std::cout << "rs=" << rs << std::endl; 
    std::cout << "main():leave" << std::endl; 
    return (0); 
}

void test_1(void){
    std::cout << "test_1():enter" << std::endl; 
    auto f = 1.1f; 
    auto d = 34553.345345; 
    auto D1 = Date();   
    auto D2 = Date(1, 1, 1970);  
    std::cout << "test_1():leave" << std::endl; 
}

void test_2(void){
    std::cout << "test_2():enter" << std::endl; 
    std::vector<int> ivec; 
    for(std::vector<int>::size_type i = 0; i != 5; ++i)
        ivec.push_back((i+1) * 100); 
    for(std::vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
        std::cout << "*iter=" << *iter << std::endl; 
    // Instead we can write 
    for(auto iter = ivec.begin(); iter != ivec.end(); ++iter)
        std::cout << "*iter=" << *iter << std::endl; 
    std::cout << "test_2():leave" << std::endl; 
}

/* 
    auto v = rhs; 
    is ROUGHLY EQUIVALENT
    decltype(rhs) v = rhs; 
*/

/*
class Process
{
    public: 
        typedef int pid_t; 
}; 

void f(Process::pid_t p)
{

}

template <typename T> 
class Process
{
    public: 
        typedef int pid_t; 
}; 

Process<int>::pid_t pid; 

namespace cpa 
{
    template <typename T> 
    class Process
    {
        public: 
            typedef int pid_t; 
    }; 
} 

cpa::Process<int>::pid_t pid; 

std::vector<int>::size_type i; 
*/
