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
            std::cout << "Entered Date::Date()" << std::endl; 
            std::cout << "Leaving Date::Date()" << std::endl; 
        }
}; 

int main(void)
{
    Date myDate1; 
    Date myDate2; 

    return 0; 
}