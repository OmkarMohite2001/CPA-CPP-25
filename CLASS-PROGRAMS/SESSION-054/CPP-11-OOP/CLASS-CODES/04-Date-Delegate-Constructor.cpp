class Date 
{
    public: 
        Date(int _d, int _m, int _y) 
        {
            if(is_date_valid(_d, _m, _y))
            {
                day = _d; 
                month = _m; 
                year = _year; 
            }
            else 
            {
                throw std::domain_error("bad date values"); 
            }
        } 

        Date() : Date(1, 1, 1970) {} 

        Date(int year) : Date(1, 1, year) {} 

        Date(int day, int month) : Date(day, month, 1970) {} 
}; 