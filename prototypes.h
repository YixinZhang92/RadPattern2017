#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;


/**
 * start form here, Yixin Zhang is testing her read in prototypes
 */
int read_string(string str[], int i, string variable_name,
                string &variable_value, ofstream &file);
int read_float(string str[], int i, string variable_name,
               float &variable_value, ofstream &file);

int read_in_inputfile (int argc, char* argv[], string s, int i, string str[], ifstream &infile);


int write_login_file (string str[], int i, string variable_name, string model_name,
                      string force_type, string wave_type, string waveform, float velocity,
                      float time_step, float total_time, float area_x, float area_y,
                      float grid_x, float grid_y, float moment, int read_string, int read_float,
                      ofstream &file);
/**
 * End here, by Yixin Zhang
 */



/**
 * @short   Main Program
 * @file    Mainfile_text.cpp
 * @authr   Yixin Zhang
 * @param   none
 * @return  0 on sucess
 *
 * Initial main file example
 * This is the main program that calls all the other functions and diplay a message for the user to know that are running.
 */
	double mesh_generator (double x, double y, double dx, double dy);
	int read_wave_file ();
	double displacement_point_force_P_wave (
	    double theta, double R, double moment, double alpha, 
	    double rho, double h[], double time[] );
	double displacement_point_force_S_wave (
	    double theta, double phi, double R, double moment, double beta, 
	    double rho, double h[], double time[] );
	double displacement_single_force_P_wave (
	    double theta, double phi, double R, double moment, double alpha, 
	    double rho, double h_derivative[], double time_derivative[] );
	double displacement_single_force_SH_wave (
	    double theta, double phi, double R, double moment, double alpha, 
	    double rho, double h_derivative[], double time_derivative[] );
	double displacement_single_force_SV_wave (
	    double theta, double phi, double R, double moment, double beta, 
	    double rho, double h_derivative[], double time_derivative[] );
	double displacement_double_couple_P_wave (
	    double theta, double phi, double R, double moment, double alpha, 
	    double rho, double h_derivative[], double time_derivative[] );
	double displacement_double_couple_SH_wave (
	    double theta, double phi, double R, double moment, double alpha, 
	    double rho, double h_derivative[], double time_derivative[] );
	double displacement_double_couple_SV_wave (
	    double theta, double phi, double R, double moment, double alpha, 
	    double rho, double h_derivative[], double time_derivative[] );
	double displacement_force_dipole_P_wave (
	    double theta, double phi, double R, double moment, double alpha, 
	    double rho, double h[], double time[] );
	double displacement_force_dipole_SH_wave (
	    double theta, double phi, double R, double moment, double alpha, 
	    double rho, double h[], double time[] );
	double displacement_force_dipole_SV_wave (
	    double theta, double phi, double R, double moment, double alpha, 
	    double rho, double h[], double time[] );

	int write_P_waves_to_file (
	    double displacement_point_force_P_wave_output[], double displacement_single_couple_P_wave_output[], 
	    double displacement_double_couple_P_wave_output[], double displacement_force_dipole_P_wave_output[], 
	    double h[], double h_derivative[], double time[], double time_derivative[], double x[], 
	    double y[], string outputfilename );
	int write_SV_waves_to_file (
	    double displacement_point_force_S_wave_output[], double displacement_single_couple_SV_wave_output[], 
	    double displacement_double_couple_SV_wave_output[], double displacement_force_dipole_SV_wave_output[], 
	    double h[], double h_derivative[], double time[], double time_derivative[], double x[], 
	    double y[], string outputfilename );
	int write_SH_waves_to_file (
	    double displacement_point_force_S_wave_output[], double displacement_single_couple_SH_wave_output[], 
	    double displacement_double_couple_SH_wave_output[], double displacement_force_dipole_SH_wave_output[], 
	    double h[], double h_derivative[], double time[], double time_derivative[], double x[], 
	    double y[], string outputfilename );

	
	double gaussian_function (double time[],double time_derivative[]);
	double derivative_waveform_function (double time[],double time_derivative[]);
	double cartesian_to_spherical_function (double x[],double y[]);
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

