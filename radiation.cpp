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
#include "error_check.h"
using namespace std;

// defining the value of PI.
#define PI 3.14159265

int rad_pattern (double theta, double phi, radiation_pattern *radiation, int len, Parameters *params)
{
    // Check variables
    double R = 1;
    check_loc(R, theta, phi);

    // displacement for P and SH-SV waves. Time shift is included.
    rad_pattern_x (theta, phi, radiation, len, params); 

    rad_pattern_y (theta, phi, radiation, len, params); 

    return 0;
}


int rad_pattern_x (double theta, double phi, radiation_pattern *radiation, int len, Parameters *params)
{
     string force_type = params->force_type;

     for (int i=0; i<len; i++)
     {
        if (force_type == "point_force") 
        {
            radiation->P_x[i]  = abs(cos(theta))*sin(theta)*cos(phi);
            
            radiation->SH_x[i] = pow(sin(theta),2)*cos(phi);

            radiation->SV_x[i] = pow(sin(theta),2)*cos(phi);
   
        }


        if (force_type == "single_couple")
        {
            radiation->P_x[i]  = sin(2.0*phi)*(pow(sin(theta),3))*cos(phi);

            radiation->SH_x[i] = abs(sin(theta)*(pow(sin(phi),2)))*sin(theta)*cos(phi);
            
            radiation->SV_x[i] = sin(2.0*theta)*sin(2.0*phi)*sin(theta)*cos(phi);
        }


        if (force_type == "double_couple")
        {
            radiation->P_x[i]  = sin(2.0*phi)*(pow(sin(theta),3))*cos(phi);

            radiation->SH_x[i] = pow(sin(theta),2)*cos(2.0*phi)*cos(phi);
            
            radiation->SV_x[i] = sin(2.0*theta)*sin(2.0*phi)*sin(theta)*cos(phi);
        }


        if (force_type == "force_dipole")
        {
            radiation->P_x[i]  = -(pow(sin(theta),3))*(pow(cos(phi),3));

            radiation->SH_x[i] = pow(sin(theta),2)*sin(2.0*phi)*cos(phi);
            
            radiation->SV_x[i] = -cos(theta)*pow(cos(phi),2)*sin(theta);
        }
      }
   return 0;
}


int rad_pattern_y (double theta, double phi, radiation_pattern *radiation, int len, Parameters *params)
{
     string force_type = params->force_type;

     for (int i=0; i<len; i++)
     {
        if (force_type == "point_force") 
        {
            radiation->P_y[i]  = abs(cos(theta))*sin(theta)*sin(phi);
            
            radiation->SH_y[i] = pow(sin(theta),2)*sin(phi);

            radiation->SV_y[i] = pow(sin(theta),2)*sin(phi);
   
        }


        if (force_type == "single_couple")
        {
            radiation->P_y[i]  = sin(2.0*phi)*(pow(sin(theta),3))*sin(phi);

            radiation->SH_y[i] = -(pow(sin(theta),2)*(pow(sin(phi),3)));
            
            radiation->SV_y[i] = sin(2.0*theta)*sin(2.0*phi)*sin(theta)*sin(phi);
        }


        if (force_type == "double_couple")
        {
            radiation->P_y[i]  = sin(2.0*phi)*(pow(sin(theta),3))*sin(phi);

            radiation->SH_y[i] = pow(sin(theta),2)*cos(2.0*phi)*sin(phi);
            
            radiation->SV_y[i] = sin(2.0*theta)*sin(2.0*phi)*sin(theta)*sin(phi);
        }


        if (force_type == "force_dipole")
        {
            radiation->P_y[i]  = -(pow(sin(theta),3))*(pow(cos(phi),2))*sin(phi);

            radiation->SH_y[i] = pow(sin(theta),2)*sin(2.0*phi)*sin(phi);
            
            radiation->SV_y[i] = abs(cos(theta)*cos(phi))*sin(theta)*sin(phi);
        }

      }
   return 0;
}
