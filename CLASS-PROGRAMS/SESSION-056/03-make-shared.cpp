#include <iostream> 
#include <memory> 

namespace cpa 
{
    template <typename T, typename... Args> 
    std::shared_ptr<T> make_shared(Args&&... args) 
    {
        std::cout << "Apna Make Shared" << std::endl; 
        return std::shared_ptr<T>(new T(std::forward<Args>(args)...));     
    }
} 

class Date 
{
    private: 
        int day, month, year; 
    public: 
        Date(int _d, int _m, int _y) : day(_d), month(_m), year(_y) {} 
        void show() { std::cout << day << "/" << month << "/" << year << std::endl;}
}; 

void test(); 

int main() 
{
    test();
    return 0; 
}

void test() 
{
    std::shared_ptr<Date> sp1 = cpa::make_shared<Date>(12, 4, 2026); 
    std::shared_ptr<Date> sp2(sp1); 

    sp1->show(); 
    sp2->show(); 

    std::cout << "sp1.use_count():" << sp1.use_count() << std::endl; 
    std::cout << "sp2.use_count():" << sp2.use_count() << std::endl; 
}