#include <iostream>
#include <stdexcept>
#include <cstdlib>

class X{
	double num;

	// private target constructor: validates and stores
	X(double x){
		if(x <= 0.0)
			throw std::domain_error("Initializer cannot be negative");
		num = x;
	}

	public:
		// delegating constructors: forward to target
		X(const char* str_num) : X(atof(str_num)){
		}

		X(int _num) : X(static_cast<double>(_num)){
		}

		void show() const {
			std::cout << "num = " << num << std::endl;
		}
};

int main(void){
	X x1("100.454");
	x1.show();

	X x2(500);
	x2.show();

	try{
		X x3("-5544.54");
	}catch(std::domain_error& e){
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
