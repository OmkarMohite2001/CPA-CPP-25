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
}; 

int main(void)
{
    Date myDate(5, 10, 2025); 
    Date myExamDate(5, 12, 2025); 
    Date myBirthDate(3, 1, 1975); 
    Date epochDate(1, 1, 1970); 

    return 0; 
}