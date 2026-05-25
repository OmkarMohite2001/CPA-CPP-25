#include <iostream> 

class cpa_array 
{
    private: 
        int* p_array; 
        int N; 

    public: 
        cpa_array(int size = 0) : N(size)
        {
            p_array = (N > 0) ? (new int [N]) : 0; 
        }

        cpa_array(std::initializer_list<int> lst)
        {
            N = lst.size(); 
            p_array = new int[N]; 
            int index = 0; 
            for(auto iter = lst.begin(); iter != lst.end(); ++iter)
                p_array[index++] = *iter;  
        }

        ~cpa_array()
        {
            if(p_array)
            {   delete[] p_array; 
                p_array = 0; 
                N = 0;
            }  
        }

        void move_to_empty_object(cpa_array& other)
        {
            //  This models case I of 01-move-semantics-prep.cpp 
            //  object pointed by 'this' -> is empty -> i.e. its p_array is NULL and N is 0 
            //  object referred by 'other' -> object from which to move the array 
            
            //  Following statements can be executed because the member functions of class 
            //  have access to their private data members 

            //  object referred by 'other' is transferring the ownership to object pointed by 'this' 
            this->p_array = other.p_array; 
            this->N = other.N; 

            //  object referred by 'other' is surrendering its claim over object 
            other.p_array = NULL; 
            other.N = 0; 
        }

        void move_to_nonempty_object(cpa_array& other)
        {
            //  This models case II of 01-move-semantics-prep.cpp 
            //  object pointed by 'this' -> is nonempty -> i.e. its p_array is not NULL and N > 0
            //  object referred by 'other' -> object from which to move the array 

            //  object pointed by 'this' will give up the ownership of its own array 
            delete[] this->p_array; 
            this->p_array = NULL; 
            this->N = 0; 

            //  object referred by 'other' will transfer its ownership to the object pointed by 'this' 
            this->p_array = other.p_array; 
            this->N = other.N; 

            //  object referred by other will surrender its ownership 
            other.p_array = NULL; 
            other.N = 0; 
        }

        friend std::ostream& operator<<(std::ostream& os, const cpa_array& arr_object); 
}; 

std::ostream& operator<<(std::ostream& os, const cpa_array& arr_object) 
{
    std::cout << std::endl; 
    for(int i = 0; i < arr_object.N; ++i)
        os << "arr[" << i << "]:" << arr_object.p_array[i] << std::endl; 
    return os; 
}

int main()
{
    cpa_array O1{100, 200, 300, 400, 500}; 
    cpa_array O2{1000, 2000, 3000, 40000, 5000, 6000, 7000, 8000}; 
    cpa_array O3; 

    std::cout << "Before moving O1 to O3:" << std::endl; 
    std::cout << "O3:" << O3; 
    std::cout << "O1:" << O1; 

    //  O3 is empty object. O1 wants to transfer ownership to O3 
    O3.move_to_empty_object(O1); 

    std::cout << "After moving O1 to O3:" << std::endl; 
    std::cout << "O3:" << O3; 
    std::cout << "O1:" << O1; 

    //  O3 wants to transfer ownership to O2 
    //  O2 is non-empty 
    std::cout << "Before moving O3 to O2:" << std::endl; 
    std::cout << "O3:" << O3 << std::endl; 
    std::cout << "O2:" << O2 << std::endl; 
    O2.move_to_nonempty_object(O3); 
    std::cout << "After moving O3 to O2:" << std::endl; 
    std::cout << "O3:" << O3 << std::endl; 
    std::cout << "O2:" << O2 << std::endl; 

    return 0; 
}