#include <iostream> 

class IntPtr 
{
    friend class HasPtr; 
    private: 
        int* p; 
        unsigned int reference_count; 
        IntPtr(int _m) : p(new int(_m)), reference_count(1) {} 
        ~IntPtr() { delete p; } 
}; 

class HasPtr
{
    private: 
        int n; 
        IntPtr* pIntPtr; 

    public: 
        HasPtr(int _n, int _m) : n(_n), pIntPtr(new IntPtr(_m)) 
        {
        }

        HasPtr(const HasPtr& other) : n(other.n), pIntPtr(other.pIntPtr)
        {
            pIntPtr->reference_count += 1; 
        }

        HasPtr& operator=(const HasPtr& other)
        {
            if(this != &other)
            {
                n = other.n; 
                if(--pIntPtr->reference_count == 0)
                    delete pIntPtr; 
                pIntPtr = other.pIntPtr; 
                pIntPtr->reference_count += 1;             
            }

            return *this; 
        }

        ~HasPtr() 
        {
            std::cout << "In HasPtr::~HasPtr()" << std::endl; 
            if(--pIntPtr->reference_count == 0)
            {
                std::cout << "Deleting shared pIntPtr" << std::endl; 
                delete pIntPtr;   
            } 
        }

        unsigned int getrefcount() const 
        {
            return pIntPtr->reference_count;   
        }
}; 

void test(); 

int main()
{
    test(); 
    return 0;
}

void test() 
{
    HasPtr* php1 = new HasPtr(100, 200); 
    std::cout << "php1->getrefcount():" << php1->getrefcount() << std::endl; 
    HasPtr* php2 = new HasPtr(*php1); 
    std::cout << "php1->getrefcount():" << php1->getrefcount() << std::endl; 
    HasPtr* php3 = new HasPtr(*php2); 
    std::cout << "php1->getrefcount():" << php1->getrefcount() << std::endl; 

    HasPtr* php4 = new HasPtr(300, 400); 
    std::cout << "php4->getrefcount():" << php4->getrefcount() << std::endl; 
    HasPtr* php5 = new HasPtr(*php4); 
    std::cout << "php4->getrefcount():" << php4->getrefcount() << std::endl; 

    delete php3; 
    php3 = 0; 
    std::cout << "php1->getrefcount():" << php1->getrefcount() << std::endl; 
    delete php2;
    php2 = 0;  
    std::cout << "php1->getrefcount():" << php1->getrefcount() << std::endl; 
    delete php1;
    php1 = 0;  

    delete php5; 
    php5 = 0; 
    std::cout << "php4->getrefcount():" << php4->getrefcount() << std::endl; 
    delete php4; 
    php4 = 0; 
}
