#include <iostream> 

class Test 
{
    private: 
        int num, num2; 
        double d_num; 
        static int s_num;
        // static T v_name; 
    
    public: 
        Test() 
        {
            num = 100; 
            d_num = 3.1415; 
        } 

        void show() 
        {
            std::cout << "num:" << num << std::endl 
                        << "d_num:" << d_num << std::endl
                        << "s_num:" << s_num << std::endl; 
        }
}; 

int Test::s_num = 10;   // This is where memory gets allocated. 
                        // This syntax is mandatory in C++ 98. 
                        // From C++ 11 onwards, this is not necessary. 

// T Test::v_name [=optional iniitializer]

int main(void)
{
    Test t; 
    t.show(); 

    std::cout << "Sizeof(Test):" << sizeof(Test) << std::endl; 
    
    return 0; 
}

//  Comments: 
//  Applying static qualifier to data definition statement inside class has 
//  the following effects 
//  1)  Time of allocation: static 
//  2)  Section of allocation: Data / BSS 
//  3)  Frequency of allocation: Once 
//  4)  Visibility: static and non-static member functions of class. 
//      [We are not considering derived classes, friend functions and 
//          and friend classes as of now]
//  5)  Lifetime == Lifetime of program

//  For non-static data member 
//  1)  Time of allocation == Time of allocation of object 
//  2)  Section of allocation == Section of allocation of object 
//  3)  Frequency of allocation == Per object 
//  4)  Visibility == non-static member functions of class. 
//                      [ static member functions cannot access non-static data members ]
//      [We are not considering derived classes, friend functions and 
//       and friend classes as of now]
//  5)  Lifetime == Lifetime of object 
