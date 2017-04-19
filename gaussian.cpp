/**
 * @short   gaussian
 * @file    gaussian.cpp
 * @author  Eric Jambo
 *
 * short description:This file contains the functions used to generate a guassian
 *                   function and its derivative using total time and time steps.
 *
 * Return   0 on sucess
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
#include "gaussian.h"

using namespace std;

// defining the value of PI.

#define PI 3.14159265

double gauss_func (double *h, double *h_der, int len, Parameters *params)

{

    double total_time = params->total_time; 
    double time_step = params->time_step;

    double a = 2.2/ total_time;  //Mean of distribution
    // set standard deviation to 1.0
    double sigma = 0.45;
    double s = 2.0 * sigma * sigma;
 
    // generate gaussian time function and its derivative
    for (double time = 0; time <= params->total_time; time = time + params->time_step) 
	
    {
        for (int i=0; i<len; i++)
        {

	    h[i] = (1/sqrt(PI * s))*(exp(-(pow(time - a,2))/s));
            
            h_der[i] = -(time - a)/(pow(s,3)*sqrt(2.0*PI))*(exp(-(pow(time - a,2))/s));
        }
    }
 return 0;
}

