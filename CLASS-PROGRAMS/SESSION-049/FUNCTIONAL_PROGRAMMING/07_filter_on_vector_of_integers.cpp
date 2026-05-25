#include <iostream> 
#include <functional> 
#include <vector> 

void test(void); 

int main(void)
{
    test(); 
    return (0); 
}

void test(void)
{
    auto filter = [](std::function<bool(int)> func_object, std::vector<int>& ivec)->std::vector<int>{
                    std::vector<int> rsv; 
                    for(std::vector<int>::size_type i = 0; i != ivec.size(); ++i)
                        if(func_object(ivec[i]) == true)
                            rsv.push_back(ivec[i]); 
                    return rsv; 
                }; 

    std::vector<int> rsv = filter([](int x)->bool { return x % 2 == 0; }, 
                                    std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}); 

    std::cout << "Filtered list:" << std::endl; 
    for(std::vector<int>::size_type i = 0; i != rsv.size(); ++i)
        std::cout << "rsv[" << i << "]:" << rsv[i] << std::endl; 
}