#ifndef _MAP_H 
#define _MAP_H 

#include <vector> 
#include <functional> 

template <typename Ti, typename To> 
auto map = [](std::function<To(Ti)> f_map, std::vector<Ti> ivec)->std::vector<To>{
    std::vector<To> ovec; 
    for(std::vector<Ti>::size_type i = 0; i != ivec.size(); ++i)
        ovec.push_back(f_map(ivec[i])); 
    return ovec; 
}; 

#endif 
