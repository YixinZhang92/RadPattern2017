/**
 * @short   displacement Headers
 * @file    displ_calc.h
 * @author  Oluwaseun Fadugba, Yixin Zhang and Eric Jambo
 *
 * This function calculates the P-, SH- and SH-wave Displacements for
 * single force, double couple, force dipole and point forces using the values of theta,
 * phi, distance (R), moment (C1), S-wave velocity (beta), density (rho), the input
 * waveform (h) and its derivative, and the time series (time) and its derivative.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>

using namespace std;

int compute_displ (
    double theta, double R, double phi, double moment, double alpha, double beta,
    double rho, double *h, double *h_der,
    double *displ_P, double *displ_SH, double *displ_SV, int len, string force_type);
