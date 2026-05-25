#ifndef _FILTER_H 
#define _FILTER_H 

#include <vector> 
#include <functional> 

template <typename T> 
auto filter = [](std::function<bool(T)> f_func, std::vector<T> vec) -> std::vector<T>{
    std::vector<T> ovec; 
    for(std::vector<T>::size_type i = 0; i != vec.size(); ++i)
        if(f_func(vec[i]) == true)
            ovec.push_back(vec[i]); 
    return ovec; 
}; 

#endif 