#include <iostream> 

class HasPtr 
{
    private: 
        int n; 
        int* ptr; 

    public: 
        HasPtr(int _n, int _m) : n(_n), ptr(new int(_m))
        {
        }

        int getn() const 
        {
            return n; 
        }

        void setn(int new_n)
        {
            n = new_n; 
        }

        int get_ptr_val() const 
        {
            return *ptr; 
        }

        void set_ptr_val(int new_val)
        {
            *ptr = new_val; 
        }

        ~HasPtr() 
        {
            delete ptr; 
        }
}; 

void memory_leak_scenario(); 
void segfault_scenario(); 

int main() 
{
    // memory_leak_scenario(); 
    segfault_scenario(); 
    //  Control flow will not reach here 
    std::cout << "main():Application terminated successfully" << std::endl; 
    return 0; 
}

void memory_leak_scenario()
{
    std::cout << "----Entered memory_leak_scenario()----" << std::endl; 
    HasPtr hp1(100, 200); 
    HasPtr hp2(400, 500); 

    hp1 = hp2; 
    /* 
        hp1 = hp2; 
        will be internally converted to a synthesized copy assignment operator call 

        HasPtr::operator=(&hp1, hp2); 

        And synthesized copy assignment operator does memberwise assignment. 
        In effect the following will happen 
        hp1.n = hp2.n;      //  It will happen through 'this' pointer and 'other' reference variable
        hp1.ptr = hp2.ptr;  //  Lo' behold -> the memory leak ! 
    */
   std::cout << "----Leaving memory_leak_scenario()----" << std::endl; 
}

void segfault_scenario()
{
    std::cout << "----Entered segfault_scenario()----" << std::endl; 
    HasPtr* p_hp1 = new HasPtr(100, 200); 
    HasPtr* p_hp2 = new HasPtr(*p_hp1); //  Synthesized version of copy constructor will initialize 
                                        //  p_hp2->n by p_hp1->n and p_hp2->ptr by p_hp1->ptr 
                                        //  The former is not problematic, the later is a BIG RED FLAG. 
                                        //  p_hp1->ptr and p_hp2->ptr will SHARE THE INTEGER OBJECT 
                                        //  ALLOCATED ON HEAP WHILE EXECUTING CONSTRUCTOR FOR OBJECT 
                                        //  pointed by p_hp1 
                                        //  How does it lead to segfault? Refer to the following lines 


    delete p_hp1;   /*  
                        Object of class HasPtr pointed by p_hp1 will be freed but 
                        before that it will be passed through a destructor of HasPtr 
                        where the ptr member of object will be deleted resulting into 
                        the release of SHARED INTEGER OBJECT between p_hp1 and p_hp2 
                        After delete p_hp1 is complete if any member function invoked 
                        on p_hp2, DEREFERENCES its ptr member then it will result into 
                        a SEGMENTATION FAULT. 
                    */

    std::cout << "Ye Antim, Behoshi Antim, Saki Antim Pyala hai, Pathik Pyar se Pina Isko, Phir Na Milegi Madhushala" << std::endl; 
    // std::cout.flush(); 
    p_hp2->set_ptr_val(500);    //  !!! SEGMENTATION FAULT 
    delete p_hp2; 

    std::cout << "segfault_scenario() : this should not get executed" << std::endl; 
    std::cout << "----Leaving segfault_scenario()----" << std::endl; 
}
