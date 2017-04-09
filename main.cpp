/**
 * @mainpage RadPattern101
 *
 * Welcome to the Radiation Pattern Program (RadPattern101).
 * This program is a term project in Programming Tools course with Dr. Ricardo Taborda at
 * the University of Memphis in Spring 2017.
 *
 * The team members are Oluwaseun Fadugba, Yixin Zhang and Eric Jambo.
 *
 * In this project, we are going to generate the radiation pattern, wave propagation map,
 * and seismic waves at a specific location in the specified grid. This program requires
 * the type of force (point force, force dipole, double couple or single couple) that 
 * radiation pattern should be generated for. The program also requires the type of wave
 * e.g. P-, SV- or SH- waves and the rock properties through they propagate.
 *
 * Another aspect of the program is to generate a time-map of the wavepropagation with 
 * epicentral distance given an input waveform at the source. The default source input
 * waveform in this program is a Gaussian function.
 *
 * lastly, we also can display the waveform at a particular epicentral distance after
 * incorporating the influence of radiation pattern for the particular waveform as input.
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "prototypes.h"
using namespace std;

// defining the value of PI.
#define PI 3.14159265

/**
 * @short   Main program
 * @file    main.cpp
 * @author  Oluwaseun Fadugba, Yixin Zhang and Eric Jambo
 * @param   EQinfo1.txt
 * @return  0 on success
 *
 * In this project, we are going to generate the radiation pattern, wave propagation map,
 * and seismic waves at a specific location in the specified grid. This program requires
 * the type of force (point force, force dipole, double couple or single couple) that
 * radiation pattern should be generated for. The program also requires the type of wave
 * e.g. P-, SV- or SH- waves and the rock properties through they propagate.
 *
 * Another aspect of the program is to generate a time-map of the wavepropagation with
 * epicentral distance given an input waveform at the source. The default source
 * input waveform in this program is a Gaussian function.
 *
 * Lastly, we also can display the waveform at a particular epicentral distance after
 * incorporating the influence of radiation pattern for the particular waveform as input.
 *
 * Please find below some mnemonics used in this project:
 *
 * time              = t
 *
 * displacement      = displ
 *
 * point_force       = pt_fo
 *
 * single_couple     = si_cpl
 * 
 * double_couple     = do_cpl
 *
 * force_dipole      = fo_dipo
 *
 * output            = o
 *
 * wave              = w
 *
 * write             = wr
 *
 * generator         = gen
 *
 * spherical         = sph
 *
 * cartessian        = cart
 *
 * to                = 2
 *
 * derivative        = der
 *
 * waveform          = wavf
 *
 * function          = func
 *
 * gaussian          = gauss
 *
 * Radiation_pattern = radp
 *
 */

