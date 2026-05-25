#include <iostream> 

class Rectangle
{
    private: 
        double w;
        double h; 

    public: 
        Rectangle(double _w, double _h) : w(_w), h(_h)
        {
        }

        double get_width() const 
        {
            return w; 
        }

        double get_height() const 
        {
            return h; 
        }

        void set_width(double _w)
        {
            this->w = _w; 
        }

        void set_height(double _h)
        {
            this->h = _h; 
        }
}; 

int main(void)
{
    Rectangle R(5.0, 2.0);

    double cw, ch; 

    cw = R.get_width(); 
    ch = R.get_height(); 
    std::cout << "Current W:" << cw << ", Current H:" << ch << std::endl;
    
    R.set_width(7.0); 
    R.set_height(3.0); 

    cw = R.get_width(); 
    ch = R.get_height(); 
    std::cout << "Current W:" << cw << ", Current H:" << ch << std::endl;

    return 0; 
}