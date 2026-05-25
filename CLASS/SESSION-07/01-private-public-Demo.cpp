#include <iostream>

struct Date_01
{
    int day;
    int mmonth;
    int year;
};

class Date_02
{
    private:
    int day;
    int month;
    int year;
};

int main(void)
{
    struct Date_01 myDate01;
    Date_02 myDate02;

    myDate01.day = 21;  //ok
    myDate02.day = 10;  //error

    return 0;
}