int main(int argc, char* argv[])
{

// This function calls all the functions used in this program.

// Reading in the parameters from a file
// Read_in functions: This function read the input waveforms in the program

// -----------------------------------------------------------------------------------------------
    
 
    //  Changed by Yixin Zhang, test for adding readin program
    int n_x, n_y;
    string model_name, force_type, wave_type, waveform;
    float velocity, time_step, total_time, area_x, area_y, moment;
    ifstream infile;
    ofstream logfile, outfile;
    
    // read_in function
    read_in_parameters(argc, argv, model_name, force_type, wave_type, velocity,
                       time_step, total_time, waveform, area_x, area_y, n_x, n_y,
                       moment, infile, logfile, outfile);
    
    //  End of test by Yixin Zhang
    
    // -------------------------------------------------------------------------
    // These parameters (in this bracket) are supposed to be from the input file.
    // I initialize them here to make things work. We will delete them when the
    // everything is working.
    // -------------------------------------------------------------------------

    int len = 9;

    double *t;	                                t     = new double[len];

    double *x;	                                x     = new double[100];
    double *y;	                                y     = new double[100];
    double *dx;	                                dx    = new double[1];
    double *dy;	                                dy    = new double[1];

    double *h;	                                h     = new double[len];
    double *h_der;                              h_der = new double[len];
    double *t_der;                              t_der = new double[len];

    string outputfilename;

    // Initialize the old vector.
    for (int i=0; i<len; i++)
    {
         h[i]     = double(i);
         h_der[i] = double(i);
         t[i]     = double(i);
         t_der[i] = double(i);
     }

    double *displ_pt_fo_Pw_o;	  displ_pt_fo_Pw_o    = new double[len];
    double *displ_pt_fo_Sw_o;     displ_pt_fo_Sw_o    = new double[len];
    double *displ_si_cpl_Pw_o;	  displ_si_cpl_Pw_o   = new double[len];
    double *displ_si_cpl_SVw_o;	  displ_si_cpl_SVw_o  = new double[len];
    double *displ_si_cpl_SHw_o;	  displ_si_cpl_SHw_o  = new double[len];
    double *displ_do_cpl_Pw_o;	  displ_do_cpl_Pw_o   = new double[len];
    double *displ_do_cpl_SVw_o;	  displ_do_cpl_SVw_o  = new double[len];
    double *displ_do_cpl_SHw_o;	  displ_do_cpl_SHw_o  = new double[len];
    double *displ_fo_dipo_Pw_o;	  displ_fo_dipo_Pw_o  = new double[len];
    double *displ_fo_dipo_SVw_o;  displ_fo_dipo_SVw_o = new double[len];
    double *displ_fo_dipo_SHw_o;  displ_fo_dipo_SHw_o = new double[len];

    // These functions generates a guassian function and its derivative using 
    // total time and time steps
    // ------------------------------------------------------------------------

    gauss_func (t, t_der);

    der_wavf_func (t, t_der);

		
    // This function gives the x,y coordinates for every point and returns the spherical coordinates for each grid
    // -----------------------------------------------------------------------------------------------
    

    
    // Output file open
    outfile.open("output.txt");
    float* X = new float[n_x];
    float* Y = new float[n_y];
    mesh_gen_o (area_x, area_y, n_x, n_y, X, Y, outfile);
    


    // This function converts the cartesian coordinates into spherical coordinates
    // using location(x,y)
    // ----------------------------------------------------------------------------------	

    cart_2_sph (x, y);
    cout << n_x << endl << "\n";

    // This function generates P-, SH- and SV-wave radiation patterns for single couple force,
    // double couple, force dipole and point forces using the values of theta and phi.
    // --------------------------------------------------------------------------------------

    radp_Pw_si_cpl (4.0, 2.9);
    radp_SHw_si_cpl (4.0, 2.9);
    radp_SVw_si_cpl (4.0, 2.9);

    radp_Pw_do_cpl (4.0, 2.9);
    radp_SHw_do_cpl (4.0, 2.9);
    radp_SVw_do_cpl (4.0, 2.9);

    radp_Pw_fo_dipo (4.0, 2.9);
    radp_SHw_fo_dipo (4.0, 2.9);
    radp_SVw_fo_dipo (4.0, 2.9);

    radp_Pw_pt_fo (1.9, 1.0);
    radp_SHw_pt_fo (1.5, 1.0);
    radp_SVw_pt_fo (1.6, 1.0);

    // Short description: This function calculates the P-, SH- and SH-wave Displacements for
    // single force, double couple, force dipole and point forces using the values of theta,
    // phi, distance (R), moment (C1), S-wave velocity (beta), density (rho), the input
    // waveform (h) and its derivative, and the time series (time) and its derivative.
    // -------------------------------------------------------------------------------------

    displ_pt_fo_Pw (3.9, 3.5, 2.8, 3.5, 3.7, h, t, displ_pt_fo_Pw_o, 9);
    displ_pt_fo_Sw (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h, t, displ_pt_fo_Pw_o, 9);

    displ_si_cpl_Pw (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_der, t_der, displ_si_cpl_Pw_o, 9);
    displ_si_cpl_SHw (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_der, t_der, displ_si_cpl_SHw_o, 9);
    displ_si_cpl_SVw (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_der, t_der, displ_si_cpl_SVw_o, 9);

    displ_do_cpl_Pw (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_der, t_der, displ_do_cpl_Pw_o, 9);
    displ_do_cpl_SHw (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_der, t_der, displ_do_cpl_SHw_o, 9);
    displ_do_cpl_SVw (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_der, t_der, displ_do_cpl_SVw_o, 9);

    displ_fo_dipo_Pw (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h, t, displ_fo_dipo_Pw_o, 9);
    displ_fo_dipo_SHw (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h, t, displ_fo_dipo_SHw_o, 9);
    displ_fo_dipo_SVw (3.0, 2.0, 5.9, 2.8, 2.5, 4, h, t, displ_fo_dipo_SVw_o, 9);

    // This function writes the all the P-, SH- and SV-wave displacements, input waveform
    // and its derivative and its location (x,y) into a file.
    // ----------------------------------------------------------------------------------

    // it is not printing the correct answer. I will need to fix it. I am still working
    // on how to print to a binary file.

    wr_Pw_2_file (
        displ_pt_fo_Pw_o, displ_si_cpl_Pw_o, displ_do_cpl_Pw_o, displ_fo_dipo_Pw_o, h,
        h_der, t, t_der, 6.0, 7.0, "outputfilename.txt", len);

    wr_SVw_2_file (
        displ_pt_fo_Sw_o, displ_si_cpl_SVw_o, displ_do_cpl_SVw_o,displ_fo_dipo_SVw_o,h,
        h_der, t, t_der, 6.0, 7.0, "outputfilename.txt", len);

    wr_SHw_2_file (
        displ_pt_fo_Sw_o, displ_si_cpl_SHw_o, displ_do_cpl_SHw_o, displ_fo_dipo_SHw_o, h,
        h_der,  t, t_der,  6.0, 7.0, "outputfilename.txt",len);
    
    // Output file close
    outfile.close();


    cout << "\n"
        "I have completed running all the prototypes,\n";
        "Goodbye.";
    cout << endl;
}
