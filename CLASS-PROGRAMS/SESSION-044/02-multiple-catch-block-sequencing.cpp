#include <iostream> 
#include <stdexcept> 
#include <ctime> 

void f(int n); 
void g(int n); 

int main()
{
    srand(time(0)); 
    try 
    {
        f(rand());
        g(rand());  
    }
    catch(const std::logic_error& e)
    {
        //  Control flow will come here in both cases 
        //  logic_error is thrown | domain_error is thrown
    }
    catch(const std::domain_error& e)
    {
        // control flow will never come here 
        //  because even if domain_error exception is thrown 
        //  in function f() it will match with the first catch 
        //  block, because a reference variable of the type logic_error 
        //  can refer to object of type domain_error because logic_error 
        //  is a base class of domain_error
    }
   
    //  Note : while writing multiple catch block
    //  Make sure that exception in any lower catch block 
    //  should be a direct or an indirect derived class of 
    //  an exception written in any catch block above it. 

    //  While writing a catch block : ask yourself: 
    //  whether exception name that you are going to write in this catch block 
    //  is directly or indirectly deriving itself from any of the exception 
    //  in catch blocks lying above you. 

    //  If answer is no : then go ahead 
    //  If answer is yes : then put current catch block above the catch 
    //  block whose derived class is your current catch block's exception 
}

void f(int n) 
{
    if(n % 2 == 0)
        throw std::domain_error("Exception thrown because of even number"); 
}

void g(int n) 
{
    if(n % 2 == 1)
        throw std::logic_error("Exception thrown because of odd number"); 
}




