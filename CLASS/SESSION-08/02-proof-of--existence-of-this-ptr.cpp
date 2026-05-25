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

            std::cout << "Address of object:this:" << this << std::endl;

            std::cout << "Leaving Date::Date()" << std::endl;
        }
};

int main(void)
{
    Date myDate1;

    std::cout << "Address of myDate1 : " << &myDate1 << std::endl;

    Date myDate2;

    std::cout << "Address of myDate2 : " << &myDate2 << std::endl;
    return 0;

}