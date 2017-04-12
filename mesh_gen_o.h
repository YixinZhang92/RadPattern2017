/**
 * @short   mesh generation Headers
 * @file    mesh_gen_o.h
 * @author  Yixin Zhang
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
#include <vector>

using namespace std;

// defining the value of PI.
#define PI 3.14159265

// Short description: This function takes x,y coordinates for every point and returns
// the spherical coordinates for each grid
// -------------------------------------------------------------------------------------

int mesh_gen_o (float area_x, float area_y, int n_x, int n_y, float X[], float Y[], ofstream &file);
