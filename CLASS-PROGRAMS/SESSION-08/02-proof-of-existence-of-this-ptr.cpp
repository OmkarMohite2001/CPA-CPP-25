#include <iostream> 

class Date
{
    private: 
        int day; 
        int month; 
        int year; 
    public: 
        Date()
        {
            std::cout << "Date::Date():Entered" << std::endl; 
            std::cout << "Date::Date():Address of object:this:" << this << std::endl;  
            std::cout << "Date::Date():Leaving" << std::endl;  
        }
}; 

int main(void)
{
    Date myDate1; 
    std::cout << "main():Address of myDate1:" << &myDate1 << std::endl; 

    Date myDate2; 
    std::cout << "main():Address of myDate2:" << &myDate2 << std::endl; 

    return 0; 
}