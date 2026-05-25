#include <iostream> 
#include <typeinfo> 

class Date {}; 

Date D; 

int a[10]; 

Date arr[10]; 

Date* ptrDate; 

int* iPtr; 

int main()
{
    std::cout << "typeid(typeid(int)):" << typeid(typeid(int)).name() << std::endl; 
    std::cout << "type(int):" << typeid(int).name() << std::endl; 
    std::cout << "type(D):" << typeid(D).name() << std::endl; 
    std::cout << "type(a):" << typeid(a).name() << std::endl; 
    std::cout << "type(arr):" << typeid(arr).name() << std::endl; 
    std::cout << "type(ptrDate):" << typeid(ptrDate).name() << std::endl; 
    std::cout << "type(iPtr):" << typeid(iPtr).name() << std::endl; 
    
    int a = 10, b = 20; 
    std::cout << "type(a+b):" << typeid(a+b).name() << std::endl; 
    
    return 0; 
}