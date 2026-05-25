#include <iostream> 
#include <functional> 

int my_add(int, int); 

int main(void) 
{
    // std::function; /* function template */

    std::function<int(int, int)> func_obj(my_add); 

    // std::function<int(int,int)::operator()(&func_obj, 100, 200)
    int result = func_obj(100, 200); 
    std::cout << "Result=" << result << std::endl; 

    return (0); 
}

int my_add(int a, int b)
{
    return a + b; 
}


/* Generalized syntax: 

ret_type fun_name(T1 v1, T2 v2, ...., Tn vn); 

ret_type(T1, T2, T3, ..., Tn); 

TYPE ANNOTATION. 

A FUNCTION HAVING TYPE int(int, int)

int my_add(int, int)
{
}

double square(double){
}

A FUNCTION HAVING TYPE double(double)

int(int, int); 

namespace std{
    template <typename T>
    class function{
        private: 
            T *pfn; 
        public: 
            Tr operator()(params){
                return pfn(params); 
            }
    }; 
}

std::function<int(int, int)> my_func_object(func); 

auto return_val = my_func_object(actual parameter list compatible with 'func')

*/

