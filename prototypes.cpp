/**
 * @short   Prototypes
 * @file    prototypes.cpp
 * @author  Oluwaseun Fadugba, Yixin Zhang and Eric Jambo
 *
 * This file contains the prototypes and a short description of all the functions used in the RadPattern101 program.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include "prototypes.h"
using namespace std;

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function float inputs
 *
 * Return             0 on sucess
 
 * Return             EXIT_FAILURE when the input file is missing
 */
 
// Just test, try to add read in program
// made by Yixin Zhang
//

int read_string(string str[], int i, string variable_name,
    string &string_value, ofstream &file)

{
	
    variable_name = str[i];
    file << variable_name << "=\t" << endl;
    cout << variable_name << "=\t" << endl;
    
    string_value = str[i+1];
    file << string_value << endl << "\n";
    cout << string_value << endl << "\n";
    
    return 0;

}

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function float inputs
 *
 * Return             0 on sucess
 *
 */

 int read_float(string str[], int i, string variable_name,
    float &float_value, ofstream &file)

{

    char* c;
    
    variable_name = str[i];
    file << variable_name << "=\t" << endl;
    cout << variable_name << "=\t" << endl;
    
    c = const_cast<char*>(str[i+1].c_str());
    sscanf(c,"%e", &float_value);
    file << float_value << endl << "\n";
    cout << float_value << endl << "\n";
    
    return 0;

}

//  End of test by Yixin Zhang

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function gives the x,y coordinates for every point and returns the spherical coordinates for each grid
 *
 * Return             0 on sucess
 *
 */
 
double mesh_generator (double x, double y, double dx, double dy)

{
	
    cout <<  "Running: mesh_generator\n";
    cout << endl;
  
    return 0;

}

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function read the input waveforms in the program
 *
 * Return             0 on sucess
 * The distance between \f$(x_1,y_1)\f$ and \f$(x_2,y_2)\f$ is \f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.
 */
 
int read_wave_file ()

{

    cout << "Running: read_wave_file\n";
    cout << endl;

    return 0;
  
}


 /**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the P-wave Displacement for single force using the values of theta, phi, 
 *                    distance (R), moment (C1), P-wave velocity (alpha), density (rho), the input waveform (h) and the time series (time).
 *
 * Return             0 on sucess
 *
 */

double displacement_point_force_P_wave (
    double theta, double R, double moment, double alpha, 
    double rho, double h[], double time[] )

{

    cout <<  "Running: displacement_point_force_P_wave\n";
    cout << endl;

    return 0;

}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the S-wave Displacement for single force using the values of theta, phi,
 *                    distance (R), moment (C1), S-wave velocity (beta), density (rho), the input waveform (h) and the time series (time).
 *
 * Return             0 on sucess
 *
 */

double displacement_point_force_S_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double h[], double time[] )

{
	
    cout <<  "Running: displacement_point_force_S_wave\n";
    cout << endl;

    return 0;

}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the P-wave Displacement for single force using the values of theta, phi,
 *                    distance (R), moment (C1), P-wave velocity (alpha), density (rho), derivative of the input waveform (h) and derivative of the time series (time). 
 *
 * Return             0 on sucess
 *
 */
 
double displacement_single_force_P_wave (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double h_derivative[], double time_derivative[] )

{
    cout <<  "Running: displacement_single_force_P_wave\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the SH-wave Displacement for single force using the values of theta, phi,
 *                    distance (R), moment (C1), distance (R), moment (C1), S-wave velocity (beta), density (rho), derivative of the input waveform (h) and derivative of the time series (time).
 * 
 * Return             0 on sucess
 *
 */

double displacement_single_force_SH_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double h_derivative[], double time_derivative[] )

{
	
    cout <<  "Running: displacement_single_force_SH_wave\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the SV-wave Displacement for single force using the values of theta, phi,
 *                    distance (R), moment (C1), distance (R), moment (C1), S-wave velocity (beta), density (rho), derivative of the input waveform (h) and derivative of the time series (time).
 *
 * Return             0 on sucess
 *
 */

double displacement_single_force_SV_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double h_derivative[], double time_derivative[] )

