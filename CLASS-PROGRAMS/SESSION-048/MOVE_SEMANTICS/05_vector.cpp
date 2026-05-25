#include <iostream> 
#include <cstring> 
#include <memory> 

using ssize_t=long long int; 

class vector_int 
{
    private: 
        int* p_arr; 
        ssize_t N; 
    public: 
        vector_int() : p_arr(nullptr), N(0)
        {

        }

        vector_int(ssize_t _N) : p_arr(new int[_N]), N(_N) 
        {
            memset(p_arr, 0, N * sizeof(int)); 
        } 

        vector_int(ssize_t _N, int initializer) : p_arr(new int[_N]), N(_N)
        {
            for(ssize_t i = 0; i < N; ++i)
                p_arr[i] = initializer; 
        }

        vector_int(std::initializer_list<int> lst) 
        {
            ssize_t _N = lst.size(); 
            p_arr = new int[_N]; 
            N = _N; 
            ssize_t i = 0; 
            for(std::initializer_list<int>::iterator iter = lst.begin(); 
                iter != lst.end(); 
                ++iter)
                p_arr[i++] = *iter; 
        }

        vector_int(vector_int&& rr) : p_arr(rr.p_arr), N(rr.N)
        {
            rr.p_arr = 0; 
            rr.N = 0; 
        }

        vector_int& operator=(vector_int&& rr)
        {
            if(p_arr)
                delete[] p_arr; 
            
            p_arr = rr.p_arr; 
            N = rr.N; 
            rr.p_arr = 0; 
            rr.N = 0; 

            return *this; 
        }

        friend static std::ostream& operator<<(std::ostream&, const vector_int& obj); 
}; 

std::ostream& operator<<(std::ostream& os, const vector_int& obj)
{
    if(obj.p_arr != 0)
        for(ssize_t i = 0; i != obj.N; ++i)
            std::cout << "vec[" << i << "]:" << obj.p_arr[i] << std::endl; 
    return os; 
}

int main(void)
{
    vector_int v1; 
    std::cout << "v1:" << std::endl << v1 << std::endl;

    vector_int v2(5); 
    std::cout << "v2:" << std::endl << v2; 

    vector_int v3(15, 100); 
    std::cout << "v3:" << std::endl << v3; 

    vector_int v4 = {100, 200, 300, 400, 500, 600}; 
    std::cout << "v4:" << std::endl << v4; 
///////////////////////////////////////////////////////////////////////////////
    vector_int v5(std::move(v4)); 

    std::cout << "v5:" << std::endl << v5 << std::endl; // v5 :100, 200, 300, 400, 500, 600
    std::cout << "v4:" << std::endl << v4 << std::endl; // v4: nothing 

    v2 = std::move(v3);     

    std::cout << "v2:" << std::endl << v2 << std::endl; // v2 :15 times 100 
    std::cout << "v3:" << std::endl << v3 << std::endl; // v3: nothing 

    return 0;  
}