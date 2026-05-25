#include <iostream>
#include <string>

bool test(); 
void capture_by_value(); 
void capture_by_reference(); 
void implicit_captures(); 
void mutable_lambda(); 

int main(){
	bool b; 

	b = [] (std::string& a, std::string& b) -> bool 
			{ return a.size() > b.size();}(std::string("Hello,World"), std::string("abc")); 
	std::cout << "b:" << b << std::endl; 

	auto b2 = [](std::string& a, std::string& b) {
				return a.size() < b.size();
				} (std::string("abc"), std::string("pqrs")); 

	std::cout << "b2:" << b2 << std::endl; 

	test(); 
	capture_by_value(); 
	capture_by_reference(); 
	implicit_captures(); 
	mutable_lambda(); 

	return (0);  
}

bool test(){
	int loc = 500; 
	int kb; 

	std::cout << "enter kb:"; 
	std::cin >> kb; 

	auto b = [loc, kb] () -> bool { return kb > loc; } (); 
	std::cout << "test():b:" << b << std::endl; 

	return b; 
}

void capture_by_value(){
	int v1 = 42; 
	auto f = [v1]()->int{
				return v1;
			}; 
	v1 = 500; 
	auto v2 = f(); 
	std::cout << "v2:" << v2 << std::endl; 
}

void capture_by_reference(){
	int v1 = 500; 
	auto f = [&v1]() { return v1; }; 
	v1 = 600; 
	auto v2 = f(); 
	std::cout << "v2:" << v2 << std::endl; 
} 

void implicit_captures(){
	int i = 100, j = 200, k = 300; 
	
	auto f = [=]() { std::cout << "i:" << i << " j:" << j << " k:" << k << std::endl; }; 
	auto g = [&]() { std::cout << "i:" << i << " j:" << j << " k:" << k << std::endl; }; 
	
	f(); 
	g(); 

	i = 1000; 
	j = 2000; 
	k = 3000; 

	f(); 
	g(); 
}

// [] -> empty capture list 
// [names] -> caputure list names, by default capture by value, if &name then capture by ref
// [=] -> default capture : all by value 
// [&] -> all default captures by reference 
// [&, identifier names] -> all default captures by reference, explicit capture by value 
// [=, reference list] -> all default captures by value, explicit capture by ref 

void mutable_lambda(){
	int i = 42; 
	auto f = [i] () mutable -> int{ return ++i; }; 
	i = 0; 
	auto j = f(); 
	std::cout << "j:" << j << std::endl; 
	std::cout << "i:" << i << std::endl; 
}

/*
[&/=, capture_list](formal parameters) -> return type {BODY}; 

[capture list](formal parameters) -> return_type {BODY}; 



[=, &N1, ..., &Nk](T1 fp1, ...., Tn fpn)->return_type{		}
[&, N1, ..., Nk](T1 fp1, ...., Tn fpn)->return_type{		}
[=, &N1, ..., &Nk](T1 fp1, ...., Tn fpn)mutable->return_type{		}
[&, N1, ..., Nk](T1 fp1, ...., Tn fpn)mutable->return_type{		}
*/ 

