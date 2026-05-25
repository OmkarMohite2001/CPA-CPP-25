class bst_node
{
    friend class bst; 
    protected: 
        int data; 
        bst_node* left, *right, *parent; 
        bst_node(int _data) : data(_data), left(0), right(0), parent(0); 
}; 


class avl_node: public bst_node 
{
    friend class avl_tree; 
    protected: 
        avl_node(int _data) : bst_node(_data) 
        {

        }
}; 

class avl_tree 
{
    private:
        avl_node* root_node; 

    public: 
        void insert(int new_data)
        {
            this->root_node->data; // left, right, parent 
        }
}; 