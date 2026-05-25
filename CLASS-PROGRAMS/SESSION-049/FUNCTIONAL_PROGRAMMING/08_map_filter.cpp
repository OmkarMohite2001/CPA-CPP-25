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
    auto map = [](std::function<int(int)> func, std::vector<int> v) -> std::vector<int>{
                std::vector<int> rsv; 
                for(std::vector<int>::size_type i = 0; i != v.size(); ++i)
                    rsv.push_back(func(v[i])); 
                return rsv; 
            }; 

    auto filter = [](std::function<bool(int)> func_object, std::vector<int> ivec){
                std::vector<int> rsv; 
                for(std::vector<int>::size_type i = 0; i != ivec.size(); ++i)
                    if(func_object(ivec[i]) == true)
                        rsv.push_back(ivec[i]); 
                return rsv; 
            }; 

    std::vector<int> rsv = map(
                                [](int n)->int{return n*n;}, 
                                filter(
                                        [](int n)->bool{return n % 2 == 0; }, 
                                        std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
                                    )
                            ); 

    for(
        std::vector<int>::iterator iter = rsv.begin(); 
        iter != rsv.end(); 
        ++iter
    ) 
        std::cout << "*iter=" << *iter << std::endl; 
}