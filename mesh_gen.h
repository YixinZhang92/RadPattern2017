/**
 * @short   mesh generation Headers
 * @file    mesh_gen.h
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
#include <cmath>
#include <cstdlib>

using namespace std;

// defining the value of PI.
#define PI 3.14159265

// Short description: This function takes x,y coordinates for every point and returns
// the spherical coordinates for each grid
// -------------------------------------------------------------------------------------

double mesh_gen (double x, double y, double dx, double dy);

// Short description: This function converts the cartesian coordinates into spherical
// coordinates using location(x,y)
// ----------------------------------------------------------------------------------

double cart_2_sph (double *x, double *y);

