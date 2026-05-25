#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdio>
#include <cstdlib>

class Date{
	private:
		int day, month, year;
	public:
		Date(int init_day, int init_month, int init_year) :
			day(init_day), month(init_month), year(init_year)
		{
		}

		void show() const {
			std::cout << day << "-" << month << "-" << year << std::endl;
		}
};

void defining_and_using_shared_ptr(void);
void get_swap_routines_of_shared_ptr(void);
void make_shared_demo(void);
void shared_ptr_reference_counting(void);

int main(void){
	defining_and_using_shared_ptr();
	get_swap_routines_of_shared_ptr();
	make_shared_demo();
	shared_ptr_reference_counting();
	return (EXIT_SUCCESS);
}

void defining_and_using_shared_ptr(void){
	std::shared_ptr<int> p_int(new int(100));
	std::shared_ptr<std::vector<int>> p_vec_int(new std::vector<int>(5, 100));

	std::cout << "*p_int = " << *p_int << std::endl;
	*p_int = 500;
	std::cout << "*p_int = " << *p_int << std::endl;

	puts("Showing vector:");
	for(std::vector<int>::size_type i = 0; i != p_vec_int->size(); ++i)
		std::cout << (*p_vec_int)[i] << std::endl;

	p_vec_int->push_back(600);
	p_vec_int->push_back(700);

	puts("Showing the modified vector");
	for(std::vector<int>::size_type i = 0; i != p_vec_int->size(); ++i)
		std::cout << (*p_vec_int)[i] << std::endl;
}

void get_swap_routines_of_shared_ptr(void){
	std::shared_ptr<std::vector<int>> p_vec_int1(new std::vector<int>);
	std::shared_ptr<std::vector<int>> p_vec_int2(new std::vector<int>);

	for(std::vector<int>::size_type i = 0; i != 5; ++i){
		p_vec_int1->push_back((i+1) * 10);
		p_vec_int2->push_back((i+1) * 5);
	}

	std::vector<int>* p_vec1 = p_vec_int1.get();
	std::vector<int>* p_vec2 = p_vec_int2.get();

	puts("Vector1:");
	for(std::vector<int>::size_type i = 0; i != p_vec1->size(); ++i)
		std::cout << "p_vec1->at(" << i << "):" << p_vec1->at(i) << std::endl;

	puts("Vector2:");
	for(std::vector<int>::size_type i = 0; i != p_vec2->size(); ++i)
		std::cout << "p_vec2->at(" << i << "):" << p_vec2->at(i) << std::endl;

	std::swap(p_vec_int1, p_vec_int2);
	p_vec1 = p_vec_int1.get();
	p_vec2 = p_vec_int2.get();

	puts("After swap - Vector1:");
	for(std::vector<int>::size_type i = 0; i != p_vec1->size(); ++i)
		std::cout << "p_vec1->at(" << i << "):" << p_vec1->at(i) << std::endl;

	puts("After swap - Vector2:");
	for(std::vector<int>::size_type i = 0; i != p_vec2->size(); ++i)
		std::cout << "p_vec2->at(" << i << "):" << p_vec2->at(i) << std::endl;
}

void make_shared_demo(void){
	std::shared_ptr<int> p_int = std::make_shared<int>(10);
	std::shared_ptr<std::string> p_string = std::make_shared<std::string>("Hello!");
	std::shared_ptr<Date> p_date = std::make_shared<Date>(10, 10, 2021);

	std::cout << "*p_int = " << *p_int << std::endl
			  << "*p_string = " << *p_string << std::endl;
	p_date->show();
}

void shared_ptr_reference_counting(void){
	std::shared_ptr<int> p1 = std::make_shared<int>(100);
	std::shared_ptr<int> p2(p1);
	std::shared_ptr<int> p3 = p1;

	std::cout << "p1.use_count():" << p1.use_count() << std::endl
			  << "p2.use_count():" << p2.use_count() << std::endl
			  << "p3.use_count():" << p3.use_count() << std::endl;

	
	p1 = nullptr; 
	std::cout << "After p1 = nullptr:" << std::endl;
	std::cout << "p1.use_count():" << p1.use_count() << std::endl
			  << "p2.use_count():" << p2.use_count() << std::endl
			  << "p3.use_count():" << p3.use_count() << std::endl;

	p2 = nullptr;
	p3 = nullptr;
	std::cout << "After all nulled:" << std::endl;
	std::cout << "p1.use_count():" << p1.use_count() << std::endl
			  << "p2.use_count():" << p2.use_count() << std::endl
			  << "p3.use_count():" << p3.use_count() << std::endl;
}




