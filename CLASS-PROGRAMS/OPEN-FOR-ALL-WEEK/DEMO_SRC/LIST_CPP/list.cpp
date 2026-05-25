#include "list.hpp"

// get_node(data) == new node(data) + node::node(data)
node::node(int _data) : data(_data), prev(0), next(0){

}

// create_list() == get_node(0) + list::list()
list::list() : head_node(new node){
    head_node->prev = head_node; 
    head_node->next = head_node; 
} 

list::~list(){
    node* run = 0; 
    node* run_next = 0; 

    for(run = head_node->next; run != head_node; run = run_next){
        run_next = run->next; 
        delete run; 
    }

    delete head_node; 
}

status_t list::insert_start(data_t new_data){
    generic_insert(head_node, new node(new_data), head_node->next); 
    return SUCCESS; 
}

status_t list::insert_end(data_t new_data){
    generic_insert(head_node->prev, new node(new_data), head_node); 
    return SUCCESS;        
}

status_t list::insert_after(data_t existing_data, data_t new_data){
    node* e_node = 0; 

    e_node = search_node(existing_data); 
    if(e_node == 0)
        return LIST_INVALID_DATA; 

    generic_insert(e_node, new node(new_data), e_node->next); 
    return SUCCESS; 
}

status_t list::insert_before(data_t existing_data, data_t new_data){
    node* e_node = 0; 

    e_node = search_node(existing_data); 
    if(e_node == 0)
        return LIST_INVALID_DATA; 

    generic_insert(e_node->prev, new node(new_data), e_node); 
    return SUCCESS; 
}

status_t list::get_start(data_t* p_start_data){
    if(is_empty())
        return LIST_EMPTY; 
    *p_start_data = head_node->next->data; 
    return SUCCESS; 
}

status_t list::get_end(data_t* p_end_data){
    if(is_empty())
        return LIST_EMPTY;
    *p_end_data = head_node->prev->data; 
    return SUCCESS;
}

status_t list::pop_start(data_t* p_start_data){
    if(is_empty())
        return LIST_EMPTY;
    *p_start_data = head_node->next->data; 
    generic_delete(head_node->next); 
    return SUCCESS; 
}

status_t list::pop_end(data_t* p_end_data){
    if(is_empty())
        return LIST_EMPTY;
    *p_end_data = head_node->prev->data; 
    generic_delete(head_node->prev); 
    return SUCCESS;
}

status_t list::remove_start(){
    if(is_empty())
        return LIST_EMPTY;
    generic_delete(head_node->next); 
    return SUCCESS; 
}

status_t list::remove_end(){
    if(is_empty())
        return LIST_EMPTY;
    generic_delete(head_node->prev); 
    return SUCCESS; 
}

status_t list::remove_data(data_t r_data){
    node* e_node = 0; 

    e_node = search_node(r_data); 
    if(e_node == 0)
        return LIST_INVALID_DATA; 

    generic_delete(e_node); 
    return SUCCESS; 
}

bool list::is_empty() const{
    return head_node->prev == head_node && head_node->next == head_node; 
}

bool list::find(data_t f_data) const{
    node* f_node = 0;

    f_node = search_node(f_data); 
    return (f_node != 0); 
}

len_t list::length() const{
    len_t L = 0; 

    for(node* run = head_node->next; run != head_node; run = run->next)
        L += 1; 
    return L; 
}

list::iterator list::begin() const {
    list::iterator iter(head_node->next); 
    return iter; 
}

list::iterator list::end() const {
    list::iterator iter(head_node); 
    return iter; 
}

list::iterator::iterator(node* _node) : current_node(_node){

}

list::iterator& list::iterator::operator++(){
    current_node = current_node->next; 
    return *this;
}

list::iterator list::iterator::operator++(int){
    list::iterator tmp(current_node); 
    current_node = current_node->next; 
    return tmp; 
}

list::iterator& list::iterator::operator--(){
    current_node = current_node->prev; 
    return *this;
}

list::iterator list::iterator::operator--(int){
    list::iterator tmp(current_node); 
    current_node = current_node->prev; 
    return tmp; 
}

int list::iterator::operator*(){
    return current_node->data; 
}

bool list::iterator::operator==(const list::iterator& rhs){
    return current_node == rhs.current_node; 
}

bool list::iterator::operator!=(const list::iterator& rhs){
    return current_node != rhs.current_node; 
}

std::ostream& operator<<(std::ostream& os, const list& list_object){
    os << "[START]<->"; 
    for(
        node* run = list_object.head_node->next; 
        run != list_object.head_node; 
        run = run->next
    )
        os << "[" << run->data << "]<->"; 

    os << "[END]" << std::endl; 
    return os; 
}

void list::generic_insert(node* p_start, node* p_mid, node* p_end){
    p_mid->next = p_end; 
    p_mid->prev = p_start; 
    p_start->next = p_mid; 
    p_end->prev = p_mid; 
    
}

void list::generic_delete(node* p_delete_node){
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    delete p_delete_node; 
}

node* list::search_node(data_t search_data) const{
    for(node* run = head_node->next; run != head_node; run = run->next)
        if(run->data == search_data)
            return run; 
    return 0; 
}
