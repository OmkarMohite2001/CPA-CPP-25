#include <iostream>

// final on a virtual function: prevents further overriding
class B1{
	public:
		virtual void f() {}
};

class B2 : public B1{
	public:
		void f() override {}
};

class B3 : public B2{
	public:
		void f() final {
			// no class below B3 can override f()
		}
};

// class B4 : public B3{
// 	public:
// 		void f() {} 	// error: f() is final in B3
// };

// final on a class: prevents further inheritance
class X final{
	public:
		void do_work(){}
};

// class Y : public X{}; 	// error: X is final

int main(void){
	B3 b;
	b.f();

	X x;
	x.do_work();

	return (0);
}
