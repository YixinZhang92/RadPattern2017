/**
 * @short   Read input Headers
 * @file    read_in.h
 * @author  Yixin Zhang
 *
 * This file contains the prototypes all functions used for reading parameters in.
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

// Short description: These functions read the input parameters in the program
// -------------------------------------------------------------------------------------

int process_parameter(int argc, char* argv[], string *model_name, string *force_type,
                      float *alpha, float *beta, float *time_step, float *total_time,
                      string *waveform, float *area_x, float *area_y, int *n_x, int *n_y,
                      float *moment, float *rho);

int read_infile(int argc, char* argv[], string str[]);

int store_parameters(string str[], string *model_name, string *force_type, float *alpha, float *beta,
                     float *time_step, float *total_time, string *waveform, float *area_x, float *area_y,
                     int *n_x, int *n_y, float *moment, float *rho);

int read_string(string str[], int i, string variable_name, string &string_value);

int read_float(string str[], int i, string variable_name, float &float_value);

int read_int(string str[], int i, string variable_name, int &int_value);

int out_logfile(string *model_name, string *force_type, float *alpha, float *beta, float *time_step,
                float *total_time, string *waveform, float *area_x, float *area_y, int *n_x,
                int *n_y, float *moment, float *density);
