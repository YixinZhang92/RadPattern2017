/**
 * @short   writing Headers
 * @file    writing.h
 * @author  Oluwaseun Fadugba
 *
 * This file contains the prototypes and a short description of all the functions used
 * to write all wave displacements,input waveform and its derivative and location
 * (x,y) into a file.
 */
 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cmath>
#include <cstdlib>

using namespace std;

// Short description: This function writes the all the P-, SH- and SV-wave displacements,
// input waveform and its derivative and its location (x,y) into a file
// --------------------------------------------------------------------------------------		

int wr_Pw_2_file (
    double *displ_pt_fo_Pw_o, double *displ_si_cpl_Pw_o,
    double *displ_do_cpl_Pw_o, double *displ_fo_dipo_Pw_o,
    double *h, double *h_der, double *t, double *t_der, double xx,
    double yy, string outputfilename, int len);

int wr_SVw_2_file (
    double *displ_pt_fo_Sw_o, double *displ_si_cpl_SVw_o,
    double *displ_do_cpl_SVw_o, double *displ_fo_dipo_SVw_o,
    double *h, double *h_der, double *t, double *t_der, double xx,
    double yy, string outputfilename, int len);

int wr_SHw_2_file (
    double *displ_pt_fo_Sw_o, double *displ_si_cpl_SHw_o,
    double *displ_do_cpl_SHw_o, double *displ_fo_dipo_SHw_o,
    double *h, double *h_der, double *t, double *t_der, double xy,
    double yy, string outputfilename, int len);
