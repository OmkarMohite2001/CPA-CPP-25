#ifndef _ILIST_HPP 
#define _ILIST_HPP

const int SUCCESS = 1; 
const int LIST_INVALID_DATA = 2;
const int LIST_EMPTY = 3; 

typedef int status_t; 
typedef int data_t; 
typedef size_t len_t;

class IList{
    public: 
        virtual status_t insert_start(data_t new_data)                  =   0; 
        virtual status_t insert_end(data_t new_data)                    =   0; 
        virtual status_t insert_after(data_t e_data, data_t new_data)   =   0; 
        virtual status_t insert_before(data_t e_data, data_t new_data)  =   0; 

        virtual status_t get_start(data_t* p_data)                      =   0; 
        virtual status_t get_end(data_t* p_data)                        =   0; 

        virtual status_t pop_start(data_t* p_data)                      =   0; 
        virtual status_t pop_end(data_t* p_data)                        =   0; 

        virtual status_t remove_start()                                 =   0; 
        virtual status_t remove_end()                                   =   0; 
        virtual status_t remove_data(data_t e_data)                     =   0; 

        virtual len_t get_length() const                                =   0; 
        virtual bool find(data_t f_data) const                          =   0; 
        virtual bool empty() const                                      =   0; 

        virtual void show(const char* msg) const                        =   0; 
        virtual ~IList() {} // virtual destructor. it cannot be made pure 
                            // therefore, the empty definition 

        static IList* get_instance(void); 
        static void release_instance(IList* pIList); 
}; 

#endif // _ILIST_HPP

