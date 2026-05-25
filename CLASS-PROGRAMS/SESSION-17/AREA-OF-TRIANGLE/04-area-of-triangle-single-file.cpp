#include <iostream> 

#define SUCCESS 1 
#define TR_INVALID_LENGTH -1 
#define TR_INVALID_COMBINATION -2 

class Triangle 
{
    private: 
        double s1, s2, s3; 
        int check_sides()
        {
            if(s1 <= 0 || s2 <= 0 || s3 <= 0)
                return TR_INVALID_LENGTH; 
            
            if((s1 + s2 <= s2) || (s2 + s3 <= s1) || (s3 + s1 <= s2))
                return TR_INVALID_COMBINATION; 

            return SUCCESS; 
        }

    public: 
        Triangle(double _s1, double _s2, double _s3)
        {
            int status = check_sides(); 
            if(status != SUCCESS)
            {
                s1 = 5.0; 
                s2 = 5.0; 
                s3 = 5.0f; 
            }
            else 
            {
                s1 = _s1; 
                s2 = _s2; 
                s3 = _s3;
            } 
        }

        double get_perimeter() const 
        {

        }

        double get_semi_perimeter() const 
        {

        }

        double get_area() const 
        {
            
        }

        void show() const 
        {
            
        }
}; 