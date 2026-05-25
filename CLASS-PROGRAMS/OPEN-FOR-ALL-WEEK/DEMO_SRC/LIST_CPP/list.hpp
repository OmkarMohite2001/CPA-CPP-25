#ifndef _LIST_HPP 
#define _LIST_HPP 

#include <iostream> 
#include <cstdlib>
#include <cassert> 

// Symbolic constats 
const int SUCCESS = 1; 
const int LIST_INVALID_DATA = 2; 
const int LIST_EMPTY = 3; 

// typedefs 
typedef int data_t; 
typedef int status_t; 
typedef unsigned int len_t; 

// type definitions 
class node{
    friend class list; 
    friend std::ostream& operator<<(std::ostream& os, const list& list_object); 
    private: 
        data_t data; 
        node* prev; 
        node* next; 
        node(data_t _data = 0); 
}; 

class list{
    private: 
        node* head_node;    // this->head_node == p_list in C version 
        static void generic_insert(node* p_start, node* p_mid, node* p_end); 
        static void generic_delete(node* p_delete_node); 
        node* search_node(data_t search_data) const; 
    public: 
        class iterator; 
        list();     // create_list() 
        ~list();    // destroy_list() 
        status_t insert_start(data_t new_data);
        status_t insert_end(data_t new_data);  
        status_t insert_after(data_t existing_data, data_t new_data) ; 
        status_t insert_before(data_t existing_data, data_t new_data); 
        status_t get_start(data_t* p_start_data); 
        status_t get_end(data_t* p_end_data); 
        status_t pop_start(data_t* p_start_data); 
        status_t pop_end(data_t* p_end_data); 
        status_t remove_start(); 
        status_t remove_end(); 
        status_t remove_data(data_t r_data); 
        bool is_empty() const; 
        bool find(data_t f_data) const; 
        len_t length() const; 
        friend std::ostream& operator<<(std::ostream& os, const list& list_object); 

        iterator begin() const; 
        iterator end() const; 

        class iterator{
            private: 
                node* current_node; 
            public: 
                iterator(node* _node); 
                iterator& operator++(); 
                iterator operator++(int); 
                iterator& operator--(); 
                iterator operator--(int); 
                int operator*(); 
                bool operator==(const iterator& rhs); 
                bool operator!=(const iterator& rhs); 
        }; 
}; 

#endif  // _LIST_HPP
