namespace cpa::dsa::tree 
{
    template <typename T> 
    class bst_node 
    {
        protected: 
            T data; 
            bst_node<T>* left; 
            bst_node<T>* right; 
            bst_node<T>* parent; 
    }; 

    template <typename T> 
    class bst 
    {

    };

    template <typename T> 
    class avl_node 
    {

    }; 

    template <typename T> 
    class avl 
    {

    }; 

    enum class color { RED, BLACK}; 

    template <typename T> 
    class rb_node : public class bst_node<T> 
    {
        private: 
            color node_color; 
    }; 

    template <typename T> 
    class rb_tree 
    {

    }; 
}
