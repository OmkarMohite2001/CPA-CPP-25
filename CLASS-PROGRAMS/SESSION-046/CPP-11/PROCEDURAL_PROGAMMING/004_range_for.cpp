#include <iostream>
#include <vector> 

template <typename T> 
void show(std::vector<T>& vec){
    for(const auto& v : vec)
        std::cout << "v:" << v << std::endl; 
}

int main(void){
    std::vector<int> ivec{10, 20, 30, 40}; 
    show(ivec); 

    std::vector<char> cvec {'a', 'b', 'c', 'd'}; 
    show(cvec); 

    for(auto& v : ivec)
        v = 100; 
    show(ivec); 

    std::cout << "auto v : ivec pattern" << std::endl;
    for(auto v : ivec)
    {
        std::cout << "Before: v:" << v << std::endl; 
        v = 500; 
        std::cout << "After: v:" << v << std::endl; 
        
    }

    show(ivec);

    for(auto& v : cvec)
        v = 'A'; 
    show(cvec);

    return 0;  
}

// for(typeof(containee)& v : containter)

/*
void f()
{
    std::vector<int> ivec; 

    for(int i = 0; i < 5; ++i)
        ivec.push_back((i+1) * 100); 

    for(int& v : ivec)
        std::cout << v << std::endl; // potential for r/w

    for(const int& v : ivec)
        std::cout << v << std::endl;    // potential for r only

    for(auto& v: ivec)
    {
        // potential for r/w
    }

    for(const auto& v : ivec)
    {
        // potential for r only 
    }

    std::vector<int> ivec1; 
    std::vector<int> ivec2(5); 
    std::vector<int> ivec3(5, 100); 
    std::vector<int> ivec4(ivec3); 
}
*/

/*
    for (auto v : ivec)
    {
        // do something with v 
    }

    for(auto& v : ivec)
    {
        // action on v 
    }
    == 

    for(std::vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter) 
    {
        int& v = *iter; 

        // action on v
    }

    for(auto v : container)
    {
        //  each element of the container will be copied to v 
        //  Action on v will be reflected on the clone of the elements 
        //  in the container 

        //  You can perform both mutable and immutable operations on clone 
    }

    for(auto& v : container)
    {
        //  reference variable v will latch itself to every element in the 
        //  container turn by turn 

        //  Any action performed on v will be reflected on the element present in 
        //  the container 

        //  On v you can perform mutable & immutable operations 
    }

    for(const auto& v : container)
    {
        //  reference variable v will latch itself to every element in the 
        //  container turn by turn 

        //  Any action performed on v will be reflected on the element present in 
        //  the container 

        //  You can perform only immutable operations on v 
    }
*/