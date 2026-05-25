#include <iostream> 

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 

    public: 
        Date(int init_day, int init_month, int init_year) : day(init_day), 
                                                            month(init_month), 
                                                            year(init_year)
        {

        }

        int get_day() const 
        {
            return this->day; 
        }

        int get_month() const 
        {
            return this->month; 
        }

        int get_year() const 
        {
            return this->year; 
        }

        void show() const 
        {
            std::cout << day << "/" << month << "/" << year << std::endl; 
        }

        void set_day(int new_day)
        {
            day = new_day; 
        }

        void set_month(int new_month)
        {
            month = new_month; 
        }

        void set_year(int new_year)
        {
            year = new_year; 
        }
}; 

int main(void)
{
    //  normal client code of Date 

    return 0; 
}