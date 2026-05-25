#include "filter.hpp"

#include <iostream> 

int main(void){
    
    std::vector<double> ovec = filter<double>([](double x)->bool { return x/2 < 5.0; },
                                            std::vector<double>{1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0}
                                        );   
    for(std::vector<double>::size_type i = 0; i != ovec.size(); ++i) 
        std::cout << "ovec[" << i << "]:" << ovec[i] << std::endl; 

    return (0); 
}