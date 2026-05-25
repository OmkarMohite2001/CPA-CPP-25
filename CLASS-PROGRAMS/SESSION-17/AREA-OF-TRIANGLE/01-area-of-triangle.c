// Header files 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

void area_of_triangle(void); 

int main(void) 
{
    area_of_triangle(); 
    return (EXIT_SUCCESS); 
}

void area_of_triangle(void)
{
    // data variables 
    double s1, s2, s3;
    
    // code 
    // Step 1: Input values for s1, s2 and s3 from end user 
    printf("Enter value for s1:"); 
    scanf("%lf", &s1); 

    printf("Enter value for s2:");
    scanf("%lf", &s2); 

    printf("Enter value for s3:"); 
    scanf("%lf", &s3); 

    // Step 2: Validation checks 
    // Validation check 1: All sides must have positive length
    if(s1 <= 0.0 || s2 <= 0.0 || s3 <= 0.0)
    {
        fprintf(stderr, "Bad input. Side of triangle cannot be negative in measure\n"); 
        return; 
    }

    // Validation check 2: Sum of any two sides of a triangle must be greater than that 
    // of the third 
    if((s1 + s2 <= s3) || (s2 + s3 <= s1) || (s3 + s1 <= s2))
    {
        fprintf(stderr, "Given measures of the sides do not form a triangle\n"); 
        fprintf(stderr, "Violation: Sum of any two sides of triangle is greather than that of the third"); 
        return; 
    } 
    
    printf("Sides of the triangle:s1:%.3lf unit, s2:%.3lf unit, s3:%.lf unit\n", s1, s2, s3); 
    // Step 3: DO computation 
    // Step 3: part 1: Calculate perimeter and semi-perimeter 
    double P; // for perimeter 
    double s; // for semi-perimeter 

    P = (s1 + s2 + s3); 
    s = P/2.0; 

    printf("Perimeter:%.3lf unit, Semi-Perimeter:%.3lf unit\n", P, s); 

    // Step 3: part 2: Compute the area of the triangle using horns formula
    double A; // for area

    A = sqrt(s * (s - s1) * (s - s2) * (s - s3));
    printf("Area of the triangle:%.lf square unit\n", A);  
}