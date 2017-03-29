
/**
 * @mainpage RadPattern101
 *
 * Welcome to the Radiation Pattern Program (RadPattern101).
 * This program is a term project in Programming Tools course with Dr. Ricardo Taborda at the University of Memphis in Spring 2017.
 *
 * The team members are Oluwaseun Fadugba, Yixin Zhang and Eric Jambo.
 *
 * In this project, we are going to generate the radiation pattern, wave propagation map, and seismic waves at a specific location in the specified grid.
 * This program requires the type of force (point force, force dipole, double couple or single couple) that radiation pattern should be generated for. The
 * program also requires the type of wave e.g. P-, SV- or SH- waves and the rock properties through they propagate.
 *
 * Another aspect of the program is to generate a time-map of the wavepropagation with epicentral distance given an input waveform at the source. The default source
 * input waveform in this program is a Gaussian function.
 *
 * lastly, we also can display the waveform at a particular epicentral distance after incorporating the influence of radiation pattern for the particular waveform as input.
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include "prototypes.h"
using namespace std;

/**
 * @short   Main program
 * @file    main.cpp
 * @author  Oluwaseun Fadugba, Yixin Zhang and Eric Jambo
 * @param   EQinfo1.txt
 * @return  0 on success
 *
 * In this project, we are going to generate the radiation pattern, wave propagation map, and seismic waves at a specific location in the specified grid.
 * This program requires the type of force (point force, force dipole, double couple or single couple) that radiation pattern should be generated for. The
 * program also requires the type of wave e.g. P-, SV- or SH- waves and the rock properties through they propagate.
 *
 * Another aspect of the program is to generate a time-map of the wavepropagation with epicentral distance given an input waveform at the source. The default source
 * input waveform in this program is a Gaussian function.
 *
 * Lastly, we also can display the waveform at a particular epicentral distance after incorporating the influence of radiation pattern for the particular waveform as input.
 *
 */


// defining the value of PI.

#define PI 3.14159265
 
int main(int argc, char* argv[])

{
	
 
// This function calls all the functions used in this program.
 
// Reading in the parameters from a file
// Read_in functions: This function read the input waveforms in the program
// -----------------------------------------------------------------------------------------------
 
    //  Changed by Yixin Zhang, test for adding readin program
    int i;
    string str[100];
    string s, variable_name, string_value;
    string model_name, force_type, wave_type, waveform;
    float velocity, time_step, total_time, area_x, area_y,
        grid_x, grid_y, moment, float_value;
    
    ifstream infile;
    ofstream logfile;

    // Trying to make readin file works in the command line
	
    if(argc < 2)
    {
        cout << "Missing inputfile, please check\n";
        return EXIT_FAILURE;
    }
    
    //  open the input file and read the parameters in string format
 
    infile.open(argv[1]);
    
    i = 0;
    while( infile >> s )
    {
        str[i] = s;
        i++;
    }
    
    infile.close();
    cout << "It is Reading info file\n";
    
    //  Open the log file, and wtite variable values into login file
    logfile.open("login.txt");
    //    string line;
    
    i = 0;
    while(str[i] != "")
    {
        if(str[i] == "model_name")
            read_string(str, i, variable_name, model_name, logfile);
        
        if(str[i] == "force_type")
            read_string(str, i, variable_name, force_type, logfile);
        
        if(str[i] == "wave_type")
            read_string(str, i, variable_name, wave_type, logfile);
        
        if(str[i] == "waveform")
            read_string(str, i, variable_name, waveform, logfile);
        
        
        if(str[i] == "velocity")
            read_float(str, i, variable_name, velocity, logfile);
        
        if(str[i] == "time_step")
            read_float(str, i, variable_name, time_step, logfile);
        
        if(str[i] == "total_time")
            read_float(str, i, variable_name, total_time, logfile);
        
        if(str[i] == "area_x")
            read_float(str, i, variable_name, area_x, logfile);
        
        if(str[i] == "area_y")
            read_float(str, i, variable_name, area_y, logfile);
        
        if(str[i] == "grid_x")
            read_float(str, i, variable_name, grid_x, logfile);
        
        if(str[i] == "grid_y")
            read_float(str, i, variable_name, grid_y, logfile);
        
        if(str[i] == "moment")
            read_float(str, i, variable_name, moment, logfile);
        
        i++;
    }
    
    logfile.close();
    
    cout << "login file has been written./n" ;
	

//  Read in prototype test
//    int read_in_inputfile, write_login_file, read_string, read_float;
    
read_string (str, i, variable_name, string_value, logfile);

read_float (str, i, variable_name, float_value, logfile);
    

//  End of test by Yixin Zhang
    
    
// ------------------------------------------------------------------------------------------------
// These parameters (in this bracket) are supposed to be from the input file. I initialize them here to make things work. We will delete them when the everything is working.

int length = 9;

double *time;	              time = new double[length];

double *x;	              x = new double[100];
double *y;	              y = new double[100];

double *h;	              h = new double[length];
double *h_derivative;	      h_derivative = new double[length];
double *time_derivative;      time_derivative = new double[length];

double *dx;	              dx = new double[1];
double *dy;	              dy = new double[1];

string outputfilename;
		
// Initialize the old vector.
for (int i=0; i<length; i++)
{
    h[i] = double(i);

    h_derivative[i] = double(i);

    time[i] = double(i);

    time_derivative[i] = double(i);
}

// ----------------------------------------------------------------------------------------------



double *displacement_point_force_P_wave_output;	        displacement_point_force_P_wave_output = new double[length];
double *displacement_point_force_S_wave_output;	        displacement_point_force_S_wave_output = new double[length];
double *displacement_single_couple_P_wave_output;	displacement_single_couple_P_wave_output = new double[length];
double *displacement_single_couple_SV_wave_output;	displacement_single_couple_SV_wave_output = new double[length];
double *displacement_single_couple_SH_wave_output;	displacement_single_couple_SH_wave_output = new double[length];
double *displacement_double_couple_P_wave_output;	displacement_double_couple_P_wave_output = new double[length];
double *displacement_double_couple_SV_wave_output;	displacement_double_couple_SV_wave_output = new double[length];
double *displacement_double_couple_SH_wave_output;	displacement_double_couple_SH_wave_output = new double[length];
double *displacement_force_dipole_P_wave_output;	displacement_force_dipole_P_wave_output = new double[length];
double *displacement_force_dipole_SV_wave_output;	displacement_force_dipole_SV_wave_output = new double[length];
double *displacement_force_dipole_SH_wave_output;	displacement_force_dipole_SH_wave_output = new double[length];




// These functions generates a guassian function and its derivative using total time and time steps
// -----------------------------------------------------------------------------------------------

 
gaussian_function (time, time_derivative);

derivative_waveform_function (time, time_derivative);
	
		
// This function gives the x,y coordinates for every point and returns the spherical coordinates for each grid
// -----------------------------------------------------------------------------------------------
 
mesh_generator (3.0, 2.0, 0.7, 0.5);
		

// This function converts the cartesian coordinates into spherical coordinates using location(x,y)
// ---------------------------------------------------------------------------------------------------	
cartesian_to_spherical_function (x, y);


// This function generates P-, SH- and SV-wave radiation patterns for single couple force, double couple, 
// force dipole and point forces using the values of theta and phi
// -----------------------------------------------------------------------------------------------
 
radiation_pattern_P_wave_single_couple_force (4.0, 2.9);

radiation_pattern_SH_wave_single_couple_force (4.0, 2.9);

radiation_pattern_SV_wave_single_couple_force (4.0, 2.9);

radiation_pattern_P_wave_double_couple_force (4.0, 2.9);

radiation_pattern_SH_wave_double_couple_force (4.0, 2.9);

radiation_pattern_SV_wave_double_couple_force (4.0, 2.9);

radiation_pattern_P_wave_force_dipole (4.0, 2.9);

radiation_pattern_SH_wave_force_dipole (4.0, 2.9);

radiation_pattern_SV_wave_force_dipole (4.0, 2.9);

radiation_pattern_P_wave_point_force (1.9, 1.0);

radiation_pattern_SH_wave_point_force (1.5, 1.0);

radiation_pattern_SV_wave_point_force (1.6, 1.0);
	
	
	
// Short description: This function calculates the P-, SH- and SH-wave Displacements for single force, double couple, force dipole 
// and point forces using the values of theta, phi, distance (R), moment (C1), S-wave velocity (beta), density (rho), the input 
// waveform (h) and its derivative, and the time series (time) and its derivative.
// -----------------------------------------------------------------------------------------------	
	
	
displacement_point_force_P_wave (3.9, 3.5, 2.8, 3.5, 3.7, h, time, 
    displacement_point_force_P_wave_output, 9 );
	
displacement_point_force_S_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h, time, 
    displacement_point_force_P_wave_output, 9 );
	
