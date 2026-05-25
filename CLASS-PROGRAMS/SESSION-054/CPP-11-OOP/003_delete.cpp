#include <iostream>

class T{
	private:
		int a;
		char b;
		int* p;

	public:
		T(int _a, int _b, int val): a(_a), b(_b), p(new int(val)) {}

		T() = default;

		T(const T& other) = delete;
		T& operator=(const T&) = delete;

		~T(){
			delete p;
		}
};

int main(void){
	T X1(10, 'A', 100);
	// T X2(X1); 	// CTE: attempting to access deleted method
	T X2(20, 'B', 200);
	// X1 = X2; 	// CTE: attempting to access deleted method

	return (0);
}
