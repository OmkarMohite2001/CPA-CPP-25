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
            this->day = 500; 
            return this->day; 
        }

        int get_month() 
        {
            return this->month; 
        }

        int get_year() 
        {
            return this->year; 
        }

        void show() 
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
    const Date* pDate = new Date(9, 11, 2025); 

    // pDate->day = 15;     // CTE 
    // pDate->month = 12;   // CTE 
    // pDate->year = 2026;  // CTE 

    pDate->get_day();   // Date::get_day(pDate); 
                        // type(this pointer of get_day) == const Date*
                        // type(pDate) == const Date* 
                        // MATCH OKAY 
 
    Date* pDate_1 = new Date(9, 11, 2025); 
    pDate_1->get_day(); // Date::get_day(pDate_1)
                        // type(this pointer of get_day) == const Date* 
                        // type(pDate_1) == Date*
                        // MATCH OKAY 

    pDate->set_day(25);  // Date::set_day(pDate, 25)
                         // type(this pointer of set_day) == Date* 
                         // type(pDate) == const Date*
                         // MATCH ERROR 



    delete pDate; 
    pDate = 0; 

    return 0; 
}

