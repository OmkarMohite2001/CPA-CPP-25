#include <iostream> 
#include <functional>
#include <string> 
#include <map> 

int my_add(int, int); 
int my_sub(int, int); 
int my_mul(int, int); 
int my_div(int, int); 

int wrapper(std::function<int(int,int)>, int, int); 

int main(void){
    int x = 20, y = 10; 
    printf("wrapper(my_add, x, y) = %d\n", wrapper(my_add, x, y)); 
    printf("wrapper(my_sub, x, y) = %d\n", wrapper(my_sub, x, y));
    printf("wrapper(my_mul, x, y) = %d\n", wrapper(my_mul, x, y));
    printf("wrapper(my_div, x, y) = %d\n", wrapper(my_div, x, y));
    return (0); 
}

int wrapper(std::function<int(int, int)> ref_f, int x, int y){
    return ref_f(x, y); 
}

int my_add(int a, int b){
    return (a+b);
}

int my_sub(int a, int b){
    return (a-b); 
}

int my_mul(int a, int b){
    return (a*b); 
}

int my_div(int a, int b){
    return (a/b); 
}

void function_table_test()
{
    std::map<std::string, std::function<int(int, int)>> binops_table{
        {   std::string("add"), [](int x, int y)->int { return x+y; }    },
        {   std::string("sub"), [](int x, int y)->int { return x-y; }    }, 
        {   std::string("mul"), [](int x, int y)->int { return x*y; }    }, 
        {   std::string("div"), [](int x, int y)->int {  return x/y;}    }
    };

    int sum = binops_table["add"](100, 200);  
}


/* 
    int (*pfn_arr[4])(int, int) = {my_add, my_sub, my_mul, my_div}; 

    pfn_arr[0](a, b)
*/ 

/* 

namespace std{
    tempalte <typename keyType, typename valueType> 
    class map
    {
        // rest of the definition
    }; 
}
*/