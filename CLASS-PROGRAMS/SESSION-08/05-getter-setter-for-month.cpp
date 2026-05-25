#include <iostream> 

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 

    public: 
        Date(int init_day, int init_month, int init_year) 
        {
            this->day = init_day; 
            this->month = init_month; 
            this->year = init_year; 
        }

        int get_month() 
        {
            return this->month; 
        }

        void set_month(int new_month)
        {
            this->month = new_month; 
        }
};

int main(void)
{
    Date myDate(5, 10, 2025); 
    int day; 
    
    day = myDate.get_month(); // Date::get_month(&myDate); 
    
    myDate.set_month(12); // Date::set_month(&myDate, 12)

    day = myDate.get_month(); // Date::get_month(&myDate); 
    
    return 0; 
}

