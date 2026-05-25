#include <iostream> 
#include <functional> 
#include <vector> 

/* 
    1) function : accepting int, returning int 
    2) vector of integers 
    -> INPUT 
    return value: New vector containing all integers obtained 
    by applying function on vector of integers 

    HINT: Use lambda expr 
*/

void test(void); 
void test1(void); 

int main(void)
{
    test(); 
    return (0); 
}

void test(void)
{
    auto map = [](std::function<int(int)> func, std::vector<int>& v) -> std::vector<int>{
                    std::vector<int> rsv; 
                    for(std::vector<int>::size_type i = 0; i != v.size(); ++i)
                        rsv.push_back(func(v[i])); 
                    return rsv; 
                }; 

    std::vector<int> r = map([](int x)->int { return x * x ;}, std::vector<int>{100, 200, 300, 400}); 
    for(std::vector<int>::iterator iter = r.begin(); iter != r.end(); ++iter)
        std::cout << "*iter=" << *iter << std::endl; 
}

void test1(void)
{
    std::vector<int> r = [](std::function<int(int)> func, std::vector<int> v) -> std::vector<int>{
                            std::vector<int> rsv; 
                            for(std::vector<int>::size_type i = 0; i != v.size(); ++i)
                                rsv.push_back(func(v[i])); 
                            return rsv; 
                        }(
                            [](int x)->int { return x * x ;}, 
                            std::vector<int>{100, 200, 300, 400}
                        ); 

    for(std::vector<int>::iterator iter = r.begin(); iter != r.end(); ++iter)
        std::cout << "*iter=" << *iter << std::endl; 
}