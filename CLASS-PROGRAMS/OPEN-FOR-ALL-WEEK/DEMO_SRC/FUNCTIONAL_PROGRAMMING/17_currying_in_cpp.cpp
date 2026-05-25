#include <iostream> 

void test(void); 

int main(void) 
{
    test(); 
    return (0); 
}

void test(void)
{
    int x = [](int x){
                return [x](int y)->int{
                    return x + y; 
                }; 
            }(10)(20);
    std::cout << "x = " << x << std::endl;       
}

/* 
    int x = [](int x){
                return [x](int y)->int{
                    return x + y; 
                }; 
            }(10)(20);

    (lambda x : (lambda y : x + y))(10)(20)

    add x y = x + y 

*/