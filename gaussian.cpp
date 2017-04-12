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
#include "gaussian.h"

using namespace std;

// defining the value of PI.

#define PI 3.14159265

double gauss_func (double total_time, double time_step, double value, double gauss_der)

{

    double a = 2.2/ total_time;  //Mean of distribution
    // set standard deviation to 1.0
    double sigma = 0.45;
    double s = 2.0 * sigma * sigma;
 
    // generate gaussian time function and its derivative
    for (double t = 0; t <= total_time; t = t + time_step) 
	
    {
	    value = (1/sqrt(PI * s))*(exp(-(pow(t-a,2))/s));
            gauss_der = -(t-a)/(pow(s,3)*sqrt(2.0*PI))*(exp(-(pow(t-a,2))/s));
    }

 return 0;
}

