/**
 * @short   Prototype Headers
 * @file    prototypes.h
 * @author  Oluwaseun Fadugba, Yixin Zhang and Eric Jambo
 *
 * This file contains the prototypes and a short description of all the functions used in the RadPattern101 program.
 */
 
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cmath>
#include <cstdlib>

using namespace std;
// defining the value of PI.

#define PI 3.14159265


//
// Reading in the parameters from a file
//
// Author:            Yixin Zhang
//
// Short description: These functions read the input waveforms in the program
//
// -----------------------------------------------------------------------------------------------
//	

int read_string(string str[], int i, string variable_name,
    string &string_value, ofstream &file);

int read_float(string str[], int i, string variable_name,
    float &float_value, ofstream &file);

int read_wave_file ();


//
// Function:          gaussian_function and its derivative
//
// Author:            Eric Jambo
//
// Short description: These functions generates a guassian function and its derivative using total time and time steps
//
// -----------------------------------------------------------------------------------------------
//


double gaussian_function (double time[],double time_derivative[]);

double derivative_waveform_function (double time[],double time_derivative[]);



//
// Function:          Mesh_generator
//
// Author:            Yixin Zhang
//
// Short description: This function gives the x,y coordinates for every point and returns the spherical coordinates for each grid
//
// -----------------------------------------------------------------------------------------------
//

double mesh_generator (double x, double y, double dx, double dy);


//
// Function:          cartesian_to_spherical_function
//
// Author:            Eric Jambo
//
// Short description: This function converts the cartesian coordinates into spherical coordinates using location(x,y)
//
// -----------------------------------------------------------------------------------------------
//


double cartesian_to_spherical_function (double *x,double *y);


//
// Functions:         Radiation_pattern
//
// Author:            Eric Jambo
//
// Short description: This function generates P-, SH- and SV-wave radiation patterns for single couple force, double couple, 
//                    force dipole and point forces using the values of theta and phi
//
// -----------------------------------------------------------------------------------------------
//

double radiation_pattern_P_wave_single_couple_force (double theta,double phi);

double radiation_pattern_SH_wave_single_couple_force (double theta,double phi);

double radiation_pattern_SV_wave_single_couple_force (double theta,double phi);

double radiation_pattern_P_wave_double_couple_force (double theta,double phi);

double radiation_pattern_SH_wave_double_couple_force (double theta,double phi);

double radiation_pattern_SV_wave_double_couple_force (double theta,double phi);

double radiation_pattern_P_wave_force_dipole (double theta,double phi);

double radiation_pattern_SH_wave_force_dipole (double theta,double phi);

double radiation_pattern_SV_wave_force_dipole (double theta,double phi);

double radiation_pattern_P_wave_point_force (double theta,double phi);

double radiation_pattern_SH_wave_point_force (double theta,double phi);

double radiation_pattern_SV_wave_point_force (double theta,double phi);


//
// Functions:         displacement
//
// Author:            Oluwaseun Fadugba
//
// Short description: This function calculates the P-, SH- and SH-wave Displacements for single force, double couple, force dipole and point forces 
//                    using the values of theta, phi, distance (R), moment (C1), S-wave velocity (beta), density (rho), the input waveform (h) and its derivative, and the time series (time) and its derivative.
//
// -----------------------------------------------------------------------------------------------
//	


int displacement_point_force_P_wave (
    double theta, double R, double moment, double alpha, 
    double rho, double *h, double *time, double *displacement_point_force_P_wave_output, int len );

double displacement_point_force_S_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double *h, double *time, double *displacement_point_force_S_wave_output, int len  );

double displacement_single_force_P_wave (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double *h_derivative, double *time_derivative, double *displacement_single_force_P_wave_output, int len  );

double displacement_single_force_SH_wave (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double *h_derivative, double *time_derivative, double *displacement_single_force_SH_wave_output, int len  );

double displacement_single_force_SV_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double *h_derivative, double *time_derivative, double *displacement_single_force_SV_wave_output, int len  );

double displacement_double_couple_P_wave (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double *h_derivative, double *time_derivative, double *displacement_double_couple_P_wave_output, int len  );

double displacement_double_couple_SH_wave (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double *h_derivative, double *time_derivative, double *displacement_double_couple_SH_wave_output, int len  );

double displacement_double_couple_SV_wave (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double *h_derivative, double *time_derivative, double *displacement_double_couple_SV_wave_output, int len  );

double displacement_force_dipole_P_wave (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double *h, double *time,  double *displacement_force_dipole_P_wave_output, int len  );

double displacement_force_dipole_SH_wave (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double *h, double *time,  double *displacement_force_dipole_SH_wave_output, int len   );

double displacement_force_dipole_SV_wave (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double *h, double *time,  double *displacement_force_dipole_SV_wave_output, int len   );

		
		
		
//
// Functions:         write_results_to_file
//
// Author:            Oluwaseun Fadugba
//
// Short description: This function writes the all the P-, SH- and SV-wave displacements, input waveform and its derivative and its location (x,y) into a file
//                   
// -----------------------------------------------------------------------------------------------
//			
		

int write_P_waves_to_file (
    double *displacement_point_force_P_wave_output, double *displacement_single_couple_P_wave_output, 
    double *displacement_double_couple_P_wave_output, double *displacement_force_dipole_P_wave_output, 
    double *h, double *h_derivative, double *time, double *time_derivative, double xx, 
    double yy, string outputfilename , int len);

int write_SV_waves_to_file (
    double *displacement_point_force_S_wave_output, double *displacement_single_couple_SV_wave_output, 
    double *displacement_double_couple_SV_wave_output, double *displacement_force_dipole_SV_wave_output, 
    double *h, double *h_derivative, double *time, double *time_derivative, double xx, 
    double yy, string outputfilename, int len);

int write_SH_waves_to_file (
    double *displacement_point_force_S_wave_output, double *displacement_single_couple_SH_wave_output, 
    double *displacement_double_couple_SH_wave_output, double *displacement_force_dipole_SH_wave_output, 
    double *h, double *h_derivative, double *time, double *time_derivative, double xy, 
    double yy, string outputfilename, int len);

