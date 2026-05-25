#include <iostream> 

// constexpr constructor 
class Date{
    private: 
        int day, month, year; 

    public: 
        Date(int init_day, int init_month, int init_year) : day(init_day), 
                                                            month(init_month), 
                                                            year(init_year)
        {} 
        
        constexpr Date(int init_day, int init_month, int init_year) :   day(init_day), 
                                                                        month(init_month), 
                                                                        year(init_year)
        {} 
         
        void set_day(int new_day){
            day = new_day; 
        }

        void show() const {
            std::cout << day << "-" << month << "-" << year << std::endl; 
        }
}; 

// global constexpr 
int g_num1 = 100; 
const int g_num2 = g_num1; // ok 
constexpr int g_num3 = 100; // ok 
// constexpr int g_num4 = g_num1; // error, initializer must be a literal expression 

void constexpr_test_function(void); 
void Date_object_test(void); 

int main(void){
    constexpr_test_function(); 
    Date_object_test(); 
    return (0); 
}

void constexpr_test_function(void){
    int local_int = 100; 
    const int local_const_int = local_int; // ok 
    constexpr int local_constexpr_int_1 = 1000; // ok 
    // constexpr int local_constexpr_int_2 = local_int; // error 
}

void Date_object_test(void){
    int dd=11, mm=2, yy=2021; 
    Date d1(10, 1, 2021); 
    Date d2(dd, mm, yy); 
    const Date d3(11, 2, 2021); 
    const Date d4(dd, mm, yy); 
    constexpr Date d5(15, 3, 2021); 
    // constexpr Date d6(dd, mm, yy); // error, initializers must be literal 
    
    d1.show();  // ok 
    d2.show();  // ok 
    d3.show();  // ok 
    d4.show();  // ok 
    d5.show();  // ok 

    d1.set_day(20);     // ok 
    d2.set_day(20);     // ok 
    // d3.set_day(20);     // error, non-const method on const object
    // d4.set_day(20);     // error, non-const method on const object 
    // d5.set_day(20);     // error, non-const method on constexpr object 

    constexpr int dd1 = 17; 
    constexpr int mm1 = 8; 
    constexpr int yy1 = 2025; 

    constexpr Date today(dd1, mm1, yy1); // okay 
}

