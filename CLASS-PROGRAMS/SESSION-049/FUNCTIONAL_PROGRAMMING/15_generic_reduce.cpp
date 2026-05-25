#include <iostream> 
#include <vector> 
#include <list>
#include <functional> 
#include <memory> 

template <typename T, 
            template <typename ELEMENT_TYPE, class Allocator = std::allocator<ELEMENT_TYPE>>
            class CONT>  
auto cpa_reduce = [](std::function<T(T,T)> bin_op, CONT<T> container, T init_val) -> T{
                    T val{init_val};
                    for(CONT<T>::iterator iter = container.begin(); 
                        iter != container.end(); 
                        ++iter)
                        val = bin_op(val, *iter); 
                    return val;  
                }; 

int main(void){
    std::vector<float> fvec{1.1f, 1.1f, 3.3f, 4.4f, 5.5f}; 
    std::list<int> ilst{10, 20, 30, 40, 50, 60}; 

    auto rs1 = cpa_reduce<float, std::vector>([](float a, float b)->float{return a + b;}, 
                                                fvec, 0.0); 
    std::cout << "rs1:" << rs1 << std::endl; 

    auto rs2 = cpa_reduce<int, std::list>([](int a, int b){ return a * b; }, 
                                            ilst, 1); 
    std::cout << "rs2:" << rs2 << std::endl; 

    return 0; 
}