#include <iostream> 
#include <vector> 
#include "map.hpp"

int main(void)
{
    std::vector<double> ovec = map<int, double>([](int x)->double{return ((double)x)/2;}, 
                            std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    for(std::vector<double>::size_type i = 0; i != ovec.size(); ++i) 
        std::cout << "ovec[" << i << "]:" << ovec[i] << std::endl; 
    return (0);  
}