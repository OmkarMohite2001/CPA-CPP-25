#include <iostream> 
#include <string> 

class Employee
{
    private: 
        std::string& empName; 
    public: 
        Employee(std::string& _empName) : empName(_empName) 
        {
        }

        const std::string& getName() const 
        {
            return empName; 
        }
}; 

int main(void)
{
    std::string s("Yogeshwar"); 
    Employee e(s); 
    const std::string& name = e.getName(); 

    //  Employee e(std::string("Yogeshwar")); 
    //  will not print the name because 
    //  inline expression std::string("Yogeshwar")
    //  will create a temp object on the stack frame of main() 
    //  and when it leaves for the constructor the tmp object 
    //  is already destroyed. 

    //  Exception to this rule is that the formal parameter 
    //  of constructor is const std::string& empName 
    //  But that will create futher errors 
    //  because data member is is non-const reference 
    //  std::string& empName; 
    //  non-const reference cannot be initialized by const reference 

    //  and if we make data member a const reference 
    //  then it will not remain modifiable (we cannot change employee name 
    //  in any object)
   
    return (0); 
}

void test(void)
{
    const int num = 100; 
    int n; 

    n = num; 

    // num will be a symbolic constant 
    n = 100; 

}

//  movl    $100, n
//  []      

//  [PREFIX-1][OPCODE-1 to 3][MOD R/M-1][SIB-1][IMMEDATE-4][DISPLACEMENT-4]