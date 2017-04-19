/**
 * @short   write Headers
 * @file    write2file.h
 * @author  Oluwaseun Fadugba, Yixin Zhang and Eric Jambo
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

using namespace std;

int write_2_file (
    double *displ_P, double *displ_SH, double *displ_SV, 
    double *rad_P, double *rad_SH, double *rad_SV, 
    double *t, double xx, double yy, string outputfilename, int len);
