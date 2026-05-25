#include<iostream>
class Test
{
    private:
        int  num;
        double d_num;
        static int s_num;

    public:
        Test()
        {
            num = 100;
            d_num = 3.1415;
        }
        
        void show(void)
        {
            std::cout << "num : " << num << std::endl
                      << "d_num : " << d_num << std::endl
                      << "s_num : " << s_num << std::endl;
        }
};

int Test::s_num = 10;   //This is where memory gets allocated.
                        //This syntax is mandatory in C++ 98.
                        //From C++ 11 onwards, this is not necessary

int main(void)
{
    Test t;
    t.show();

    std::cout << "Sizeof(Test) : " << sizeof(Test) << std::endl;

    return 0;
}

//  Commments:
//  Applyinng static qualifiers to data defination statement inside class has
//  the following effects 
//  1)  Time of  allocation: static
//  2)  section of allocation : Data/bss
//  3)  Frequency of allocation : Once
//  4)  Visibility: static and non static member function of class.
//      [We are not considering derived classes,friend function and 
//      friend classes as of now    ]
//  5)  Lifetime = Lifetimeof a program

//  For non-static data member
//  1)  Time of allocation == Time of allocation of object
//  2)  Sectionn of allocation  == Section of allocation of object.
//  3)  Frequency of allocation == per object.
//  4)  Visibility  ==  non-static member function of class.
//                  [static member function cannot access non-static data members ]
//  [We are not considering derived classes, friend function and 
//      and friend classes as of row]
//  5)  Lifetime = Lifetime of Object
