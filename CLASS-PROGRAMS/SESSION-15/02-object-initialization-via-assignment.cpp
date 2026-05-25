#include <iostream> 

class Date 
{
    private: 
        int day, month, year; 

    public: 
        Date(int init_day, int init_month, int init_year)
        {
            // Initialization via assignment syntax 
            this->day = init_day;   
            this->month = init_month; 
            this->year = init_year; 
        }

        void show() 
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        }
}; 

int main(void)
{
    //  An object of class Date will be allocated on the stack frame of main() function 
    //  For initialization purpose, its base address along with initialization data 
    //  9, 11, 2025 will be passed to the constructor 
    //  The constructor is written using assignment syntax, therefore, 
    //  three assignment statements will be executed to put initial values in three members 
    Date myDate(9, 11, 2025); 

    myDate.show(); 

    return 0; 
}

/* 
    This is equivalent to 
    struct Date myDate; 

    void constructor_function()
    {
        myDate.day = 9; 
        myDate.month = 11; 
        myDate.year = 2025; 
    }
*/