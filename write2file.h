/**
 * @short   write Headers
 * @file    write2file.h
 * @author  Oluwaseun Fadugba
 *
 * This function writes the all the P-, SH- and SV-wave displacements, radiation pattern,
 * and its location (x,y) into a file.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>

#include "struct.h"

using namespace std;

int write_2_file (
    displacement *displ, 
    double *rad_P, double *rad_SH, double *rad_SV, 
    double *t, double xx, double yy, string outputfilename, int len);

int write_displ (
    displacement *displ,
    double *t, double xx, double yy, string outputfilename, int len);

int write_rad_patt (
    double *rad_P, double *rad_SH, double *rad_SV, 
    double xx, double yy, string outputfilename);
