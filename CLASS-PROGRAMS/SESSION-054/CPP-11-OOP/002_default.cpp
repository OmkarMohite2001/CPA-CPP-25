#include <iostream>

class node{
	private:
		int data;
		node* prev;
		node* next;
	public:
		// defaulted inside class body: inlined
		node() = default;
		node(const node&) = default;
		node(node&&) = default;
		node& operator=(const node&) = default;
		node& operator=(node&&) = default;
		node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class bst_node{
	private:
		int data;
		bst_node* left;
		bst_node* right;
		bst_node* parent;
	public:
		bst_node();
		bst_node(int);
};

// defaulted outside class body: not inlined by default
bst_node::bst_node() = default;
bst_node::bst_node(int data) : data(data), left(nullptr), right(nullptr), parent(nullptr){
}

int main(void){
	node N1(500);
	bst_node N2(1000);
	return (0);
}

