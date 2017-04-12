/**
 * @short   displacement
 * @file    displ_calc.cpp
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

#include "displ_calc.h"       

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

int displ (
    double theta, double R, double phi, double moment, double alpha, double beta,
    double rho, double *h, double *t, double *h_der, double *t_der,
    double *displ_P, double *displ_SH, double *displ_SV, int len, string force_type)
{

    //cout <<  "Running: displacement_point_force_P_wave\n";
    //cout << endl;


    if (force_type == "point_force")

        // Perform operation for Point Force.

        for (int i=0; i<len; i++)
        {

            displ_P[i]  = (cos(theta * PI / 180.0) * h[i]) / 
                          (4 * PI * rho * pow(alpha, 2) * R);

            displ_SH[i] = (-sin(theta * PI / 180.0) * h[i]) /
                          (4 * PI * rho * pow(beta, 2) * R);

            displ_SV[i] = displ_SH[i];
        }


    if (force_type == "single_couple")

        // Perform operation for Single Couple.

        for (int i=0; i<len; i++)
        {

            displ_P[i]  = (-sin(2.0*phi * PI / 180.0)*pow(sin(theta * PI / 180.0), 2) *
                          moment * h_der[i]) / (8.0 * PI * rho * pow(alpha, 3) * R);
       
            displ_SH[i] = (sin(theta * PI / 180.0)*pow(sin(phi * PI / 180.0), 2) * 
                          moment * h_der[i]) / (8.0 * PI * rho * pow(beta, 3) * R);

            displ_SV[i] = (-sin(2.0*theta * PI / 180.0)*(sin(2.0*phi * PI / 180.0)) *
                          moment * h_der[i]) / (16.0 * PI * rho * pow(beta, 3) * R);
        }

    if (force_type == "double_couple")
    
        // Perform operation for Double Couple.

        for (int i=0; i<len; i++)
        {

            displ_P[i]  = (-sin(2.0*phi * PI / 180.0)*pow(sin(theta * PI / 180.0), 2) * 
                          moment * h_der[i]) / (4.0 * PI * rho * pow(alpha, 3) * R);
        
            displ_SH[i] = (-sin(theta * PI / 180.0)*(cos(2.0*phi * PI / 180.0)) *
                          moment * h_der[i]) / (4.0 * PI * rho * pow(beta, 3) * R);
        
            displ_SV[i] = (-sin(2.0*theta * PI / 180.0)*(sin(2.0*phi * PI / 180.0)) *
                          moment * h_der[i]) / (8.0 * PI * rho * pow(beta, 3) * R);
        }

    if (force_type == "force_dipole")
    
        // Perform operation for Double Couple.
    
        for (int i=0; i<len; i++)
        {

            displ_P[i]  = (pow(sin(theta * PI / 180.0),2)*pow(cos(phi * PI / 180.0), 2) *
                          moment * h[i]) / (4.0 * PI * rho * pow(alpha, 3) * R);

            displ_SH[i] = (-sin(theta * PI / 180.0)*(sin(2.0*phi * PI / 180.0)) *
                          moment * h[i]) / (8.0 * PI * rho * pow(beta, 3) * R);
    
            displ_SV[i] = (cos(theta * PI / 180.0)*(cos(phi * PI / 180.0)) *
                          moment * h[i]) / (4.0 * PI * rho * pow(beta, 3) * R);

        }

    return 0;
}
