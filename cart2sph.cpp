/**
 * Author:            Eric Jambo
 *
 * Short description: This function converts the cartesian coordinates into spherical coordinates
 *                    using location(x,y) from the generated mesh grid
 *
 * Return             0 on sucess
 *
 */


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include "cart2sph.h"

using namespace std;

// defining the value of PI.

#define PI 3.14159265
const double Degres = 180.0/PI; // Radians to Degrees

double cart_2_sph(double xx, double yy, double R, double theta, double phi)
{
    double z = 0.0;
    if (xx !=0){
    	R = sqrt((pow(xx,2))+(pow(yy,2))+(pow(z,2))); // distance
	theta = acos(z/R)* Degres;
    	phi = atan2(yy, xx) * Degres;
        //cout<< R <<":"<< theta << ":" << phi<<endl; commented out for using too much space
        return 0;
   }
   return false;
}
