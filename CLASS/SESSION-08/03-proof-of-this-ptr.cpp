#include <iostream>

class Date
{
    private:
        int day;
        int month;
        int year;
    
    public:
        Date()
        {
            std::cout << "Entered Date::Date()" << std::endl;
            std::cout << "Date::Date() type(this)" << typeid(this).name() << std ::endl;
            std::cout << "Leaving Date::Dare()" << std::endl;
        }
};
class Student
{
    private:
        char* st_name;
        int st_roll_Number;
        float st_marks;
        float st_attendance;
    
    public:
        Student()
        {
            std::cout << "Entered Student::Student()" << std::endl;
            std::cout << "Student::Student() type(this)" <<std::endl;
            std::cout << "Leaving Student::Student()" << std::endl;
        }
};

int main(void)
{
    Date myDate;
    Student myStudent;

    return 0;
}