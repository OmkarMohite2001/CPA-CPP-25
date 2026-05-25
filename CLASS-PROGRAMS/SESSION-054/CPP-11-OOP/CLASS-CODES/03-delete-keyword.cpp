#include <iostream> 

class node 
{
    friend class list; 
    private: 
        int data; 
        node* prev; 
        node* next; 
    public: 
        node(const node& other) 
        {
            throw std::runtime_error("error"); 
        }

        node& operator=(const node& other)
        {
            throw std::runtime_error("erorr"); 
        }
}; 

class list 
{
    private: 
        node* head_node; 
}; 

