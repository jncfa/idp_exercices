#ifndef __TPC_DIRECTION_RANDOMIZER_H__
#define __TPC_DIRECTION_RANDOMIZER_H__

#include <math.h>
#include <stdlib.h>

#define UniformRand() rand() / ((double)RAND_MAX + 1)

/**
 * Helper class to provide a "3D vector" structure.
*/
struct Vector3{
    double x, y, z;

    Vector3(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

/**
 * Returns a Vector3 according to the G. Marsaglia (1972) efficient algorithm for sampling points in an unit sphere.
 * 
 * See: From https://projecteuclid.org/journals/annals-of-mathematical-statistics/volume-43/issue-2/Choosing-a-Point-from-the-Surface-of-a-Sphere/10.1214/aoms/1177692644.full
*/
inline Vector3 generateRandomDirectionMarsaglia(){
    double u1, u2, v, b;
    
    // Generate random numbers until u1*u1 + u2*u2 < 1
    do
    {
        u1 = 2.*UniformRand() - 1.;
        u2 = 2.*UniformRand() - 1.;
        v = u1*u1 + u2*u2;
    } while (v > 1.);
    
    // Return random vector
    b = 2*sqrt(1 - v);
    return Vector3(u1*b, u2*b, 1.-2.*v);
}
#endif //__TPC_DIRECTION_RANDOMIZER_H__