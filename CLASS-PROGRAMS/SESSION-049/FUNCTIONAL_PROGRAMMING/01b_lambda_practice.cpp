#include <iostream> 
#include <vector> 
#include <map> 
#include <cmath> 

void outer_function(void); 
void quadratic_solver(void); 
void arithmetic_mean(void); 
void root_mean_square(void); 

int main(void)
{
    outer_function();
    quadratic_solver(); 
    arithmetic_mean(); 
    root_mean_square(); 
    return (0); 
}

// Outer function for writing lambdas 
// One named function is required. 
void outer_function(void) 
{
    // square function :
    // Is variable from outer function required? 
    // No. capture list -> empty 
    // Is there an input parameter ? Yes, 
    // What is its type? -> double 
    // is there going to be a return value? Yes, 
    // What is its type? -> double 
    [](double x)->double{
        return x * x; 
    }; 

    // above construct creates an anonymous (=without name)
    // function aka lambda. 

    // Though lambda creates an anonymous function, we can assign it 
    // to the name, make it named function 

    // OR we can choose not to assign lambda to any name but call it 
    // as soon as we create it. 

    // In former case, we can resue function created by lambda 
    // In later case we cannot. 

    // FORMER CASE: 
    // auto keyword relieves us from responsibility of assigning type to a 
    // variable name. C++ compiler will infer the type of the right hand side lambda 
    // expression and the square_func will be of that type (= thanks to auto keyword)
    auto square_func = [](double x)->double{
                            return x * x; 
                        };
    // Using and reusing function created by lambda through the square_func variable name 
    double rs = square_func(2); 
    std::cout << "Result=" << rs << std::endl; 
    rs = square_func(5);  
    std::cout << "Result=" << rs << std::endl; 
}

void quadratic_solver(void)
{
    /* 
        @goal: Accept three floating point numbers which represent 
        coefficients of x^2, x and constant respectively. We have to 
        compute the roots of quadratic if they are real numbers. 

        Designing lambda: 
            Q1: Do you required any varaible from outer function? 
            No. Therefore, capture list is empty. 

            Q2: Do you have any formal parameters? If yes, describe the same. 
            Yes. This lambda will accept three double precision floating point 
            numbers representing coefficients of x^2, x and the constant of the 
            equation. 

            Q3: Do you have a return value? 
            Yes. In fact, if roots of equation are real then we have two floating 
            point numbers to return. We will instantiate std::pair template 
            by double data type and return the same. In case of complex root we will 
            return Not a Number. 
    */
   auto q_solver = [](double a, double b, double c) -> std::pair<double, double> {
                    std::pair<double, double> roots(NAN, NAN); 
                    if((b*b - 4*a*c) >= 0.0 && a != 0.0)
                    {
                        roots.first = (-b + sqrt(b*b-4*a*c))/(2*a); 
                        roots.second = (-b - sqrt(b*b-4*a*c))/(2*a);
                    }    
                    return roots; 
                }; 

    std::pair<double, double> roots = q_solver(3.0, 5.9, -8.1); 
    std::cout << "Roots of 3.0*x^2 + 5.9*x - 8.1 = 0 are:" << std::endl; 
    std::cout << roots.first << std::endl; 
    std::cout << roots.second << std::endl;  
}

void arithmetic_mean(void)
{
    /* 
        @goal: To compute the arithmetic mean of all numbers in vector 
        1) Variables from outer function: Not rquired 
        2) Inputs: vector of double 
        3) Return: double 
    */
   auto am = [](std::vector<double>& dvec) -> double {
            double summation = 0.0; 
            if(dvec.size() == 0)
                return NAN; 
            for(std::vector<double>::size_type i = 0; i != dvec.size(); ++i)
                summation += dvec[i];
            return summation / dvec.size();   
        }; 

    std::vector<double> dvec{1.1, 2.2, 3.3, 4.4, 5.5}; 
    double a_mean = am(dvec); 
    std::cout << "a_mean:" << a_mean << std::endl; 
}

void root_mean_square(void)
{
 /* 
        @goal: To compute the root mean square of all numbers in vector 
        1) Variables from outer function: Not rquired 
        2) Inputs: vector of double 
        3) Return: double 
    */

   auto rms = [](std::vector<double>& dvec) -> double {
            double summation = 0.0; 
            if(dvec.size() == 0)
                return NAN; 
            for(std::vector<double>::size_type i = 0; i != dvec.size(); ++i)
                summation += dvec[i] * dvec[i];
            return sqrt(summation / dvec.size());   
        }; 

    std::vector<double> dvec{1.1, 2.2, 3.3, 4.4, 5.5}; 
    double d_rms = rms(dvec); 
    std::cout << "rms:" << d_rms << std::endl; 
}

/* 
    [capture list](formal parameter list)->return type{
        // body 
    }

    [capture list](formal parameter list)-> return type{
        // body 
    }

    [capture list](formal parameter list) -> return type {
          // body 
    }

    [capture list](formal parameter list) -> return type {
        // body 
    }

    [capture list](formal parameter list) -> return type {
          // body 
    }   
*/
