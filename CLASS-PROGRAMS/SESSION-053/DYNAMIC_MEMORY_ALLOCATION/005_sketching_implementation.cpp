#include <iostream>

// Sketch of how shared_ptr works internally

namespace cpa{
	template <typename T>
	class T_ptr{
		public:
			T* p;
			std::size_t ref_cnt;

			T_ptr(T _val) : p(new T(_val)), ref_cnt(1){
			}

			~T_ptr(){
				delete p;
				p = nullptr;
			}
	};

	template <typename T>
	class shared_ptr{
		private:
			T_ptr<T>* ptr;
		public:
			shared_ptr(T val) : ptr(new T_ptr<T>(val)){
			}

			shared_ptr(const shared_ptr<T>& other){
				this->ptr = other.ptr;
				this->ptr->ref_cnt += 1;
			}

			shared_ptr<T>& operator=(const shared_ptr<T>& other){
				if(this != &other){
					this->ptr->ref_cnt -= 1;
					if(this->ptr->ref_cnt == 0)
						delete this->ptr;
					this->ptr = other.ptr;
					this->ptr->ref_cnt += 1;
				}
				return *this;
			}

			~shared_ptr(){
				if(--this->ptr->ref_cnt == 0)
					delete this->ptr;
			}

			T& operator*(){
				return *(this->ptr->p);
			}

			T* operator->(){
				return this->ptr->p;
			}

			std::size_t use_count() const {
				return this->ptr->ref_cnt;
			}
	};
}

int main(void){
	cpa::shared_ptr<int> p1(100);
	cpa::shared_ptr<int> p2(p1);
	cpa::shared_ptr<int> p3(p2);

	std::cout << "p1.use_count():" << p1.use_count() << std::endl;
	std::cout << "*p1 = " << *p1 << std::endl;

	return (0);
}
