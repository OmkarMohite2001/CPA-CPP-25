/* 
    Write a lambda: 
        @p1: lambda
            @p1: dtype1
            @return: dtype2 
        @p2: std::vector<dtype1> 
        @return: std::vector<dtype2> 
*/

#include <iostream> 
#include <functional> 
#include <vector> 

void map_demo(void); 

int main(void) 
{
    map_demo(); 
    return (0); 
}

void map_demo(void)
{
    auto map = [](std::function<int(int)> f_map, std::vector<int> input_vec)->std::vector<int>{
        std::vector<int> output_vector; 
        for(std::vector<int>::size_type i = 0; i != input_vec.size(); ++i)
            output_vector.push_back(f_map(input_vec[i])); 
        return (output_vector); 
    }; 

    std::vector<int> vec = map([](int x)->int{return x*x;}, std::vector<int>{1, 2, 3, 4, 5}); 
    for(std::vector<int>::size_type i = 0; i != vec.size(); ++i)
        std::cout << "vec[" << i << "]:" << vec[i] << std::endl; 
}




