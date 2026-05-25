#include <iostream> 
#include <functional> 
#include <vector>

void reduce_demo(void); 

int main(void)
{
    reduce_demo(); 
    return (0); 
}

void reduce_demo(void)
{
    auto reduce = [](
                        std::function<int(int, int)> r_func, 
                        std::vector<int> vec, 
                        int init_val
                    ){
            int rs = init_val; 
            for(std::vector<int>::size_type i = 0; i != vec.size(); ++i)
                rs = r_func(rs, vec[i]); 
            return rs; 
        }; 

    int rs = reduce([](int x, int y) { return x * y;}, std::vector<int>{1, 2, 3, 4, 5}, 1); 
    std::cout << "rs=" << rs << std::endl; 
}

// higher order function, factory, 
// map, map using template 
// filter, filter using template 
// reduce (of integer)
