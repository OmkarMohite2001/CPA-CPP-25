/* 
    filter is an outer lamba
        @p1: lambda 
            @p1: data of dtype_1 
            @return: bool 
        @p2: vector of dtype_1 
        @return: vector of dtype_1 

*/

#include <iostream> 
#include <vector> 
#include <functional> 

void filter_demo(void); 

int main(void)
{
    filter_demo(); 
    return (0); 
}

void filter_demo(void)
{
    auto filter = [](std::function<bool(int)> filter_func, std::vector<int> input_vec)->std::vector<int>{
        std::vector<int> op_vector; 
        for(std::vector<int>::size_type i = 0; i != input_vec.size(); ++i)
            if(filter_func(input_vec[i]) == true)
                op_vector.push_back(input_vec[i]);
        return op_vector; 
    }; 

    std::vector<int> op_vec = filter(
                                    [](int x)->bool{return x % 2 == 0;}, 
                                    std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}
                                ); 

    for(std::vector<int>::size_type i = 0; i != op_vec.size(); ++i)
        std::cout << "op_vec[" << i << "]:" << op_vec[i] << std::endl; 
}

