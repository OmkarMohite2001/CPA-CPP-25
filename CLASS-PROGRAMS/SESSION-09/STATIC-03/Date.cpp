// C++ 11 
class Date 
{
    private: 
        int day = 1; 
        int month = 1; 
        int year = 1970; 
}; 

// C++ 98 
class Date 
{
    private: 
        int day; 
        int month; 
        int year; 
        //static int s_num; 
    public: 
        Date() 
        {
            this->day = 1; 
            this->month = 1; 
            this->year = 1970; 
        }
};

int Date::s_num = 100; 
float Date::pi = 3.1415f; 



// C 
struct Date 
{
    int day; 
    int month; 
    int year;
}; 


