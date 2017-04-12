/**
 * @short   Read input Headers
 * @file    read_in.h
 * @author  Eric Jambo
 *
 * This file contains the prototypes and a short description of all the functions used
 * in the RadPattern101 program.
 */
 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

// defining the value of PI.
#define PI 3.14159265

// Short description: These functions read the input waveforms in the program
// -------------------------------------------------------------------------------------

int check_file_num(int argc);

int check_file_open(ifstream &infile);

int check_variables(float *alpha, float *beta, float *time_step, float *total_time, float *area_x,
                    float *area_y, int *n_x, int *n_y, float *moment, float *density);

int read_in_parameters(int argc, char* argv[], string *model_name, string *force_type,
                       float *alpha, float *beta, float *time_step, float *total_time,
                       string *waveform, float *area_x, float *area_y, int *n_x, int *n_y,
                       float *moment, float *density, ifstream &infile);

int read_string(string str[], int i, string variable_name, string &string_value);

int read_float(string str[], int i, string variable_name, float &float_value);

int read_int(string str[], int i, string variable_name, int &int_value);

int out_login(string *model_name, string *force_type, float *alpha, float *beta, float *time_step,
              float *total_time, string *waveform, float *area_x, float *area_y, int *n_x,
              int *n_y, float *moment, float *density, ofstream &file);

