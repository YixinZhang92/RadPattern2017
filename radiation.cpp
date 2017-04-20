/**
 * @short   radiation
 * @file    radiation.cpp
 * @author  Eric Jambo
 *
 * Short description:This file contains all the functions used to calculate 
 *                   the radiation pattern for all forces.
 *
 *Return    0 on success
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>

#include "read_in.h"
#include "struct.h"
#include "radiation.h"       

using namespace std;

// defining the value of PI.
#define PI 3.14159265

double rad_patt (double theta, double phi, double *rad_P, double *rad_SH, double *rad_SV, double *rad_P_x, double *rad_SH_x, double *rad_SV_x,double *rad_P_y, double *rad_SH_y, double *rad_SV_y, int len, Parameters *params)
{

    //cout << "Running: radiation_pattern_P_wave_single_couple_force\n";
    //cout << endl;
     string force_type = params->force_type;

     for (int i=0; i<len; i++)
     {
        if (force_type == "point_force") 
        {
            rad_P[i]  = cos(theta);
            
            rad_SH[i] = -sin(theta);

            rad_SV[i] = -sin(theta);
   
        }


        if (force_type == "single_couple")
        {
            rad_P[i]  = -sin(2.0*phi)*(pow(sin(theta),2));

            rad_SH[i] = sin(theta)*(pow(sin(phi),2));
            
            rad_SV[i] = -sin(2.0*theta)*sin(2.0*phi);
        }


        if (force_type == "double_couple")
        {
            rad_P[i]  = -sin(2.0*phi)*(pow(sin(theta),2));

            rad_SH[i] = -sin(theta)*cos(2.0*phi);
            
            rad_SV[i] = -sin(2.0*theta)*sin(2.0*phi);
        }


        if (force_type == "force_dipole")
        {
            rad_P[i]  = (pow(sin(theta),2))*(pow(cos(phi),2));

            rad_SH[i] = -sin(theta)*sin(2.0*phi);
            
            rad_SV[i] = cos(theta)*cos(phi);
        }
        
        rad_P_x[i] = abs(rad_P[i])*sin(theta)*cos(phi);
        rad_P_y[i] = abs(rad_P[i])*sin(theta)*sin(phi);
        rad_SH_x[i] = abs(rad_SH[i])*sin(theta)*cos(phi);
        rad_SH_y[i] = abs(rad_SH[i])*sin(theta)*sin(phi);
        rad_SV_x[i] = abs(rad_SV[i])*sin(theta)*cos(phi);
        rad_SV_y[i] = abs(rad_SV[i])*sin(theta)*sin(phi);
      }
   return 0;
}
