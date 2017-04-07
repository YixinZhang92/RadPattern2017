/**
 * @short   Radiation pattern Headers
 * @file    radiation.h
 * @author  Eric Jambo
 *
 * This file contains the prototypes and a short description of all the functions used
 * to calculate the radiation pattern.
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
// Short description: This function generates P-, SH- and SV-wave radiation patterns for 
// single couple force, double couple, force dipole and point forces using the values of 
// theta and phi
// -------------------------------------------------------------------------------------

double radp_Pw_si_cpl (double theta, double phi);

double radp_SHw_si_cpl (double theta, double phi);

double radp_SVw_si_cpl (double theta, double phi);

double radp_Pw_do_cpl (double theta, double phi);

double radp_SHw_do_cpl (double theta, double phi);

double radp_SVw_do_cpl (double theta, double phi);

double radp_Pw_fo_dipo (double theta, double phi);

double radp_SHw_fo_dipo (double theta, double phi);

double radp_SVw_fo_dipo (double theta, double phi);

double radp_Pw_pt_fo (double theta, double phi);

double radp_SHw_pt_fo (double theta, double phi);

double radp_SVw_pt_fo (double theta, double phi);
