#include <iostream> 

class Date 
{
    friend class Y; //  DECLARATION 
    private: 
        int day, month, year; 
    public: 
        Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy)
        {

        }
}; 

class X 
{
    public: 
        X() 
        {
            Date myDate(7, 12, 2025); 
            //  myDate.day = 8;     // CTE: private member day is not accessible 
        }

        void f1() 
        {
            Date myDate_f1(7, 12, 2025); 
            //myDate_f1.month = 11;   // CTE: private member month is not accessible  
        }

        static void f2(void)
        {
            Date myDate_f2(7, 12, 2025); 
            //myDate_f2.year = 2024;  // CTE: private member year is not accessible 
        }
}; 

//  Class Y is declared to be a friend of class Date 
//  Therefore all of its member function can access private members (data + function)
//  of all Date objects accessible to them ! 
class Y 
{
    public: 
        Y() 
        {
            Date myDate(7, 12, 2025); 
            myDate.day = 8; 
        }

        void f1() 
        {
            Date myDate_f1(7, 12, 2025); 
            myDate_f1.month = 11; 
        }

        static void f2(void)
        {
            Date myDate_f2(7, 12, 2025); 
            myDate_f2.year = 2024; 
        }
}; 

int main(void)
{

    return (0); 
}