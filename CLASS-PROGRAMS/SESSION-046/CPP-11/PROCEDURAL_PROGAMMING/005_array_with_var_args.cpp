#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <cstdarg> 

class cpa_array{
    private: 
        int* p_arr; 
        std::size_t size; 
    public: 
        cpa_array(...){
            va_list ap; 
            va_start(ap, this);
            size = (std::size_t)va_arg(ap, int); 
            
            p_arr = new int[size]; 
            for(std::size_t i = 0; i != size; ++i)
                p_arr[i] = va_arg(ap, int); 

            va_end(ap); 
        }

        ~cpa_array(){
            delete[] p_arr; 
        }

        friend std::ostream& operator<<(std::ostream& os, const cpa_array& A){
            for(std::size_t i = 0; i != A.size; ++i)
                os << "A[" << i << "]:" << A.p_arr[i] << std::endl; 
            return os; 
        }
}; 

int main(void){
    cpa_array A{5, 10, 20, 30, 40, 50}; 
    cpa_array B{3, 100, 200, 300}; 

    std::cout << "A:" << A; 
    std::cout << "B:" << B; 
  
    return (0); 
}

/* 
void test(void)
{
    std::vector<int> v1; // empty 
    std::vector<int> v2(5); // vector with five preallocated slots for integer 
                            // value in those five slot is the default value for type 
    std::vector<int> v3(5, 100); 

    std::vector<int> v4{100, 200, 300, 400, 500}; 
    std::list<int> v5 = {100, 200, -400, -500}; 

    array A{100, 200, 300}; 
}*/ 