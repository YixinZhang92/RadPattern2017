
/**
 * @short  displacement
 * @file    displacement.cpp
 * @author  Oluwaseun Fadugba
 *
 * This file contains the prototypes and a short description of all the functions used
 * to calculate displacement.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include "displacement.h"

using namespace std;

// defining the value of PI.

#define PI 3.14159265/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the P-wave Displacement for
 *                    single force using the values of theta, phi, distance (R),
 *                    moment (C1), P-wave velocity (alpha), density (rho), the
 *                    input waveform (h) and the time series (time).
 *
 * Return             0 on sucess
 *
 */

int displ_pt_fo_Pw (
    double theta, double R, double moment, double alpha,
    double rho, double *h, double *t, double *displ_pt_fo_Pw_o, int len)
{

    cout <<  "Running: displacement_point_force_P_wave\n";
    cout << endl;

    // Perform operation.

    for (int i=0; i<len; i++)
    {

        displ_pt_fo_Pw_o[i] = (cos(theta * PI / 180.0) * h[i]) / 
                              (4 * PI * rho * pow(alpha, 2) * R);
    }
    
    return 0;
}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the S-wave Displacement for single force
 *                    using the values of theta, phi, distance (R), moment (C1), S-wave
 *                    velocity (beta), density (rho), the input waveform (h) and the 
 *                    time series (time).
 *
 * Return             0 on sucess
 *
 */

double displ_pt_fo_Sw (
    double theta, double phi, double R, double moment, double beta,
    double rho, double *h, double *t , double *displ_pt_fo_Sw_o, int len)
{

// Dont forget to apply time shift to the h and h derivatives
    cout <<  "Running: displacement_point_force_S_wave\n";
    cout << endl;

    // Perform operation.
    
    for (int i=0; i<len; i++)
    {

        displ_pt_fo_Sw_o[i] = (-sin(theta * PI / 180.0) * h[i]) /
                              (4 * PI * rho * pow(beta, 2) * R);
    }

    return 0;
}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the P-wave Displacement for single force
 *                    using the values of theta, phi, distance (R), moment (C1), P-wave
 *                    velocity (alpha), density (rho), derivative of the input waveform
 *                    (h) and derivative of the time series (time).
 *
 * Return             0 on sucess
 *
 */
 
double displ_si_cpl_Pw (
    double theta, double phi, double R, double moment, double alpha,
    double rho, double *h_der, double *t_der , double *displ_si_cpl_Pw_o, int len)
{

    cout <<  "Running: displacement_single_force_P_wave\n";
    cout <<  endl;

    // Perform operation.

    for (int i=0; i<len; i++)
    {

        displ_si_cpl_Pw_o[i] = (-sin(2.0*phi * PI / 180.0)*pow(sin(theta * PI / 180.0), 2) *
                              moment * h_der[i]) / (8.0 * PI * rho * pow(alpha, 3) * R);
       
    }

    return 0;
}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the SH-wave Displacement for single force
 *                    using the values of theta, phi, distance (R), moment (C1), distance 
 *                    (R), moment (C1), S-wave velocity (beta), density (rho), derivative
 *                    of the input waveform (h) and derivative of the time series (time).
 *
 * Return             0 on sucess
 *
 */

double displ_si_cpl_SHw (
    double theta, double phi, double R, double moment, double beta,
    double rho, double *h_der, double *t_der, double *displ_si_cpl_SHw_o, int len)
{

    cout <<  "Running: displacement_single_force_SH_wave\n";
    cout <<  endl;

    for (int i=0; i<len; i++)
    {
        displ_si_cpl_SHw_o[i] = (sin(theta * PI / 180.0)*pow(sin(phi * PI / 180.0), 2) * moment
                               * h_der[i]) / (8.0 * PI * rho * pow(beta, 3) * R);
    }

    return 0;
}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the SV-wave Displacement for single force using
 *                    the values of theta, phi, distance (R), moment (C1), distance (R), moment
 *                    (C1), S-wave velocity (beta), density (rho), derivative of the input 
 *                    waveform (h) and derivative of the time series (time).
 *
 * Return             0 on sucess
 *
 */

double displ_si_cpl_SVw (
    double theta, double phi, double R, double moment, double beta,
    double rho, double *h_der, double *t_der, double *displ_si_cpl_SVw_o, int len)
{

    cout <<  "Running: displacement_single_force_SV_wave\n";
    cout <<  endl;

    for (int i=0; i<len; i++)
    {
        displ_si_cpl_SVw_o[i] = (-sin(2.0*theta * PI / 180.0)*(sin(2.0*phi * PI / 180.0)) *
                               moment * h_der[i]) / (16.0 * PI * rho * pow(beta, 3) * R);
    }

    return 0;
}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the P-wave Displacement for Double Couple using
 *                    the values of theta, phi, distance (R), moment (C1), P-wave velocity 
 *                    (alpha), density (rho), derivative of the input waveform (h) and derivative
 *                    of the time series (time).
 *
 * Return             0 on sucess
 *
 */

