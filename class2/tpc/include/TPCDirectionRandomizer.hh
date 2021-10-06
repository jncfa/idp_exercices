#ifndef __TPC_DIRECTION_RANDOMIZER_H__
#define __TPC_DIRECTION_RANDOMIZER_H__

#include "G4ThreeVector.hh"
#include "Randomize.hh"
#include "G4PhysicalConstants.hh"

/**
 * Returns a G4ThreeVector by randomizing the angles in spherical coordinates and transforming back to Cartesian coordinates.
*/

inline G4ThreeVector generateRandomDirection(){
    G4double phy = G4UniformRand()*2*pi;
    G4double theta = G4UniformRand()*pi;
    
    return G4ThreeVector(std::sin(phy)*std::sin(theta), std::cos(phy)*std::sin(theta), std::cos(theta));
}

/**
 * Returns a G4ThreeVector according to the G. Marsaglia (1972) efficient algorithm for sampling points in an unit sphere.
*/
inline G4ThreeVector generateRandomDirectionMarsaglia(){
    // From https://projecteuclid.org/journals/annals-of-mathematical-statistics/volume-43/issue-2/Choosing-a-Point-from-the-Surface-of-a-Sphere/10.1214/aoms/1177692644.full
    G4double u1, u2, v, b;
    
    // Generate random numbers until u1*u1 + u2*u2 < 1
    do
    {
        u1 = 2.*G4UniformRand() - 1.;
        u2 = 2.*G4UniformRand() - 1.;
        v = u1*u1 + u2*u2;
        
    } while (v > 1.);
    
    // Return random vector
    b = 2*sqrt(1 - v);
    return G4ThreeVector(u1*b, u2*b, 1.-2.*v);
}
#endif //__TPC_DIRECTION_RANDOMIZER_H__