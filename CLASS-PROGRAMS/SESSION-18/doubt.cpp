#include <iostream> 

class Test 
{
    private: 
        int x, y, z; 
    public: 
        Test() : x(10), y(20), z(30)
        {

        }

        void func() 
        {
            x = 1000;  
            y = 2000; 
            z = 3000; 
        }

        static void func2()
        {
            // x = 1000; 
            Test myObject; 

            myObject.x = 1000; 

            // NOT ALLOWED 
            // this->x 
            // this->y 
            // this->z 
            // x 
            // y
            // z
        }
}; 

int main(void)
{
    Test t; 
    t.func(); // &t
    // Test::func(); // NOT ALLOWED 

    Test::func2(); 
    t.func2(); 

}