#include <iostream> 
#include <cstdlib> 
#include <cassert> 
#include <cstring> 

class vector_int{
    private: 
        int* p_arr; 
        size_t size; 
    public: 
        vector_int(size_t arr_size, int default_val=0){
            assert(arr_size > 0); 
            p_arr = new int[arr_size]; 
            size = arr_size; 
            for(size_t i = 0; i < arr_size; ++i)
                p_arr[i] = default_val; 
        }

        vector_int(std::initializer_list<int> init_lst){
            size = init_lst.size(); 
            p_arr = new int[size]; 
            size_t index = 0; 
            for(std::initializer_list<int>::iterator iter = init_lst.begin(); 
                iter != init_lst.end(); 
                ++iter){
                p_arr[index] = *iter; 
                ++index; 
            }
        }

        void show(const char* msg) const{
            if(msg)
                puts(msg); 
            for(size_t index = 0; index < size; ++index)
                std::cout << "A[" << index << "]:" << p_arr[index] << std::endl; 
        }

        ~vector_int(){
            delete[] p_arr; 
            p_arr = nullptr; 
        }
}; 

int main(void)
{
    vector_int ivec_1(10, 5); 
    vector_int ivec_2{100, 200, 300, 400}; 
    vector_int* p_ivec = new vector_int{1000, 2000, 3000, 4000}; 

    ivec_1.show("ivec_1:"); 
    ivec_2.show("ivec_2:"); 
    p_ivec->show("ivec_3:"); 

    delete p_ivec; 
    p_ivec = 0; 

    return (0); 
}

/* 
std::initializer_list<int>::iterator tmp = init_lst.begin(); 
std::initializer_list<int>::iterator iter = init_lst.begin(); 

std::initializer_list<int>::iterator::operator=(&iter, init_list.begin()); 

namespace std
{
    template <typename T> 
    class initializer_list 
    {
        public: 
            class iterator 
            {
                // synethsized member function 
                iterator& operator=(const iterator& other)
                {
                    // member wise copying
                    return *this;   
                }
            }; 
    }; 
}

class_name object_name{t-o1, t-o2, t-o3};

class class_name
{
    public: 
        class_name(std::initializer_list<t> var_args)
        {
        
        }
}; 

*/