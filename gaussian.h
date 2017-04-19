/**
 * @short   gaussian Headers
 * @file    gaussian.h
 * @author  Eric Jambo
 *
 * This file contains the prototypes and a short description of all the functions used
 * to generate a guassian function and its derivative using total time and time steps.
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
// Short description: These functions generate a guassian function and its derivative 
// using total time and time steps
// ------------------------------------------------------------------------------------

double gauss_func (double total_time, double time_step, double *h, double *h_der, int len);

