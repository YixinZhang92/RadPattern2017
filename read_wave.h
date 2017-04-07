/**
 * @short   read wave Headers
 * @file    read_wave.h
 * @author  Oluwaseun Fadugba, Yixin Zhang and Eric Jambo
 *
 * This file contains the prototype and a short description of the function used
 * to read the input waveform.
 */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cmath>
#include <cstdlib>

using namespace std;

// Short description: These functions read the input waveforms in the program
// -------------------------------------------------------------------------------------

int read_string(string str[], int i, string variable_name,
    string &string_value, ofstream &file);

int read_float(string str[], int i, string variable_name,
    float &float_value, ofstream &file);

int read_wave_file ();
