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
            this-> year = init_year;
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
    Date myDate(02,04,2026);
    
    int month =  myDate.get_month();
    std::cout << "month" << month;

    
    return 0;
}