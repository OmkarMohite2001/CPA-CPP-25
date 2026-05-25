#include <iostream> 
#include <functional> 
#include <vector> 
#include <list> 

template <
            typename Ti, 
            typename To, 
            template <typename ELEMENT_TYPE, typename ALLOCATOR = std::allocator<ELEMENT_TYPE>> class I_CONT, 
            template <typename ELEMENT_TYPE, typename ALLOCATOR = std::allocator<ELEMENT_TYPE>> class O_CONT
        >
auto cpa_map = [](std::function<To(Ti)> func, I_CONT<Ti> container) -> O_CONT<To>{
                O_CONT<To> output_container; 

                for(I_CONT<Ti>::iterator iter = container.begin(); 
                    iter != container.end(); 
                    ++iter)
                    output_container.push_back(func(*iter)); 
                
                return output_container; 
            }; 

int main(void)
{
    std::list<double> olist = cpa_map<int, double, std::vector, std::list>(
                                    [](int x) -> double {return (double)x/7.0f;},
                                    std::vector<int> {10, 20, 30, 40, 50}  
                                ); 

    for(std::list<double>::iterator iter = olist.begin(); iter != olist.end(); ++iter) 
        std::cout << "*iter = " << *iter << std::endl; 

    return 0; 
}

// C++ : OG language