displacement_single_force_P_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_derivative, 
    time_derivative, displacement_point_force_P_wave_output, 9 );
	
displacement_single_force_SH_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_derivative, 
    time_derivative, displacement_point_force_P_wave_output, 9  );
	
displacement_single_force_SV_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_derivative, 
    time_derivative, displacement_point_force_P_wave_output, 9  );
	
displacement_double_couple_P_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_derivative, 
    time_derivative, displacement_point_force_P_wave_output, 9  );
	
displacement_double_couple_SH_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_derivative, 
    time_derivative, displacement_point_force_P_wave_output, 9  );
	
displacement_double_couple_SV_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_derivative, 
    time_derivative, displacement_point_force_P_wave_output, 9  );
	
displacement_force_dipole_P_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h, time, 
    displacement_point_force_P_wave_output, 9  );
	
displacement_force_dipole_SH_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h, time, 
    displacement_point_force_P_wave_output, 9  );
	
displacement_force_dipole_SV_wave (3.0, 2.0, 5.9, 2.8, 2.5, 4, h, time, 
    displacement_point_force_P_wave_output, 9  );
	
	
// This function writes the all the P-, SH- and SV-wave displacements, input waveform and its derivative and its location (x,y) into a file
// -----------------------------------------------------------------------------------------------	
  

// it is not printing the correct answer. I will need to fix it. I am still working on how to print to a binary file.


write_P_waves_to_file (
    displacement_point_force_P_wave_output, displacement_single_couple_P_wave_output,
    displacement_double_couple_P_wave_output, displacement_force_dipole_P_wave_output, h,
    h_derivative, time, time_derivative, 6.0, 7.0, "outputfilename.txt",length);
	
write_SV_waves_to_file (
    displacement_point_force_S_wave_output, displacement_single_couple_SV_wave_output,
    displacement_double_couple_SV_wave_output,displacement_force_dipole_SV_wave_output,h,
    h_derivative,  time, time_derivative,  6.0, 7.0, "outputfilename.txt",length);
		
write_SH_waves_to_file (
    displacement_point_force_S_wave_output, displacement_single_couple_SH_wave_output,
    displacement_double_couple_SH_wave_output, displacement_force_dipole_SH_wave_output, h,
    h_derivative,  time, time_derivative,  6.0, 7.0, "outputfilename.txt",length);


	

cout << "\n"
    "I have completed running all the prototypes,\n";
    "Goodbye.";
cout << endl;

}
