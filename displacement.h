/**
 * @short   displacement Headers
 * @file    displacement.h
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
#include <cmath>
#include <cstdlib>

using namespace std;

// defining the value of PI.
#define PI 3.14159265
// Short description: This function calculates the P-, SH- and SH-wave Displacements for 
// single force, double couple, force dipole and point forces using the values of theta,
// phi, distance (R), moment (C1), S-wave velocity (beta), density (rho), the input waveform
// (h) and its derivative, and the time series (time) and its derivative.
// --------------------------------------------------------------------------------------------

int displ_pt_fo_Pw (
    double theta, double R, double moment, double alpha,
    double rho, double *h, double *t, double *displ_pt_fo_Pw_o, int len);

double displ_pt_fo_Sw (
    double theta, double phi, double R, double moment, double beta,
    double rho, double *h, double *t, double *displ_pt_fo_Sw_o, int len);

double displ_si_cpl_Pw (
    double theta, double phi, double R, double moment, double alpha,
    double rho, double *h_der, double *t_der, double *displ_si_fo_Pw_o, int len);

double displ_si_cpl_SHw (
    double theta, double phi, double R, double moment, double alpha,
    double rho, double *h_der, double *t_der, double *displ_si_fo_SHw_o, int len);

double displ_si_cpl_SVw (
    double theta, double phi, double R, double moment, double beta,
    double rho, double *h_der, double *t_der, double *displ_si_fo_SVw_o, int len);

double displ_do_cpl_Pw (
    double theta, double phi, double R, double moment, double alpha,
    double rho, double *h_der, double *t_der, double *displ_do_cpl_Pw_o, int len);

double displ_do_cpl_SHw (
    double theta, double phi, double R, double moment, double alpha,
    double rho, double *h_der, double *t_der, double *displ_do_cpl_SHw_o, int len);

double displ_do_cpl_SVw (
    double theta, double phi, double R, double moment, double alpha,
    double rho, double *h_der, double *t_der, double *displ_do_cpl_SVw_o, int len);

double displ_fo_dipo_Pw (
    double theta, double phi, double R, double moment, double alpha,
    double rho, double *h, double *t,  double *displ_fo_dipo_Pw_o, int len);

double displ_fo_dipo_SHw (
    double theta, double phi, double R, double moment, double alpha,
    double rho, double *h, double *t,  double *displ_fo_dipo_SHw_o, int len);

double displ_fo_dipo_SVw (
    double theta, double phi, double R, double moment, double alpha,
    double rho, double *h, double *t,  double *displ_fo_dipo_SVw_o, int len);	
