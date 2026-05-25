#include <iostream>

class Base{
	private:
		int x;
		int y;
	public:
		Base() : x(0), y(0) {}

		Base(int _x) : x(_x), y(0) {
			std::cout << "Base(int)" << std::endl;
		}

		Base(int _x, int _y) : x(_x), y(_y) {
			std::cout << "Base(int, int)" << std::endl;
		}

		void show() const {
			std::cout << "x=" << x << " y=" << y << std::endl;
		}
};

class Derived : public Base{
	private:
		int z;
	public:
		// inherit all constructors from Base
		using Base::Base;
        
		// Derived's own constructor
		Derived(int _x, int _y, int _z) : Base(_x, _y), z(_z){
			std::cout << "Derived(int, int, int)" << std::endl;
		}

		void show_all() const {
			show();
			std::cout << "z=" << z << std::endl;
		}
};

int main(void){
	Derived d1(10); 		// calls inherited Base(int)
	d1.show();

	Derived d2(10, 20); 	// calls inherited Base(int, int)
	d2.show();

	Derived d3(10, 20, 30); // calls Derived(int, int, int)
	d3.show_all();

	return (0);
}
