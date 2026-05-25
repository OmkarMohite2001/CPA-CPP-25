// not a full proof implementation 
// focus on keyword static 

#include <iostream> 
#include <stdexcept>

class Singleton
{
    private: 
        int num; 
        double val; 
        static Singleton* pSingleton; 
    
        Singleton(int _num, int _val)
        {
            if(this != pSingleton)
            {
                throw std::runtime_error("Cannot create another object from singleton class"); 
            }
            this->num = _num; 
            this->val = _val; 
        }

    public: 
        static Singleton* getInstance(int _num, int _val) 
        {
            if(pSingleton != 0)
            {
              
                return pSingleton; 
            }
            else
            {
                pSingleton =  new Singleton(_num, _val); 
                return pSingleton; 
            } 
        }
}; 

Singleton* Singleton::pSingleton = 0; 

int main(void)
{

    return 0; 
}