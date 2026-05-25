#include <iostream>
#include <memory>
#include <cstdio>

void unique_ptr_demo_1(void);

int main(void){
	unique_ptr_demo_1();
	return (0);
}

void unique_ptr_demo_1(void){
	std::unique_ptr<int> pu1;

	if(pu1.get() == nullptr)
		std::cout << "pu1 contains null" << std::endl;

	std::unique_ptr<int> pu2(new int(500));
	printf("*pu2:%d\n", *pu2);
	pu2 = nullptr;
	if(pu2.get() == nullptr)
		printf("pu2 contains null\n");

	// release(): returns raw pointer and relinquishes ownership
	std::unique_ptr<int> pu3(new int(600));
	int* p_int = pu3.release();
	printf("*p_int:%d\n", *p_int);

	if(pu3.get() == nullptr)
		printf("pu3 is null\n");

	delete p_int;
	p_int = nullptr;

	// reset(): destroys managed object
	std::unique_ptr<int> pu4(new int(700));
	pu4.reset();
	if(pu4.get() == nullptr)
		printf("pu4 is null\n");

	// reset(new_ptr): destroys old, takes ownership of new
	std::unique_ptr<int> pu5(new int(800));
	pu5.reset(new int(900));
	printf("*pu5:%d\n", *pu5);
}
