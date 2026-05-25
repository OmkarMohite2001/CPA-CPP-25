#include <iostream> 
//////////////////////////////////////////////////////////////
class X1 
{
    private: 
        int x, y; 
        double d_arr[4]; 
    public: 
        //  This class does not define any constructor 
        //  There is no public member function whose name 
        //  is equal to name of class
        //  If class definition write has not defined 
        //  constructor then compiler will synthesize 
        //  a constructor for him/her. 
        //  That constructor will not accept any parameter 
        //  other than invisible this pointer and its body 
        //  will be empty. 
        //  Its definition looks like the following 
        //  X1() 
        //  {
        //  }  
}; 
//////////////////////////////////////////////////////////////
class Date 
{
    private: 
        int day, month, year; 
    public: 
        //  This constructor is written by hand 

        //  It does not have any other parameter 
        //  than invisible this pointer

        //  Body of default constructor may be 
        //  empty or may not be empty 
        Date() : day(1), month(1), year(1970) 
        {

        }
}; 
//////////////////////////////////////////////////////////////
class Date 
{
    private: 
        int day, month, year; 
    public: 
        // If a constructor contains at least one mandatory (=non-default)
        // parameter than invisible this pointer then 
        // it is called as parameterized constructor 
        Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy)
        {
        }
}; 