{

    cout <<  "Running: displacement_single_force_SV_wave\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the P-wave Displacement for Double Couple using the values of theta, phi,
 *                    distance (R), moment (C1), P-wave velocity (alpha), density (rho), derivative of the input 
 *                    waveform (h) and derivative of the time series (time).
 *
 * Return             0 on sucess
 *
 */

double displacement_double_couple_P_wave (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double h_derivative[], double time_derivative[] )

{

    cout <<  "Running: displacement_double_couple_P_wave\n";
    cout << endl;

    return 0;

}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the SH-wave Displacement for Double Couple using the values of theta, phi,
 *                    distance (R), moment (C1), S-wave velocity (beta), density (rho), derivative of the input 
 *                    waveform (h) and derivative of the time series (time).
 *
 * Return             0 on sucess
 *
 */
 
double displacement_double_couple_SH_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double h_derivative[], double time_derivative[] )

{

    cout <<  "Running: displacement_double_couple_SH_wave\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the SV-wave Displacement for Double Couple using the values of theta, phi,
 *                    distance (R), moment (C1), S-wave velocity (beta), density (rho), derivative of the input 
 *                    waveform (h) and derivative of the time series (time).
 *
 * Return             0 on sucess
 *
 */

double displacement_double_couple_SV_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double h_derivative[], double time_derivative[] )

{

    cout <<  "Running: displacement_double_couple_SV_wave\n";
    cout << endl;

    return 0;

}



/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the P-wave Displacement for Force Dipole using the values of theta, phi,
 *                    distance (R), moment (C1), P-wave velocity (alpha), density (rho), input waveform (h) and time 
 *                    series (time).
 *
 * Return             0 on sucess
 *
 */

double displacement_force_dipole_P_wave (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double h[], double time[] )

{

    cout <<  "Running: displacement_force_dipole_P_wave\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the SH-wave Displacement for Force Dipole using the values of theta, phi,
 *                    distance (R), moment (C1), S-wave velocity, density (rho), input waveform (h) and time series (time). 
 *
 * Return             0 on sucess
 *
 */

double displacement_force_dipole_SH_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double h[], double time[] )

{

    cout <<  "Running: displacement_force_dipole_SH_wave\n";
    cout << endl;

    return 0;

}



/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function calculates the SV-wave Displacement for Force Dipole using the values of theta, phi,
 *                    distance (R), moment (C1), S-wave velocity, density (rho), input waveform (h) and time series (time).
 *
 * Return             0 on sucess
 *
 */

double displacement_force_dipole_SV_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double h[], double time[] )

