/**
 * @short   Compute displacement Headers
 * @file    compute_displ.h
 * @author  Oluwaseun Fadugba
 *
 * This file contains the prototypes compute_displ.cpp and init_time.cpp
 *
 */
 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cmath>
#include <cstdlib>

using namespace std;

int compute_displ (
    double theta, double R, double phi, double *h, double *h_der,
    double *displ_P, double *displ_SH, double *displ_SV, int len, Parameters *params);

int init_time (double *t, Parameters *params);
