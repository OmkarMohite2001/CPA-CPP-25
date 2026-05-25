#include <iostream> 

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


// && -> rvalue reference to 

//  int&& rr1 = 10; 
//  rr1 is an rvalue reference to int initialized by r-value expression 10

int main(void){
    int m = 10; 
    int&& rr1 = 10; // 10 is an rvalue which cannot be lvalue 
    int&& rr2 = m + 1; // m+1 is an ravlue which cannot be lvalue 

    // int&& rr3 = m; // error: m is an lvalue 

    int&& rr4 = std::move(m);   // ok, std::move template returns T&& 

    int&& rr5 = reinterpret_cast<int&&>(m); 

    Date myDate(17, 8, 2025); 

    Date&& refDate1 = reinterpret_cast<Date&&>(myDate); 
    // or 
    Date&& refDate1 = std::move(myDate); 

    return (0); 
}

/* Usage will be seen in move semantics */
/* 
    class T{
        private: 
            data layout 
        public: 
            // default constructor 
            T(){} 

            // parameterized constructor 
            T(params){} 

            // Copy constructor 
            T(const T& other){}

            // Move constructor (application of rvalue reference syntax)
            T(T&& other){}

            // Copy Assignment operator 
            T& operator=(const T& other){}

            // Move assignment operator (application of rvalue reference syntax) 
            T& operator=(T&& other) {} 
    }; 

*/

/* 

namespace std 
{
    template <typename T> 
    T&& move(T& ref)
    {
        return reinterpret_cast<T&&>(ref); 
    }
}

*/