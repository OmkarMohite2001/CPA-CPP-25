#include <iostream>

class Base{
	public:
		virtual void f()  { std::cout << "Base::f()" << std::endl; }
		virtual void g() const { std::cout << "Base::g()" << std::endl; }
};

class Derived: public Base{
	public:
		void h() { std::cout << "Derived::h()" << std::endl; }

		void f() override {
			std::cout << "Derived::f():Enter" << std::endl;
			this->Base::f();
			std::cout << "Derived::f(): own logic" << std::endl;
			std::cout << "Derived::f(): leave" << std::endl;
		}

		void g() const override{
			std::cout << "Derived::g():Enter" << std::endl;
			std::cout << "Derived::g():leave" << std::endl;
		}
};

int main(void){
	Derived d;

	d.h(); 	// derived specific member
	d.f(); 	// extendor (overridden)
	d.g(); 	// replacor (overridden)

	return (0);
}
