/**
 * @short   Struct Headers
 * @file    read_in.h
 * @author  Yixin Zhang
 *
 * This file contains the definition of struct Parameters.
 *
 */

#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>

using namespace std;

#ifndef parameters
#define parameters

struct Parameters
{
    // declare all element in struct
    int n_x, n_y;
    string model_name, force_type, waveform, logfile_path, outputfile_path;
    float alpha, beta, time_step, total_time, length_x, length_y, moment, rho;
};

#endif

