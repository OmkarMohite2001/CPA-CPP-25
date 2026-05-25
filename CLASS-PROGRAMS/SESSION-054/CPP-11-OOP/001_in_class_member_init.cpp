#include <iostream>

class node{
	private:
		int data = 0;
		node* prev = nullptr;
		node* next = nullptr;
	public:
		node() = default;

		node(int _data) : data(_data){
			// prev and next already initialized to nullptr
		}

		void show() const {
			std::cout << "data:" << data
					  << " prev:" << prev
					  << " next:" << next << std::endl;
		}
};

class Config{
	private:
		int width = 800;
		int height = 600;
		bool fullscreen = false;
		double scale = 1.0;
	public:
		Config() = default; 	// uses all in-class defaults

		Config(int w, int h) : width(w), height(h){
			// fullscreen and scale keep their defaults
		}

		void show() const {
			std::cout << width << "x" << height
					  << " fullscreen:" << fullscreen
					  << " scale:" << scale << std::endl;
		}
};

int main(void){
	node N1;
	node N2(500);
	N1.show();
	N2.show();

	Config c1;
	Config c2(1920, 1080);
	c1.show();
	c2.show();

	return (0);
}
