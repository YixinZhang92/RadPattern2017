/**
 * @short   displacement
 * @file    init_time.cpp 
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

#include "init_time.h"       

using namespace std;

// defining the value of PI.
#define PI 3.14159265

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the Displacement for all
 *                    forces using the values of theta, phi, distance (R),
 *                    moment (C1), P-wave velocity (alpha), S-wave velocity (beta), density (rho), the
 *                    input waveform (h) and the time series (time).
 *
 * Return             0 on sucess
 *
 */

int init_time (double *t, Parameters *params)
{
        // Perform operation for Point Force.
        int i = 0; 
        for (double tt=0; tt<=params.total_time; tt+= params.time_step)
        {
            i++;
            t[i]  = tt;

        }

return 0;

};