double displ_do_cpl_Pw (
    double theta, double phi, double R, double moment, double alpha,
    double rho, double *h_der, double *t_der, double *displ_do_cpl_Pw_o, int len)
{

    cout <<  "Running: displacement_double_couple_P_wave\n";
    cout <<  endl;

    for (int i=0; i<len; i++)
    {

        displ_do_cpl_Pw_o[i] = (-sin(2.0*phi * PI / 180.0)*pow(sin(theta * PI / 180.0), 2) * 
                               moment * h_der[i]) / (4.0 * PI * rho * pow(alpha, 3) * R);
        
    }

    return 0;
}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the SH-wave Displacement for Double Couple
 *                    using the values of theta, phi, distance (R), moment (C1), S-wave 
 *                    velocity (beta), density (rho), derivative of the input waveform (h)
 *                    and derivative of the time series (time).
 *
 * Return             0 on sucess
 *
 */
 
double displ_do_cpl_SHw (
    double theta, double phi, double R, double moment, double beta,
    double rho, double *h_der, double *t_der, double *displ_do_cpl_SHw_o, int len)
{

    cout <<  "Running: displacement_double_couple_SH_wave\n";
    cout << endl;

    for (int i=0; i<len; i++)
    {

        displ_do_cpl_SHw_o[i] = (-sin(theta * PI / 180.0)*(cos(2.0*phi * PI / 180.0)) *
                                 moment * h_der[i]) / (4.0 * PI * rho * pow(beta, 3) * R);
        
    }

    return 0;
}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the SV-wave Displacement for Double Couple
 *                    using the values of theta, phi, distance (R), moment (C1), S-wave 
 *                    velocity (beta), density (rho), derivative of the input waveform (h)
 *                    and derivative of the time series (time).
 *
 * Return             0 on sucess
 *
 */

double displ_do_cpl_SVw (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double *h_der, double *t_der, double *displ_do_cpl_SVw_o, int len)
{

    cout <<  "Running: displacement_double_couple_SV_wave\n";
    cout <<  endl;

    for (int i=0; i<len; i++)
    {

        displ_do_cpl_SVw_o[i] = (-sin(2.0*theta * PI / 180.0)*(sin(2.0*phi * PI / 180.0)) *
                                moment * h_der[i]) / (8.0 * PI * rho * pow(beta, 3) * R);
       
    }

    return 0;
}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the P-wave Displacement for Force Dipole using
 *                    the values of theta, phi, distance (R), moment (C1), P-wave velocity 
 *                    (alpha), density (rho), input waveform (h) and time series (time).
 *
 * Return             0 on sucess
 *
 */

double displ_fo_dipo_Pw (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double *h, double *t, double *displ_fo_dipo_Pw_o, int len)
{

    cout <<  "Running: displacement_force_dipole_P_wave\n";
    cout << endl;

    for (int i=0; i<len; i++)
    {

        displ_fo_dipo_Pw_o[i] = (pow(sin(theta * PI / 180.0),2)*pow(cos(phi * PI / 180.0), 2) *
                                moment * h[i]) / (4.0 * PI * rho * pow(alpha, 3) * R);

    }

    return 0;
}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the SH-wave Displacement for Force Dipole
 *                    using the values of theta, phi, distance (R), moment (C1), S-wave 
 *                    velocity, density (rho), input waveform (h) and time series (time).
 *
 * Return             0 on sucess
 *
 */

double displ_fo_dipo_SHw (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double *h, double *t, double *displ_fo_dipo_SHw_o, int len)
{

    cout <<  "Running: displacement_force_dipole_SH_wave\n";
    cout << endl;

    for (int i=0; i<len; i++)
    {

        displ_fo_dipo_SHw_o[i] = (-sin(theta * PI / 180.0)*(sin(2.0*phi * PI / 180.0)) *
                                 moment * h[i]) / (8.0 * PI * rho * pow(beta, 3) * R);
    }

    return 0;
}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the SV-wave Displacement for Force Dipole
 *                    using the values of theta, phi, distance (R), moment (C1), S-wave
 *                    velocity, density (rho), input waveform (h) and time series (time).
 *
 * Return             0 on sucess
 *
 */

double displ_fo_dipo_SVw (
    double theta, double phi, double R, double moment, double beta,
    double rho, double *h, double *t, double *displ_fo_dipo_SVw_o, int len)
{

    cout <<  "Running: displacement_force_dipole_SV_wave\n";
    cout << endl;

    for (int i=0; i<len; i++)
    {

        displ_fo_dipo_SVw_o[i] = (cos(theta * PI / 180.0)*(cos(phi * PI / 180.0)) *
                                 moment * h[i]) / (4.0 * PI * rho * pow(beta, 3) * R);

    }

    return 0;
}

