// STAGE 1 : PROCEDURAL PROGRAMMING : USING BUILT IN FUNCTIONS 

#include <stdio.h> 

int main(void)
{
    double G = 6.67 * 10e-11;  /* Universal constant of gravitation */
    double m1;  /* for storing mass of object 1 in kgs */
    double m2;  /* for storing mass of object 2 in kgs */
    double r;   /* for storing distance in kgs */
    double F;   /* for storing the force in newtons */

    printf("Enter mass of object 1 in kgs:"); 
    scanf("%lf", &m1); 

    printf("Enter mass of object 2 in kgs:"); 
    scanf("%lf", &m2); 

    printf("Enter distance between the objects in meters:"); 
    scanf("%lf", &r); 

    if(m1 <= 0.0 || m2 <= 0.0 || r <= 0.0)
    {
        printf("Invalid values for mass or distance\n"); 
        return (-1); 
    }

    F = (G * m1 * m2)/(r*r); 

    printf("Force of gravitation:%lf Newton\n", F); 

    return (0); 
}

/* 
    Mass of sun in kgs: 1.9891 x 10^30
    Mass of earth in kgs: 5.9722 x 10^24 
    Distance between the earth and the sun:  149,597,871,000 meters
*/