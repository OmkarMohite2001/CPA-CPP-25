#include <iostream>
#include <memory>

// weak_ptr: non-owning observer of a shared_ptr
// does not affect reference count
// must be converted to shared_ptr via lock() before use

void test_basic_weak_ptr(void);

int main(void){
	test_basic_weak_ptr();
	return (0);
}

void test_basic_weak_ptr(void){
	std::shared_ptr<int> sp = std::make_shared<int>(42);
	std::weak_ptr<int> wp = sp;

	std::cout << "sp.use_count():" << sp.use_count() << std::endl; 	// 1, wp doesn't count

	// lock() returns a shared_ptr; empty if object is gone
	if(auto locked = wp.lock()){
		std::cout << "value:" << *locked << std::endl;
		std::cout << "sp.use_count():" << sp.use_count() << std::endl; 	// 2 (sp + locked)
	}
	// locked goes out of scope, back to 1

	std::cout << "expired? " << wp.expired() << std::endl; 	// 0 (false)

	sp = nullptr; 	// destroy the managed object

	std::cout << "expired? " << wp.expired() << std::endl; 	// 1 (true)

	if(auto locked = wp.lock())
		std::cout << "value:" << *locked << std::endl;
	else
		std::cout << "object has been destroyed" << std::endl;
}

