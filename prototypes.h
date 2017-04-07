/**
 * @short   Prototype Headers
 * @file    prototypes.h
 * @author  Oluwaseun Fadugba, Yixin Zhang and Eric Jambo
 *
 * This file contains the prototypes and a short description of all the functions used
 * in the RadPattern101 program.
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

// Short description: These functions read the input waveforms in the program
// -------------------------------------------------------------------------------------

int read_string(string str[], int i, string variable_name,
    string &string_value, ofstream &file);

int read_float(string str[], int i, string variable_name,
    float &float_value, ofstream &file);

int read_wave_file ();

// Short description: These functions generates a guassian function and its derivative 
// using total time and time steps
// ------------------------------------------------------------------------------------

double gauss_func (double t[], double t_der[]);

double der_wavf_func (double t[], double t_der[]);

// Short description: This function gives the x,y coordinates for every point and returns
// the spherical coordinates for each grid
// -------------------------------------------------------------------------------------

double mesh_gen (double x, double y, double dx, double dy);

// Short description: This function converts the cartesian coordinates into spherical
// coordinates using location(x,y)
// ----------------------------------------------------------------------------------

double cart_2_sph (double *x, double *y);

