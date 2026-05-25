#include <iostream> 

int g_num = 1000; 

class X 
{
    private: 
        int n = 10; 
        const int P = 100; 
        int& ref = g_num; 
        int&& r_ref = 500; 
    public: 
        X() = default; 
        
        void show() const 
        {
            std::cout << "n:" << n << std::endl;
            std::cout << "P:" << P << std::endl; 
            std::cout << "ref:" << ref << std::endl; 
            std::cout << "r_ref:" << r_ref << std::endl; 
        }
}; 

int main() 
{
    X objX; 

    objX.show(); 

    return 0; 
}