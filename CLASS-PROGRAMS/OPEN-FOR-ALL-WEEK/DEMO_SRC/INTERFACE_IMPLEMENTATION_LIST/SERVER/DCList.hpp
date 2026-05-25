#include "IList.hpp"

class DCnode{
    friend class DCList; 
    private: 
        data_t data; 
        DCnode* prev; 
        DCnode* next; 
        DCnode(int new_data); 
}; 

class DCList : public IList{
    private: 
        DCnode* head_node; 

        static void generic_insert(DCnode* p_beg, DCnode* p_mid, DCnode* p_end); 
        static void generic_delete(DCnode* p_delete_node); 
        DCnode* search_node(data_t search_data) const; 

    public: 
        // ctor & dtor 
        DCList(); 
        ~DCList();

        // insert 
        status_t insert_start(data_t new_data); 
        status_t insert_end(data_t new_data); 
        status_t insert_after(data_t e_data, data_t new_data); 
        status_t insert_before(data_t e_data, data_t new_data); 

        // get
        status_t get_start(data_t* p_data); 
        status_t get_end(data_t* p_data); 

        // pop 
        status_t pop_start(data_t* p_data); 
        status_t pop_end(data_t* p_data); 

        // remove 
        status_t remove_start(); 
        status_t remove_end(); 
        status_t remove_data(data_t e_data); 

        // misc 
        len_t get_length() const; 
        bool find(data_t f_data) const; 
        bool empty() const; 
        void show(const char* msg) const;    
}; 