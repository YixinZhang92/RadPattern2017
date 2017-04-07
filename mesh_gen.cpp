/**
 * @short   mesh generation
 * @file    mesh_gen.cpp
 * @author  Yixin Zhang and Eric Jambo
 *
 * This file contains the prototypes and a short description of all the functions used
 * generate mesh grid and then convert every point in it into spherical coordinates.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include "mesh_gen.h"

using namespace std;

// defining the value of PI.

#define PI 3.14159265

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function gives the x,y coordinates for every point
 *                    and returns the spherical coordinates for each grid
 *
 * Return             0 on sucess
 *
 */

double mesh_gen (double x, double y, double dx, double dy)
{

    cout <<  "Running: mesh_generator\n";
    cout << endl;

    return 0;
}

/**
 * Author:            Eric Jambo
 *
 * Short description: This function converts the cartesian coordinates into spherical coordinates
 *                    using location(x,y) from the generated mesh grid
 *
 * Return             0 on sucess
 *
 */

double cart_2_sph (double *x, double *y)
{

    cout << "Running: cartesian_to_spherical_function\n";
    cout << endl;

    return 0;
}

