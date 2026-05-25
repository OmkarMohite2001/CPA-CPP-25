#include <iostream> 
#include <functional> 
#include <vector> 

void test(); 
void test1(); 

int main()
{
    test(); 
    test1(); 
    return 0; 
}

void test() 
{
    auto map1 = [](std::function<int(int)> func, std::vector<int>& vec) -> std::vector<int> 
                {
                    std::vector<int> rsv; 
                    for(const auto&v : vec)
                        rsv.push_back(func(v)); 
                    return rsv; 
                };

    auto map2 = [](std::function<int(int)> func, std::vector<int>& vec) -> std::vector<int> 
                {
                    std::vector<int> rsv; 
                    for(const auto& v : vec)
                        rsv.push_back(func(v)); 
                    return rsv; 
                }; 

    auto map3 = [](std::function<int(int)> func, std::vector<int>& vec) -> std::vector<int> 
                {
                    std::vector<int> rsv; 
                    for(const auto& v : vec)
                        rsv.push_back(func(v)); 
                    return rsv; 
                }; 

    auto map4 = [](std::function<int(int)> func_object, std::vector<int>& vec) -> std::vector<int> 
                {
                    std::vector<int> rsv; 
                    for(const auto& v : vec)
                        rsv.push_back(func_object(v)); 
                    return rsv; 
                }; 


    auto map5 = [](std::function<int(int)> func_object, std::vector<int>& vec) -> std::vector<int> 
                {
                    std::vector<int> rsv; 
                    for(const auto& v : vec)
                        rsv.push_back(func_object(v)); 
                    return rsv; 
                }; 
}

void test1() 
{
    //  sum of squares of all even numbers between 1 to 10 -> computed in 1 RHS 

    int sum =   [](std::function<int(int, int)> sum_func, std::vector<int>& vec, int init_val) -> int 
                {
                    int rs = init_val; 
                    for(const auto& v : vec)
                        rs = sum_func(rs, v); 

                    return rs; 
                }(
                    [](int x, int y) -> int { return x + y;}, 
                    [](std::function<int(int)> func, std::vector<int>& vec) -> std::vector<int> 
                    {
                        std::vector<int> rsv; 
                        for(const auto& v : vec) 
                            rsv.push_back(func(v)); 
                        return rsv; 
                    }(
                        [](int x) -> int { return x * x; }, 
                        [](std::function<bool(int)> func, std::vector<int>& vec) -> std::vector<int> 
                        {
                            std::vector<int> rsv; 
                            for(const auto& v : vec)
                                if(func(v))
                                    rsv.push_back(v); 
                            return rsv; 
                        }(
                            [](int x) -> bool { return x % 2 == 0;}, 
                            std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
                        )
                    ), 
                    0
                ); 

    std::cout << "Sum:" << sum << std::endl; 
}