/**
 * @short   Prototypes
 * @file    prototypes.cpp
 * @author  Oluwaseun Fadugba, Yixin Zhang and Eric Jambo
 *
 * This file contains the prototypes and a short description of all the functions used in the RadPattern101 program.
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

double cart_2_sph (double xx, double yy)
{

    //cout << "Running: cartesian_to_spherical_function\n";
    //cout << endl;

    return 0;
}

/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates P-wave radiation pattern for single couple
 *                    force using the values of theta and phi
 *
 * Return             0 on sucess
 *
 */

double radp (double theta, double phi)
{

    //cout << "Running: radiation_pattern_P_wave_single_couple_force\n";
    //cout << endl;

    return 0;
}
