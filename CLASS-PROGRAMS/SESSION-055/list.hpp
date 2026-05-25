namespace cpa 
{
    namespace dsa 
    {
        template <typename T> 
        class snode 
        {
            template <typename T> 
            friend class slist<T>; 

            private: 
                T data;
                snode<T>* next; 
                snode(T const& _data) : data(_data), next(nullptr)f
                {

                }
        }; 

        template <typename T> 
        class slist 
        {
            private: 
                snode<T>* head_node; 
                void generic_insert(snode<T>* start_node, snode<T>* new_node, snode<T>* end_node); 
                void generic_delete(snode<T>* p_delete_node); 
                snode<T>* search_node(T const& data); 

            public: 
                slist() : head_node(new snode(T()))
                {

                }

                void insert_start(T const& data); 
                void insert_end(T const& data); 
                void insert_after(T const& e_data, T const& new_data); 
                void insert_before(T const& e_data, T const& new_data); 


                //  
                friend std::ostream& operator<<(std::ostream& os, slist<T>& lst_object); 

                class iterator 
                {
                    private: 
                        snode<T>* current_node; 
                    public: 
                        iterator(); 
                        iterator(snode<T>* _node); 

                        iterator operator++(); 
                        iterator operator++(int); 

                        iterator operator--(); 
                        iterator operator--(int); 

                        T& operator*() const; 

                        bool operator==(const iterator& other) const; 
                        bool operator!=(const iterator& other) const; 
                }; 

                iterator begin(); 
                iterator end(); 

                //  const_iterator -> cbegin() cend() 
                //  reverse_iterator -> rbegin() rend() 
                //  const_reverse_iterator -> crbegin() crend() 
        }; 
    }
}