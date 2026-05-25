#include <iostream> 

class Test
{
    private: 
        int num1; 
        const int num2; 
        static const int num3; 
        
    public: 
        Test(int x, int y) : num2(y)
        {
            num1 = x; 
            // num2 = y;    // CTE : LHS must be a modifiable l-value
        }

        void show() 
        {
            std::cout << "num1:" << num1 << std::endl
                        << "num2:" << num2 << std::endl 
                        << "num3:" << num3 << std::endl; 
        }
}; 

const int Test::num3 = 100; 

int main(void)
{
    Test t(50, 150); 
    
    t.show(); 
    
    return (0); 
}

