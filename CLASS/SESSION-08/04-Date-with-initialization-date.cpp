#include <iostream>

class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int init_day,int init_month,int init_year)
        {
            this->day = init_day;
            this->month = init_month;
            this->year = init_year;
        }
};

int main(void)
{
    Date myDate(10,10,2025);
    Date myExamDate(04,05,2026);
    Date myBirthDate(04,11,2001);
    Date epochDate(1,1,1970);

    return 0;
}