#include <iostream>
#include <typeinfo> 

class Date
{
    private: 
        int day; 
        int month; 
        int year; 
    public: 
        Date()
        {
            std::cout << "Date::Date():Entered" << std::endl; 
            std::cout << "Date::Date():type(this):" << typeid(this).name() << std::endl; 
            std::cout << "Date::Date():Leaving" << std::endl;  
        }
}; 

class Student 
{
    private: 
        char* st_name; 
        int st_roll_number; 
        float st_marks; 
        float st_attendance; 
    public: 
        Student() 
        {
            std::cout << "Student::Student():Entered" << std::endl; 
            std::cout << "Student::Student():type(this):" << typeid(this).name() << std::endl; 
            std::cout << "Student::Student():Leaving" << std::endl;  
        }
}; 

int main(void)
{
    Date myDate; 
    Student firstStudent; 

    return 0; 
}
