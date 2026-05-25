#include <iostream>
#include <typeinfo>

class Base{
	public: 
		virtual void f() {} 
}; 

class Derived : public Base {
public: 
	Derived() : Base() {} 
	void g(){} 
}; 

int main(void){
	int a; 
	decltype(a) b; 

	std::cout << "typeid(a):" << typeid(a).name() << std::endl; 
	std::cout << "typeid(b):" << typeid(b).name() << std::endl; 

	Base* pB = new Derived; 
	decltype(*pB) D1 = *pB; 
	decltype(pB) X; 

	std::cout << "typeinfo(D1):" << typeid(D1).name() << std::endl; 
	std::cout << "typeinfo(X):" << typeid(X).name() << std::endl; 
	return (0); 
}

// <type annotation> v; 

// decltype(expr) v; 

// int v; 
// std::vector<int> ivec; 
// decltype(v) X; 

