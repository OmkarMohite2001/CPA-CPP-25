#include <iostream> 
#include <cstdlib> 
#include <stdexcept> 

class list_invalid_data : public std::runtime_error
{
    public: 
        list_invalid_data(const char* msg); 
}; 

class list_empty : public std::runtime_error
{
    public: 
        list_empty(const char* msg); 
}; 

class node 
{
    friend class list; 
    friend std::ostream& operator<<(std::ostream& os, const list& lst_obj); 

    private: 
        int data; 
        node* prev; 
        node* next; 
        node(int new_data); 
}; 

// Implement move semantics 
// Take deep copying approach while implementing copy semantics 
class list 
{
    private: 
        node* p_head_node; 

        static void generic_insert(node* beg, node* mid, node* end); 
        static void generic_delete(node* delete_node); 
        node* search_node(int data); 

    public: 
        list();                     // default Ctor 
        
        ~list();                    // Dtor 1 

        list(const list& other);    // Copy Ctor 2 
        list(list&& other);         // move Ctor 3 

        list& operator=(const list& other);     // copy assignment operator 4 
        list& operator=(list&& other);          // move assignment operator 5 
        
        friend std::ostream& operator<<(std::ostream& os, const list& lst_obj); 

        void insert_start(int new_data); 
        void insert_end(int new_data);
        void insert_after(int e_data, int new_data); 
        void insert_before(int e_data, int new_data);  
        void remove_end(); 
        void remove_start();  
        void remove_data(int r_data); 
        bool find(int data) const; 
        bool is_empty() const; 
}; 

int main(void)
{
    list LL1; 
    // populate list LL1 with data 
    list LL2(LL1); // LL2 should be a clone of LL1 

    list LL3(std::move(LL2));   // linked list LL2 should get moved to linked list LL3 
                                // LL2 should be empty list 
    
    list LL4; 
    // populat LL4 with data 

    LL3 = LL4;  // LL3 will give up its current list 
                // and will store the CLONED list of LL4 

    LL4 = std::move(LL1);   // move linked list of LL1 to LL4 and make LL1 empty 


    return 0; 
}

node::node(int new_data) : data(new_data), prev(0), next(0)
{

} 

void list::generic_insert(node* beg, node* mid, node* end)
{
    mid->next = end; 
    mid->prev = beg; 
    beg->next = mid; 
    end->prev = mid; 
}

void list::generic_delete(node* delete_node)
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    delete delete_node;
}

node* list::search_node(int data)
{
    for(node* p_run = p_head_node->next; p_run != p_head_node; p_run = p_run->next)
        if(p_run->data == data)
            return p_run; 
    return nullptr; 
}

list::list() : p_head_node(new node(0))                // default Ctor 
{
    p_head_node->prev = p_head_node; 
    p_head_node->next = p_head_node; 
}

list::~list()                    // Dtor 1 
{
    node* p_run, *p_run_next; 
    
    for(p_run = p_head_node->next; p_run != p_head_node; p_run = p_run_next)
    {
        p_run_next = p_run->next; 
        delete p_run; 
    }

    delete p_head_node; 
    p_head_node = 0; 
}

list::list(const list& other)   // Copy Ctor 2 
{
    this->p_head_node = new node(0); 
    this->p_head_node->prev = this->p_head_node;
    this->p_head_node->next = this->p_head_node; 
    for(node* p_run = other.p_head_node->next; p_run != other.p_head_node; p_run = p_run->next)
        this->insert_end(p_run->data); 
}

// list new_list(std::move(existing_list)); 
list::list(list&& other) : p_head_node(other.p_head_node)   // move Ctor 3 
{
    other.p_head_node = new node(0); 
    other.p_head_node->prev = p_head_node; 
    other.p_head_node->next = p_head_node; 
}

list& list::operator=(const list& other)     // copy assignment operator 4 
{
    delete this; 
    this->p_head_node = new node(0); 
    this->p_head_node->prev = this->p_head_node; 
    this->p_head_node->next = this->p_head_node; 

    for(node* p_run = other.p_head_node->next; p_run != other.p_head_node; p_run = p_run->next)
        this->insert_end(p_run->data); 
    
    return *this; 
}

// existingLL = std::move(exsting_LL_rhs); 
list& list::operator=(list&& other)          // move assignment operator 5 
{
    delete this; 
    this->p_head_node = other.p_head_node; 
    other.p_head_node = new node(0); 
    other.p_head_node->prev = p_head_node; 
    other.p_head_node->next = p_head_node; 
}

std::ostream& operator<<(std::ostream& os, const list& lst_obj)
{
    os << "[START]<->"; 
    for(node* p_run = lst_obj.p_head_node->next; p_run != lst_obj.p_head_node; 
        p_run = p_run->next)
        os << "[" << p_run->data << "]<->"; 
    os << "[END]" << std::endl;  
    return os; 
}

void list::insert_start(int new_data)
{
    generic_insert(p_head_node, new node(new_data), p_head_node->next); 
}

void list::insert_end(int new_data)
{
    generic_insert(p_head_node->prev, new node(new_data), p_head_node); 
}

void list::insert_after(int e_data, int new_data)
{

}

void list::insert_before(int e_data, int new_data)
{
    
}

void list::remove_end()
{

}

void list::remove_start()
{

} 

void list::remove_data(int r_data)
{

}

bool list::find(int data) const
{
    node* p_run = const_cast<list*>(this)->search_node(data); 
    return (p_run != nullptr); 
}

bool list::is_empty() const
{
    return (p_head_node->prev == p_head_node && p_head_node->next == p_head_node); 
}

list_invalid_data::list_invalid_data(const char* msg) : std::runtime_error(msg)
{

}

list_empty::list_empty(const char* msg) : std::runtime_error(msg)
{
    
}

// C  
// DSA 
// Kerrisk, Hart 

// C++ : Primer 
// DSA in C++ : Tamassia 
// C++ Qt 
// C++ COM 
// C++ Boost 
// C++ STL 
// TEMPLATE PROGRAMMING DEPTH 

// C++ 11/14/17 

