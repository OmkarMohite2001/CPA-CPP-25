#include <iostream> 
#include "IList.hpp"
#include "DCList.hpp"

DCnode::DCnode(int new_data) : data(new_data), prev(0), next(0){
}

DCList::DCList() : head_node(new DCnode(0)){
    head_node->prev = head_node; 
    head_node->next = head_node;
}

DCList::~DCList(){
    DCnode* run = 0; 
    DCnode* run_next = 0; 

    for(run = head_node->next; run != head_node; run = run_next){
        run_next = run->next; 
        delete run; 
    }

    delete head_node; 
    head_node = 0; 
}

// insert 
status_t DCList::insert_start(data_t new_data){
    generic_insert(head_node, new DCnode(new_data), head_node->next); 
    return SUCCESS; 
}

status_t DCList::insert_end(data_t new_data){
    generic_insert(head_node->prev, new DCnode(new_data), head_node); 
    return SUCCESS; 
}

status_t DCList::insert_after(data_t e_data, data_t new_data){
    DCnode* e_node = search_node(e_data); 
    
    if(!e_node)
        return LIST_INVALID_DATA; 

    generic_insert(e_node, new DCnode(new_data), e_node->next); 
    return SUCCESS;
}

status_t DCList::insert_before(data_t e_data, data_t new_data){
    DCnode* e_node = search_node(e_data); 
    
    if(!e_node)
        return LIST_INVALID_DATA; 

    generic_insert(e_node->prev, new DCnode(new_data), e_node); 
    return SUCCESS; 
}

// get
status_t DCList::get_start(data_t* p_data){
    if(empty())
        return LIST_EMPTY; 
    
    *p_data = head_node->next->data; 
    return SUCCESS; 
}

status_t DCList::get_end(data_t* p_data){
    if(empty())
        return LIST_EMPTY;

    *p_data = head_node->prev->data; 
    return SUCCESS; 
}

// pop 
status_t DCList::pop_start(data_t* p_data){
    if(empty())
        return LIST_EMPTY;

    *p_data = head_node->next->data; 
    generic_delete(head_node->next); 
    return SUCCESS; 
}

status_t DCList::pop_end(data_t* p_data){
    if(empty())
        return LIST_EMPTY;

    *p_data = head_node->prev->data; 
    generic_delete(head_node->prev); 
    return SUCCESS; 
}

// remove 
status_t DCList::remove_start(){
    if(empty())
        return LIST_EMPTY;

    generic_delete(head_node->next); 
    return SUCCESS; 
}

status_t DCList::remove_end(){
    if(empty())
        return LIST_EMPTY;

    generic_delete(head_node->prev); 
    return SUCCESS; 
}

status_t DCList::remove_data(data_t e_data){
    DCnode* r_node = search_node(e_data); 

    if(!r_node)
        return LIST_INVALID_DATA; 

    generic_delete(r_node); 
    return SUCCESS;
}

// misc 
len_t DCList::get_length() const{
    DCnode* run = head_node->next; 
    len_t len = 0; 

    while(run != head_node){
        ++len; 
        run = run->next; 
    }

    return len; 
}

bool DCList::find(data_t f_data) const{
    DCnode* f_node = search_node(f_data); 
    return (f_node != 0); 
}

bool DCList::empty() const{
    return head_node->prev == head_node && head_node->next == head_node; 
}

void DCList::show(const char* msg) const{
    if(msg)
        std::cout << msg << std::endl; 

    std::cout << "[START]<->"; 
    for(DCnode* run = head_node->next; run != head_node; run = run->next)
        std::cout << "[" << run->data << "]<->"; 
    std::cout << "[END]" << std::endl; 
}

// private auxillary functions 
void DCList::generic_insert(DCnode* p_beg, DCnode* p_mid, DCnode* p_end){
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
}

void DCList::generic_delete(DCnode* p_delete_node){
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    delete p_delete_node;
}

DCnode* DCList::search_node(data_t search_data) const {
    DCnode* run = head_node->next; 

    for(; run != head_node; run = run->next)
        if(run->data == search_data)
            return run; 

    return 0; 
}

IList* IList::get_instance(void){
    return new DCList; 
}

void IList::release_instance(IList* pIList){
    delete pIList; 
}