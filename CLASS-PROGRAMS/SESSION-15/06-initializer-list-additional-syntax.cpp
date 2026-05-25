#include <iostream> 
#include <cstdlib> 

class Test_1
{
    private: 
        int m, n; 
        double x, y; 

    public:
        Test_1() : m(100), n(200), x(1.0), y(2.0)
        {

        }
}; 

class Test_2
{
    private: 
        int m, n; 
        double x, y; 

    public:
        Test_2() : m(100), n(200)
        {
            x = 1.1; 
            y = 2.2; 
        }
};

class Test_3
{
    private: 
        int m, n; 
        double x, y; 

    public:
        Test_2() : m(100), x(1.1)
        {
            n = 200; 
            y = 2.2; 
        }
}; 

class Random
{
    private: 
        int n1, n2; 

    public: 
        Random() : n1(rand()), n2(rand())
        {

        }

        void show() 
        {
            std::cout << "n1:" << n1 << std::endl 
                        << "n2:" << n2 << std::endl; 
        }
}; 