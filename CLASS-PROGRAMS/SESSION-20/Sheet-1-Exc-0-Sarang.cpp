#include <iostream>
#include <string> 

class Employee
{
    private:
        std::string& empDept;
    public:
        Employee (std::string& newEmpDept): empDept(newEmpDept)
        {

        }

        std::string getDept()
        {
            std::cout << "empDept:" << empDept << std::endl; 
            return empDept;
        } 
};

int main(void)
{
    Employee firstEmp(std::string("Fin"));
    std::string my_dep = firstEmp.getDept();
    std::cout << my_dep << std::endl;
    return 0;
}
