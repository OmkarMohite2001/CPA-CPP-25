#include <iostream>
#include <memory>

// Circular reference problem: A holds shared_ptr<B>, B holds shared_ptr<A>
// Neither can be destroyed -> memory leak
// Solution: break the cycle with weak_ptr

class B; 	// forward declaration

class A{
	private:
		std::shared_ptr<B> sP1;

	public:
		A() { std::cout << "A()" << std::endl; }
		~A() { std::cout << "~A()" << std::endl; }

		void setShared(std::shared_ptr<B>& p){
			sP1 = p;
		}
};

class B{
	private:
		std::weak_ptr<A> wP1; 	// weak_ptr breaks the cycle

	public:
		B() { std::cout << "B()" << std::endl; }
		~B() { std::cout << "~B()" << std::endl; }

		void setWeak(std::shared_ptr<A>& p){
			wP1 = p;
		}
};

void test(void);

int main(void){
	test();
	std::cout << "Both A and B were properly destroyed" << std::endl;
	return (0);
}

void test(void){
	std::shared_ptr<A> aPtr(new A);
	std::shared_ptr<B> bPtr(new B);
	aPtr->setShared(bPtr);
	bPtr->setWeak(aPtr);
}
