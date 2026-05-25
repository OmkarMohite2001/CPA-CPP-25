// STAGE 3 : PROCEDURAL PROGRAMMING IN C USING STRUCT 

#include <stdio.h> 
#include <stdlib.h> 

struct MassAndDistance
{
    double m1; 
    double m2; 
    double r; 
}; 

double ComputeGravitatioanlForce(struct MassAndDistance* pData); 

int main(void)
{
    struct MassAndDistance sunEarth; // 24 
    struct MassAndDistance sunJupitor; // 24
    double forceBetweenSunEarth; // 8
    double forceBetweenSunJupitor; // 8

    sunEarth.m1 = 1.9891e30;    // mass of sun 
    sunEarth.m2 = 5.9722e24;    // mass of earth 
    sunEarth.r = 149597871000;  // distance between them 

    forceBetweenSunEarth = ComputeGravitatioanlForce(&sunEarth); 
    printf("Gravitational Force Between Sun and Earth = %lf N\n", forceBetweenSunEarth); 

    sunJupitor.m1 = 1.9891e30;    // mass of sun 
    sunJupitor.m2 = 1.89813e27;   // mass of jupitor 
    sunJupitor.r = 760070000000;  // distance between them 
    forceBetweenSunJupitor = ComputeGravitatioanlForce(&sunJupitor); 
    printf("Gravitational Force Between Sun and Jupitor = %lf N\n", forceBetweenSunJupitor); 

    return (0); 
}

double ComputeGravitatioanlForce(struct MassAndDistance* pData)
{
    double F; 
    double G = 6.67 * 10e-11; 

    if(pData->m1 <= 0.0 || pData->m2 <= 0.0 || pData->r <= 0.0)
    {
        printf("Invalid data for mass or distance..exiting..\n"); 
        exit(-1); 
    }

    F = (G * pData->m1 * pData->m2) / (pData->r * pData->r); 

    return (F); 
}