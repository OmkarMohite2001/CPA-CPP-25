#include <iostream> 
#include <vector>
#include <functional> 

void test(); 

int main()
{
    test(); 
    return 0;
}

void test() 
{
    //  Square function 
    auto x = [](int x)->int{return x * x;}(10); 
    std::cout << "x:" << x << std::endl;    // x == 100 

    //  Newton formula for gravitation 
    double G = 6.67 * (10e-11); 
    auto force = [G](double m1, double m2, double r){
                    return (G * m1 * m2)/(r * r); 
                }(345345.35443, 34534535.34535, 0.05); 
    std::cout << "Force:" << force << std::endl;

    std::vector<int> ivec {100, 200, 300, 400}; 
    std::vector<float> fvec {1.1f, 2.2f, 3.3f, 4.4f}; 
    std::vector<std::string> svec{std::string("abc"), std::string("pqr"), std::string("xyz")}; 

    for(const auto& v : ivec)
        std::cout << "v:" << v << std::endl; 

    for(const auto& v : fvec)
        std::cout << "v:" << v << std::endl; 

    for(const auto& str : svec)
        std::cout << "str:" << str << std::endl; 

    //  std::function<std::vector<int>(std::function<int(int)> func_object, std::vector<int>& vec)> map1

    auto map1 = [](std::function<int(int)> func_object, std::vector<int>& vec) -> std::vector<int>
                {
                    std::vector<int> rsv; 
                    for(const auto& v : vec)
                        rsv.push_back(func_object(v)); 
                    return rsv; 
                }; 

    auto map2 = [](std::function<float(float)> func_object, std::vector<float>& fvec) -> std::vector<float>
                {
                    std::vector<float> rsv; 
                    for(const auto& v : fvec)
                        rsv.push_back(func_object(v)); 
                    return rsv; 
                };
                
    auto filter =   [](std::function<bool(int)> function_object, std::vector<int>& ivec) -> std::vector<int>
                    {
                        std::vector<int> rsv; 
                        for(const auto& v : ivec) 
                            if(function_object(v))
                                rsv.push_back(v); 
                        return rsv; 
                    }; 

    std::function<std::vector<int>(std::function<int(int)> func_object, std::vector<int>& vec)> map3 = 
    [](std::function<int(int)> func_object, std::vector<int>& vec) -> std::vector<int>
    {
        std::vector<int> rsv; 
        for(const auto& v : vec)
            rsv.push_back(func_object(v)); 
        return rsv; 
    }; 
}

