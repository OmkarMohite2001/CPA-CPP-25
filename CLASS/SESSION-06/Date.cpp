#include <iostream>

class Date
{
    private:
        int day;
        int month;
        int year;
    
    public:
        Date(int init_Day,int init_Month,int init_Year):day(init_Day),month(init_Month),year(init_Year)
        {

        }
        int get_Day()
        {
            return this->day;
        }
        int get_Month()
        {
            return this->month;
        }
        int get_Year()
        {
            return this->year;
        }
        void set_Day(int new_day)
        {
            this->day = new_day;
        }
        void set_Month(int new_month)
        {
            this->month = new_month;
        }
        void set_Year(int new_year)
        {
            this->year = new_year;
        }
        void show()
        {
            std::cout << day << "/" << month << "/" << year << std::endl;
        }
};
int main(void)
{
    Date myDate_1(28,9,2026);
    int Day = myDate_1.get_Day();
    int Month = myDate_1.get_Month();
    int Year = myDate_1.get_Year();

    std::cout << "Testing Getters():\n" << Day << "/" << Month << "/" << Year << std::endl;
    myDate_1.set_Day(19);
    myDate_1.set_Month(5);
    myDate_1.set_Year(2026);

    std::cout<< "Testing Setters():" << std::endl;
    myDate_1.show();

    return 0;
}