/**
 * @short   Prototypes
 * @file    prototypes.cpp
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
#include <cstdlib>
#include <cmath>
#include "prototypes.h"

using namespace std;

// defining the value of PI.

#define PI 3.14159265

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function float inputs
 *
 * Return             0 on sucess
 *
 * Return             EXIT_FAILURE when the input file is missing
 */

// Just test, try to add read in program
// made by Yixin Zhang
//

int read_string(string str[], int i, string variable_name,
    string &string_value, ofstream &file)
{

    variable_name = str[i];
    file << variable_name << "=\t" << endl;
    cout << variable_name << "=\t" << endl;

    string_value = str[i+1];
    file << string_value << endl << "\n";
    cout << string_value << endl << "\n";
    
    return 0;

}

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function float inputs
 *
 * Return             0 on sucess
 *
 */

int read_float(string str[], int i, string variable_name,
    float &float_value, ofstream &file)
{

    char* c;
    
    variable_name = str[i];
    file << variable_name << "=\t" << endl;
    cout << variable_name << "=\t" << endl;

    c = const_cast<char*>(str[i+1].c_str());
    sscanf(c, "%e", &float_value);
    file << float_value << endl << "\n";
    cout << float_value << endl << "\n";

    return 0;
}

//  End of test by Yixin Zhang

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
 * Author:            Yixin Zhang
 *
 * Short description: This function read the input waveforms in the program
 *
 * Return             0 on sucess
 *
 */

int read_wave_file ()
{

    cout << "Running: read_wave_file\n";
    cout << endl;

    return 0;
}

/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates a guassian function using total time and time steps
 *
 * Return             0 on sucess
 *
 */

double gauss_func (double t[], double t_der[])
{

    cout << "Running: gaussian_function\n";
    cout << endl;

    return 0;
}

/**
 * Author:            Eric Jambo
 *
 * Short description: This function calculates the derivative of the input waveform using total
 *                    time and time steps
 *
 * Return             0 on sucess
 *
 */

double der_wavf_func (double t[], double t_der[])
{

    cout << "Running: derivative_waveform_function\n";
    cout << endl;

    return 0;
}

/**
 * Author:            Eric Jambo
 *
 * Short description: This function converts the cartesian coordinates into spherical coordinates
 *                    using location(x,y)
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

