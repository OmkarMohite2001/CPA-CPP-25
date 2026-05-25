#include <iostream> 

class CPA_int
{
    private: 
        int n; 

    public: 
        CPA_int(int _n = 0) : n(_n) 
        {
        }

        void show(const char* msg = 0) const 
        {
            if(msg) 
                std::cout << msg; 
            std::cout << n << std::endl; 
        }

        CPA_int operator+(const CPA_int& rhs_object) const 
        {
            int tmp; 
            
            tmp = n + rhs_object.n; 
            CPA_int result(tmp); 

            return (result); 
        }   

        CPA_int operator-(const CPA_int& rhs_object) const 
        {
            return CPA_int(n - rhs_object.n); 
        }

        CPA_int operator*(const CPA_int& rhs_object) const 
        {
            return CPA_int(n * rhs_object.n); 
        }

        CPA_int operator/(const CPA_int& rhs_object) const 
        {
            //  Ideally, if rhs_object.n == 0 then throw runtime_error exception 
            return CPA_int(n / rhs_object.n); 
        }

        CPA_int operator%(const CPA_int& rhs_object) const 
        {
            //  Ideally, if rhs_object.n == 0 then throw runtime_error exception 
            return CPA_int(n % rhs_object.n); 
        }

        bool operator<(const CPA_int& rhs_object) const 
        {
            return n < rhs_object.n; 
        }

        bool operator<=(const CPA_int& rhs_object) const 
        {
            return n <= rhs_object.n; 
        }

        bool operator>(const CPA_int& rhs_object) const 
        {
            return n > rhs_object.n; 
        }

        bool operator>=(const CPA_int& rhs_object) const 
        {
            return n >= rhs_object.n; 
        }

        bool operator==(const CPA_int& rhs_object) const 
        {
            return n == rhs_object.n; 
        }

        bool operator!=(const CPA_int& rhs_object) const 
        {
            return n != rhs_object.n; 
        }

        CPA_int operator!() const 
        {
            return CPA_int(!n); 
        }

        CPA_int operator~() const 
        {
            return CPA_int(~n); 
        }

}; 

int main(void)
{
    CPA_int n1(25); 
    CPA_int n2(7); 
    CPA_int result;
    
    n1.show("n1:"); 
    n2.show("n2:"); 

    //  Addition 
    result = n1 + n2; 
    result.show("n1 + n2:"); 

    //  Subtraction
    result = n1 - n2; 
    result.show("n1 - n2:"); 

    //  Multiplication 
    result = n1 * n2; 
    result.show("n1 * n2:"); 

    //  Division 
    result = n1 / n2; 
    result.show("n1 / n2:"); 

    //  Modulo 
    result = n1 % n2; 
    result.show("n1 % n2:"); 

    //  Comparison operators 
    bool comparisonResult; 
    
    //  Less than 
    comparisonResult = n1 < n2; 
    std::cout << "n1 < n2:" << comparisonResult << std::endl; 

    //  Less than or equal to 
    comparisonResult = n1 <= n2; 
    std::cout << "n1 <= n2:" << comparisonResult << std::endl; 

    //  Greater than 
    comparisonResult = n1 > n2; 
    std::cout << "n1 > n2:" << comparisonResult << std::endl; 

    //  Greater than or equal to 
    comparisonResult = n1 >= n2; 
    std::cout << "n1 >= n2:" << comparisonResult << std::endl; 

    //  equal to 
    comparisonResult = n1 == n2; 
    std::cout << "n1 == n2:" << comparisonResult << std::endl; 

    //  Not equal to 
    comparisonResult = n1 != n2; 
    std::cout << "n1 != n2:" << comparisonResult << std::endl; 

    //  Logical operators 
    //  logical AND 
    result = n1 && n2; 
    result.show("n1 && n2:"); 

    //  Logical OR 
    result = n1 || n2; 
    result.show("n1 || n2"); 

    //  Logical NOT 
    result = !n1; 
    result.show("!n1:"); 

    //  Bitwise operators 
    //  Bitwise AND 
    result = n1 & n2; 
    result.show("n1 & n2:"); 

    //  Bitwise OR 
    result = n1 | n2; 
    result.show("n1 | n2:"); 

    // Bitwise XOR 
    result = n1 ^ n2; 
    result.show("n1 ^ n2:"); 

    //  Bitwise NOT 
    result = ~n1; 
    result.show("~n1:"); 

    //  Shift arithmetic left 
    result = n1 << n2; 
    result.show("n1 << n2:"); 

    result = n1 >> n2; 
    result.show("n1 >> n2:"); 


    return (0); 
}