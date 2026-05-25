#include <iostream> 

namespace cpa 
{
    template <typename T> 
    class vector
    {
        private: 
            T* p_arr; 
            std::size_t N; 

        public: 
            vector<T>() : p_arr(0), N(0) {}
            
            vector<T>(std::size_t N, T const& defaultVal)
            {
                p_arr = new T[N]; 
                for(std::size_t i = 0; i != N; ++i)
                    p_arr[i] = defaultVal; 
            }

            vector<T>(std::size_t N)
            {
                p_arr = new T[N]; 
            }

            vector<T>(const vector<T>& other)
            {
                this->N = other.N; 
                p_arr = new T[this->N]; 
                for(std::size_t i = 0; i != N; ++i)
                    p_arr[i] = other.p_arr[i]; 
            }

            vector<T>(std::initializer_list<T> i_list) 
            {
                this->N = i_list.size(); 
                this->p_arr = new T[this->N]; 
                std::size_t index = 0; 
                for(const auto& v : i_list)
                    this->p_arr[index++] = v; 
            }

            vector<T>& operator=(const vector<T>& other)
            {
                if(this->p_arr)
                {
                    delete this->p_arr; 
                    this->p_arr = 0; 
                    this->N = 0; 
                } 

                this->N = other.N; 
                this->p_arr = new T[this->N]; 
                std::size_t index = 0; 
                for(index = 0; index != this->N; ++index)
                    this->p_arr[index] = other.p_arr[index]; 

                return *this; 
            }

            ~vector<T>()
            {
                if(this->p_arr)
                {
                    delete this->p_arr; 
                    this->p_arr = 0; 
                    this-> N =0; 
                }
            }
    }; 
}

// sweet exercise 
int main(void)
{
    // Test the above code 
    return 0; 
}

/* 
    ANTON GOWDY : GOD LIES IN THE DETAILS. 
*/