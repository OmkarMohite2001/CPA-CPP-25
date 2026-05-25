#include <iostream> 

namespace cpa 
{
    namespace dsa  
    {
        template <typename T> 
        class snode 
        {
            private: 
                T const& data; 
                snode* next; 
                snode(T const& _data); 
        }; 

        template <typename T> 
        class slist 
        {
            private: 
                snode<T>* head_node; 
            
            public: 
                slist()
                {

                }

                ~slist()
                {

                }

                slist(const slist<T>& other)
                {

                }

                slist<T>& operator=(const slist<T>& other)
                {

                }

                slist(slist<T>&& other)
                {

                }

                slist<T>& operator=(slist<T>&& other)
                {

                }

                void insert_start(const T& data)
                {

                }

                void insert_end(const T& data)
                {

                }

                void insert_after(const T& e_data, const T& new_data)
                {

                }

                void insert_before(const T& e_data, const T& new_data)
                {

                }

                void get_start(T* p_start_data)
                {

                }

                void get_end(T* p_end_data)
                {

                }

                void pop_start(T* p_start_data)
                {

                }

                void pop_end(T* p_end_data)
                {

                }

                void remove_start()
                {

                }

                void remove_end()
                {

                }

                void remove_data(T const& r_data)
                {

                }

                friend std::ostream& operator<<(std::ostream& os, const slist<T>& slist_object); 

                slist<T> operator+(const slist<T>& other); 
                void append(slist<T>& other); 

                slist<T> get_reversed_list() const; 
                void reverse(); 

                slist<T> merge(cosnt slist<T>& other); 
        }; 
    }; 
}

template <typename T> 
std::ostream& operator<<(std::ostream& os, const cpa::dsa::slist<T>& slist_object)
{

}

/* 
    List of DSA 
        Linear DSA: 
            1) Vector 
            2) Singly Linked List 
            3) Singly Circular Linked List 
            4) Doubly Linked List 
            5) Doubly Circular Linked List 
            [In all four linked list all four iterators must be implemented 
                iterator, const_iterator, reverse_iterator, const_reverse_iterator]
                begin(), end(), rbegin(), rend(), cbegin(), cend(), crbegin() crend()] 
        Adaptor: 
            Using Interface of Doubly Circular Linked List 
            6) Stack 
            7) Queue 
            8) Dequeue 
            9) Priority Queue 
            10) HashQueue (Vector + Doubly Circular Linked List)
        Non-Linear DSA: 
            1) Binary Search Tree: 
                a) create() b) destroy() c) preorder_r() d) preorder_nrc() 
                e) inorder_r() f) inorder_nrc() g) postorder_r() h) postorder_nrc() 
                i) inorder_predecessor() j) inorder_successor() k) preorder_predecessor() 
                l) preorder_successor() m) postorder_predecessor() n) postorder_successor() 
                o) search() p) remove() q) insert() r) min s) max 
                [
                    inorder, preorder, postorder
                ]

                for(bst<T>::inorder_iterator iter = inorder_begin(); iter != inorder_end(); ++iter)
                {
                    *iter; 
                }

            2)  GRAPH 
                    create(), destroy(), show_graph(), get_nr_vertices(), get_nr_edges(),
                    add_vertex(), remove_vertex(), add_edge(), remove_edge(), 
                    dfs(), bfs(), 

                    # ADVANCED 
                    dijkstra(), bellman_ford(directed graph)

                    prims, kruskal 

                    ford-fulkerson 

                    network-flow 

            3)  Height / Weight Balance Tree 
                a) RB-tree 
                b) AVL-Tree 

*/