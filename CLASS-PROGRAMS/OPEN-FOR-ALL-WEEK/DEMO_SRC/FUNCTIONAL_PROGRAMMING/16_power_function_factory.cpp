/* 
def power_function_factory(n): 
    def inner_function(x): 
        return x ** n 
    return inner_function 

def PowerFunction(x, n): 
    return x**n 

(float, float)->float

float->(float->float)

power_function_factory(2)

IMPLEMENT FACTORY FUNCTION (POWER FUNCTION FACTORY AS EXAMPLE)
DESIGN PATTERN IN C++ USING lambda 
*/

#include <iostream> 

int main()
{
    auto power_function_factory = [](int n){
                                        return [n](double x) -> double
                                        {
                                            double rs = 1.0; 
                                            for(int i = 0; i < n; ++i)
                                                rs = rs * x; 
                                            return rs; 
                                        }; 
                                    }; 

    auto square_func = power_function_factory(2); 
    auto cube_func = power_function_factory(3); 

    double x; 
    std::cout << "Enter a fractional number" << std::endl; 
    std::cin >> x; 
    std::cout << "square_func(x):" << square_func(x) << std::endl; 
    std::cout << "cube_func(x):" << cube_func(x) << std::endl; 

    return 0; 
}