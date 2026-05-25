#include <iostream> 
#include <memory> 

class CPA_int{

private: 
    int n; 

public: 
    CPA_int(int _n) : n(_n){

    }

    CPA_int(CPA_int&& rr) : n(rr.n){
        rr.n = 0; 
    }

    CPA_int& operator=(CPA_int&& rr){
        this->n = rr.n; 
        rr.n = 0; 
        return *this; 
    }

    friend std::ostream& operator<<(std::ostream&, const CPA_int& obj); 
}; 

std::ostream& operator<<(std::ostream& os, const CPA_int& obj)
{
    os << obj.n << std::endl; 
    return os; 
}

int main(void)
{
    CPA_int n1(100); 
    std::cout << "n1:" << n1 << std::endl;  // 100 
    CPA_int n2(std::move(n1)); 
    std::cout << "n1:" << n1 << std::endl;  // 0 
    
    CPA_int n3(200); 
    std::cout << "n2:" << n2 << std::endl;  // 100 
    std::cout << "n3:" << n3 << std::endl;  // 200 
    n2 = std::move(n3);                      
    std::cout << "n2:" << n2 << std::endl;  // 200 
    std::cout << "n3:" << n3 << std::endl;  // 0 

    return 0;
}
