// STAGE 2: OBJECT BASED PROGRAMMING IN C++ : USING BUILT IN OBJECTS

#include <iostream> 

int main(void)
{
    using std::cout; // ostream | std::ostream
    using std::cin;  // istream | std::istream 
    
    double G = 6.67 * 10e-11;   // Universal constant of gravitation 
    double m1;                  // for storing mass of object 1 in kgs 
    double m2;                  // for storing mass of object 2 in kgs 
    double r;                   // for storing distance in kgs 
    double F;                   // for storing the force in newton
    
    cout << "Enter mass of object 1 in kgs:"; 
    cin >> m1; 

    cout << "Enter mass of object 2 in kgs:"; 
    cin >> m2; 

    cout << "Enter distance between the objects in meters:"; 
    cin >> r; 

    if(m1 <= 0.0 || m2 <= 0.0 || r <= 0.0)
    {
        printf("Invalid values for mass or distance\n"); 
        return (-1); 
    }

    F = (G * m1 * m2)/(r*r); 

    cout << "Force of gravitation is " << F << " Newton\n";

    return 0; 
}


