// function class 

#include <iostream>
#include <functional> 
#include <cstdio>  
#include <cstdlib> 

void insertion_sort(int* pa, int size); 

int main(void){
    std::function<void(int*, int)> sorting_function1; 
    std::function<void(int*,int)> sorting_function2(nullptr); 
    std::function<void(int*, int)> sorting_function3(insertion_sort); 
    std::function<int(int,int)> func_obj([](int a, int b) { return (a + b);}); 

    if(sorting_function3)
        puts("Does hold the callable object"); 
    if(!sorting_function2)
        puts("Does not hold the callable object"); 

    int a[] = {50, 40, 30, 20, 10}; 
    sorting_function3(a, 5); 
    
    // decltype(sorting_function3)::result_type* p; 

    std::function<void(int*, int)>::result_type* p = nullptr; 
    std::function<void(int*, int)>:: first_argument_type p_int = nullptr; 
    std::function<void(int*, int)>::second_argument_type n = -1; 
     
    return (0); 
}

void insertion_sort(int* pa, int size){
    int i, j; 
    int key; 

    for(j = 1; j < size; ++j){
        key = pa[j]; 
        i = j - 1; 
        while(i > -1 && pa[i] > key){
            pa[i+1] = pa[i]; 
            i = i - 1; 
        }
        pa[i+1] = key; 
    }
}

/* 
template<typename T> 
void insertion_sort(T* pa, size_t N, std::function<bool(T, T)> less_than, std::function<bool(T, T)> equal_to)
{
    bool rs; 

    rs = less_than(pa[i], pa[j]) || equal_to(pa[i], pa[j]); 
}
*/


/* 
template<typename T> 
void insertion_sort(T* pa, size_t N)
{
    std::less_than<T> lt; // if class T has operator< 

}
*/


/* 
std::function<void(int, int)> insertion_sort(
        [](int* pa, int size)->void(int* pa, int size){
        int i, j; 
        int key; 

        for(j = 1; j < size; ++j){
            key = pa[j]; 
            i = j - 1; 
            while(i > -1 && pa[i] > key){
                pa[i+1] = pa[i]; 
                i = i - 1; 
            }
            pa[i+1] = key; 
        }
    }
);

insertion_sort(a, 10); 

*/