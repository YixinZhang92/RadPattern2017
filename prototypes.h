/**
 * @short   Prototype Headers
 * @file    prototypes.h
 * @author  Oluwaseun Fadugba, Yixin Zhang and Eric Jambo
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

int check_file_num(int argc, int flag);

int check_file_open(ifstream &infile, int flag1);

int check_variables(float *alpha, float *beta, float *time_step, float *total_time,
                    float *area_x, float *area_y, int *n_x, int *n_y, float *moment,
                    int flag2);

int read_in_parameters(int argc, char* argv[], string *model_name, string *force_type,
                       float *alpha, float *beta, float *time_step, float *total_time,
                       string *waveform, float *area_x, float *area_y, int *n_x, int *n_y,
                       float *moment, ifstream &infile, int flag);

int read_string(string str[], int i, string variable_name, string &string_value);

int read_float(string str[], int i, string variable_name, float &float_value);

int read_int(string str[], int i, string variable_name, int &int_value);

int out_login(string *model_name, string *force_type, float *alpha, float *beta, float *time_step,
              float *total_time, string *waveform, float *area_x, float *area_y, int *n_x,
              int *n_y, float *moment, ofstream &file);


int read_wave_file ();

// Short description: These functions generates a guassian function and its derivative 
// using total time and time steps
// ------------------------------------------------------------------------------------

double gauss_func (double t[], double t_der[]);

double der_wavf_func (double t[], double t_der[]);

// Short description: This function gives the x,y coordinates for every point and returns
// the spherical coordinates for each grid
// -------------------------------------------------------------------------------------


int mesh_gen_o (float area_x, float area_y, int n_x, int n_y, float X[], float Y[], ofstream &file);

// Short description: This function converts the cartesian coordinates into spherical
// coordinates using location(x,y)
// ----------------------------------------------------------------------------------

double cart_2_sph (double xx, double yy);

// Short description: This function generates P-, SH- and SV-wave radiation patterns for 
// single couple force, double couple, force dipole and point forces using the values of 
// theta and phi
// -------------------------------------------------------------------------------------

double radp (double theta, double phi);