{

    cout <<  "Running: displacement_force_dipole_SV_wave\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function writes the all the P-wave displacements, input waveform and its derivative and its
 *                    location (x,y) into a file
 *
 * Return             0 on sucess
 *
 */

int write_P_waves_to_file (
    double displacement_point_force_P_wave_output[], double displacement_single_couple_P_wave_output[], 
    double displacement_double_couple_P_wave_output[], double displacement_force_dipole_P_wave_output[], 
    double h[], double h_derivative[], double time[], double time_derivative[], float x, 
    float y, string outputfilename )

{

    cout <<  "Running: write_P_waves_to_file\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function writes the all the SV-wave displacements, input waveform and its derivative and its
 *                    location (x,y) into a file
 *
 * Return             0 on sucess
 *
 */

int write_SV_waves_to_file (
    double displacement_point_force_S_wave_output[], double displacement_single_couple_SV_wave_output[], 
    double displacement_double_couple_SV_wave_output[], double displacement_force_dipole_SV_wave_output[], 
    double h[], double h_derivative[], double time[], double time_derivative[], float x, 
    float y, string outputfilename )
  
{

    cout <<  "Running: write_SV_waves_to_file\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function writes the all the SH-wave displacements, input waveform and its derivative and its
 *                    location (x,y) into a file
 *
 * Return             0 on sucess
 *
 */

int write_SH_waves_to_file (
    double displacement_point_force_S_wave_output[], double displacement_single_couple_SH_wave_output[], 
    double displacement_double_couple_SH_wave_output[], double displacement_force_dipole_SH_wave_output[], 
    double h[], double h_derivative[], double time[], double time_derivative[], float x, 
    float y, string outputfilename )

{

    cout <<  "Running: write_SH_waves_to_file\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates a guassian function using total time and time steps
 *
 * Return             0 on sucess
 *
 */

double gaussian_function (double time[],double time_derivative[])

{

    cout << "Running: gaussian_function\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Eric Jambo
 *
 * Short description: This function calculates the derivative of the input waveform using total time and time steps
 *
 * Return             0 on sucess
 *
 */

double derivative_waveform_function (double time[],double time_derivative[])

{

    cout << "Running: derivative_waveform_function\n";
    cout << endl;

    return 0;

}



/**
 * Author:            Eric Jambo
 *
 * Short description: This function converts the cartesian coordinates into spherical coordinates using location(x,y)
 *
 * Return             0 on sucess
 *
 */

double cartesian_to_spherical_function (double x[],double y[])

{

    cout << "Running: cartesian_to_spherical_function\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates P-wave radiation pattern for single couple force using the values of theta and phi
 *
 * Return             0 on sucess
 *
 */

double radiation_pattern_P_wave_single_couple_force (double theta,double phi)

{

    cout << "Running: radiation_pattern_P_wave_single_couple_force\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates SH-wave radiation pattern for single couple force using the values of theta and phi
 *
 * Return             0 on sucess
 *
 */

double radiation_pattern_SH_wave_single_couple_force (double theta,double phi)

{

    cout << "radiation_pattern_SH_wave_single_couple_force\n";
    cout << endl;

    return 0;

}



/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates SV-wave radiation pattern for single couple force using the values of theta and phi
 *
 * Return             0 on sucess
 *
 */

double radiation_pattern_SV_wave_single_couple_force (double theta,double phi)

{

    cout << "radiation_pattern_SV_wave_single_couple_force\n";
    cout << endl;

    return 0;

}



/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates P-wave radiation pattern for double couple force using the values of theta and phi
 *
 * Return             0 on sucess
 *
 */

double radiation_pattern_P_wave_double_couple_force (double theta,double phi)

{

    cout << "Running: radiation_pattern_P_wave_double_couple_force\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates SH-wave radiation pattern for double couple force using the values of theta and phi
 *
 * Return             0 on sucess
 *
 */

double radiation_pattern_SH_wave_double_couple_force (double theta,double phi)

{

    cout << "radiation_pattern_SH_wave_double_couple_force\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates SV-wave radiation pattern for double couple force using the values of theta and phi
 *
 * Return             0 on sucess
 *
 */

double radiation_pattern_SV_wave_double_couple_force (double theta,double phi)

{

    cout << "Running: radiation_pattern_SV_wave_double_couple_force\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates P-wave radiation pattern for force dipole using the values of theta and phi
 *
 * Return             0 on sucess
 *
 */

double radiation_pattern_P_wave_force_dipole (double theta,double phi)

{

    cout << "Running: radiation_pattern_P_wave_force_dipole\n";
    cout << endl;

    return 0;

}



/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates SH-wave radiation pattern for force dipole using the values of theta and phi
 *
 * Return             0 on sucess
 *
 */

double radiation_pattern_SH_wave_force_dipole (double theta,double phi)

{

    cout << "radiation_pattern_SH_wave_force_dipole\n";
    cout << endl;

    return 0;

}

/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates SV-wave radiation pattern for force dipole using the values of theta and phi
 *
 * Return             0 on sucess
 *
 */

double radiation_pattern_SV_wave_force_dipole (double theta,double phi)

{

    cout << "radiation_pattern_SV_wave_force_dipole\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates P-wave radiation pattern for point force using the values of theta and phi
 *
 * Return             0 on sucess
 *
 */

double radiation_pattern_P_wave_point_force (double theta,double phi)

{

    cout << "radiation_pattern_P_wave_point_force\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates SH-wave radiation pattern for point force using the values of theta and phi
 *
 * Return             0 on sucess
 *
 */

double radiation_pattern_SH_wave_point_force (double theta,double phi)

{

    cout << "radiation_pattern_SH_wave_point_force\n";
    cout << endl;

    return 0;

}


/**
 * Author:            Eric Jambo
 *
 * Short description: This function generates SV-wave radiation pattern for point force using the values of theta and phi
 *
 * Return             0 on sucess
 *
 */

double radiation_pattern_SV_wave_point_force (double theta,double phi)

{

    cout << "radiation_pattern_SV_wave_point_force\n";
    cout << endl;

    return 0;

}
