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


#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
int read_string(string str[], int i, string variable_name,
                string &variable_value, ofstream &file);
int read_float(string str[], int i, string variable_name,
               float &variable_value, ofstream &file);

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

int main() 

{
//  Read in variables and write them into memory, login file, and print them to the screen
    string str[100];
    string s, variable_name, string_value;
    string model_name, force_type, wave_type,waveform;
    float velocity, time_step, total_time, area_x, area_y, 
        grid_x, grid_y, moment;
    int i;
    
    if(argc < 2)
    { 
           cout << "Missing inputfile, please check\n";
           return EXIT_FAILURE;
     }
    
//  open the input file and read the parameters in string format    
    ifstream infile;
    infile.open(argv[1]);

    i = 0;
    while( infile >> s )
    { 
         str[i] = s;
         i++;
     }
    
    infile.close();

//    if ( !inputfile.is_open() ) 
//{
//    cout << "Cannot open the input file.\nThe file " 
//             << inputfilename << " is not located in the working directory. "
//             << endl;

//    return 1;  
//}

//  Open the log file, and wtite variable values into login file
    ofstream logfile;
    logfile.open("login.txt");
    string line;
      
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
            read_string(str, i, variable_name, string_value, logfile);
        
        
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
    
    return 0;
}


/**
 * @short    read_string
 * @file     Mainfile_text.cpp
 * @author   Yixin Zhang
 * @param    string variable_name, string &variable_value, float &variable_value
 * @display  displays the content of login file when running
 * @return   0 on sucess
 *
 * This function gives the string/float virable values to each viriable, display them and write them into loginfile 
 * latest created: February 27, 2017
 */

int read_string(string str[], int i, string variable_name,
                string &variable_value, ofstream &file)
{
    variable_name = str[i];
    file << variable_name << "=\t" << endl;
    cout << variable_name << "=\t" << endl;
    
    variable_value = str[i+1];
    file << variable_value << endl << "\n";
    cout << variable_value << endl << "\n";
    
    return 0;
}

int read_float(string str[], int i, string variable_name,
                float &variable_value, ofstream &file)
{
    char* c;
    
    variable_name = str[i];
    file << variable_name << "=\t" << endl;
    cout << variable_name << "=\t" << endl;
    
    c = const_cast<char*>(str[i+1].c_str());
    sscanf(c,"%e", &variable_value);
    file << variable_value << endl << "\n";
    cout << variable_value << endl << "\n";
    
    return 0;
}


/**
 * @short    Mesh_generator
 * @file     Mainfile_text.cpp
 * @author   Yixin Zhang
 * @param    double x, double y, double dx, double dy
 * @display  displays "Running: mesh_generator" when running
 * @return   0 on sucess
 *
 * This function gives the x,y coordinates for every point and returns the spherical coordinates for each grid
 * First created: February 14, 2017
 */

double mesh_generator (double x, double y, double dx, double dy)
{

    cout <<  "Running: mesh_generator\n";
    cout << endl;
  
    return 0;

}


/**
 * @short    read_wave_file
 * @file     Mainfile_text.cpp
 * @author   Yixin Zhang
 * @param    none
 * @display  displays "Running: read_wave_file" when running
 * @return   0 on sucess
 *
 * This function read the input waveforms in the program
 *
 * First created: February 14, 2017
 */

int read_wave_file ()
{
  
    cout << "Running: read_wave_file\n";
    cout << endl;
  
    return 0;
  
}



/**
 * @short    displacement_point_force_P_wave
 * @file     Mainfile_text.cpp
 * @author   Oluwaseun Fadugba
 * @param    double theta, double R, double moment, double alpha, double rho, double h[], double time[] 
 * @display  displays "Running: displacement_point_force_P_wave" when running
 * @return   0 on sucess
 *
 * This function calculates the P-wave Displacement for single force using the values of theta, phi, 
 * distance (R), moment (C1), P-wave velocity (alpha), density (rho), the input waveform (h) and the 
 * time series (time).
 *
 * First created: February 14, 2017
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
 * @short    displacement_point_force_S_wave
 * @file     Mainfile_text.cpp
 * @author   Oluwaseun Fadugba
 * @param    double theta, double phi, double R, double moment, double beta, double rho, double h[], double time[] 
 * @display  displays "Running: displacement_point_force_S_wave" when running
 * @return   0 on sucess
 *
 * This function calculates the S-wave Displacement for single force using the values of theta, phi,
 * distance (R), moment (C1), S-wave velocity (beta), density (rho), the input waveform (h) and the 
 * time series (time).
 *
 * First created: February 14, 2017
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
 * @short    displacement_single_force_P_wave
 * @file     Mainfile_text.cpp
 * @author   Oluwaseun Fadugba
 * @param    double theta, double phi, double R, double moment, double alpha, double rho, double h_derivative[], double time_derivative[]
 * @display  "Running: displacement_single_force_P_wave"
 * @return   0 on sucess
 *
 * This function calculates the P-wave Displacement for single force using the values of theta, phi,
 * distance (R), moment (C1), P-wave velocity (alpha), density (rho), derivative of the input 
 * waveform (h) and derivative of the time series (time). 
 *
 * First created: February 14, 2017
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
 * @short    displacement_single_force_SH_wave
 * @file     Mainfile_text.cpp
 * @author   Oluwaseun Fadugba
 * @param    double theta, double phi, double R, double moment, double beta, double rho, double h_derivative[], double time_derivative[]
 * @display  "Running: displacement_single_force_SH_wave"
 * @return   0 on sucess
 *
 * This function calculates the SH-wave Displacement for single force using the values of theta, 
 * phi, distance (R), moment (C1), S-wave velocity (beta), density (rho), derivative of the input 
 * waveform (h) and derivative of the time series (time). 
 *
 * First created: February 14, 2017
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
 * @short    displacement_single_force_SV_wave
 * @file     Mainfile_text.cpp
 * @author   Oluwaseun Fadugba
 * @param    double theta, double phi, double R, double moment, double beta, double rho, double h_derivative[], double time_derivative[]
 * @display  "Running: displacement_single_force_SV_wave"
 * @return   0 on sucess
 *
 * This function calculates the SV-wave Displacement for single force using the values of theta, phi,
 * distance (R), moment (C1), S-wave velocity (beta), density (rho), derivative of the input 
 * waveform (h) and derivative of the time series (time).
 *
 * First created: February 14, 2017
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
 * @short    displacement_double_couple_P_wave
 * @file     Mainfile_text.cpp
 * @author   Oluwaseun Fadugba
 * @param    double theta, double phi, double R, double moment, double alpha, double rho, double h_derivative[], double time_derivative[]
 * @display  "Running: displacement_double_couple_P_wave"
 * @return   0 on sucess
 *
 * This function calculates the P-wave Displacement for Double Couple using the values of theta, phi,
 * distance (R), moment (C1), P-wave velocity (alpha), density (rho), derivative of the input 
 * waveform (h) and derivative of the time series (time).
 *
 * First created: February 14, 2017
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
 * @short    displacement_double_couple_SH_wave
 * @file     Mainfile_text.cpp
 * @author   Oluwaseun Fadugba
 * @param    double theta, double phi, double R, double moment, double beta, double rho, double h_derivative[], double time_derivative[]
 * @display  "Running: displacement_double_couple_SH_wave"
 * @return   0 on sucess
 *
 * This function calculates the SH-wave Displacement for Double Couple using the values of theta, phi,
 * distance (R), moment (C1), S-wave velocity (beta), density (rho), derivative of the input 
 * waveform (h) and derivative of the time series (time).
 *
 * First created: February 14, 2017
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
 * @short    displacement_double_couple_SV_wave
 * @file     Mainfile_text.cpp
 * @author   Oluwaseun Fadugba
 * @param    double theta, double phi, double R, double moment, double beta, double rho, double h_derivative[], double time_derivative[]
 * @display  "Running: displacement_double_couple_SV_wave"
 * @return   0 on sucess
 *
 * This function calculates the SV-wave Displacement for Double Couple using the values of theta, phi,
 * distance (R), moment (C1), S-wave velocity (beta), density (rho), derivative of the input 
 * waveform (h) and derivative of the time series (time).
 *
 * First created: February 14, 2017
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
 * @short    displacement_force_dipole_P_wave
 * @file     Mainfile_text.cpp
 * @author   Oluwaseun Fadugba
 * @param    double theta, double phi, double R, double moment, double alpha, double rho, double h[], double time[]
 * @display  "Running: displacement_force_dipole_P_wave"
 * @return   0 on sucess
 *
 * This function calculates the P-wave Displacement for Force Dipole using the values of theta, phi,
 * distance (R), moment (C1), P-wave velocity (alpha), density (rho), input waveform (h) and time 
 * series (time).
 *
 * First created: February 14, 2017
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
 * @short    displacement_force_dipole_SH_wave
 * @file     Mainfile_text.cpp
 * @author   Oluwaseun Fadugba
 * @param    double theta, double phi, double R, double moment, double beta, double rho, double h[], double time[]
 * @display  "Running: displacement_force_dipole_SH_wave"
 * @return   0 on sucess
 *
 * This function calculates the SH-wave Displacement for Force Dipole using the values of theta, phi,
 * distance (R), moment (C1), S-wave velocity, density (rho), input waveform (h) and time series (time).
 *
 * First created: February 14, 2017
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
 * @short    displacement_force_dipole_SV_wave
 * @file     Mainfile_text.cpp
 * @author   Oluwaseun Fadugba
 * @param    double theta, double phi, double R, double moment, double beta, double rho, double h[], double time[]
 * @display  "Running: displacement_force_dipole_SV_wave"
 * @return   0 on sucess
 *
 * This function calculates the SV-wave Displacement for Force Dipole using the values of theta, phi,
 * distance (R), moment (C1), S-wave velocity, density (rho), input waveform (h) and time series (time).
 *
 * First created: February 14, 2017
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
 * @short    write_P_waves_to_file
 * @file     Mainfile_text.cpp
 * @author   Oluwaseun Fadugba
 * @param    double displacement_point_force_P_wave[], double displacement_single_couple_P_wave[], 
 *           double displacement_double_couple_P_wave[], double displacement_force_dipole_P_wave[], 
 *           double h[], double h_derivative[], double time[], double time_derivative[], double x[], 
 *           double y[], string outputfilename
 * @display  "Running: write_P_waves_to_file"
 * @return   0 on sucess
 *
 * This function writes the all the P-wave displacements, input waveform and its derivative and its
 * location (x,y) into a file
 *
 * First created: February 14, 2017
 */

int write_P_waves_to_file (
    double displacement_point_force_P_wave[], double displacement_single_couple_P_wave[], 
    double displacement_double_couple_P_wave[], double displacement_force_dipole_P_wave[], 
    double h[], double h_derivative[], double time[], double time_derivative[], double x[], 
    double y[], string outputfilename )

{

    cout <<  "Running: write_P_waves_to_file\n";
    cout << endl;

    return 0;

}



/**
 * @short    write_SV_waves_to_file
 * @file     Mainfile_text.cpp
 * @author   Oluwaseun Fadugba
 * @param    double displacement_point_force_S_wave[], double displacement_single_couple_SV_wave[], 
 *           double displacement_double_couple_SV_wave[], double displacement_force_dipole_SV_wave[], 
 *           double h[], double h_derivative[], double time[], double time_derivative[], double x[], 
 *           double y[], string outputfilename
 * @display  "Running: write_SV_waves_to_file"
 * @return   0 on sucess
 *
 * This function writes the all the SV-wave displacements, input waveform and its derivative and its
 * location (x,y) into a file
 *
 * First created: February 14, 2017
 */

int write_SV_waves_to_file (
    double displacement_point_force_S_wave[], double displacement_single_couple_SV_wave[], 
    double displacement_double_couple_SV_wave[], double displacement_force_dipole_SV_wave[], 
    double h[], double h_derivative[], double time[], double time_derivative[], double x[], 
    double y[], string outputfilename )
  
{

    cout <<  "Running: write_SV_waves_to_file\n";
    cout << endl;

    return 0;

}



/**
 * @short    write_SH_waves_to_file
 * @file     Mainfile_text.cpp
 * @author   Oluwaseun Fadugba
 * @param    double displacement_point_force_S_wave[], double displacement_single_couple_SH_wave[], 
 *           double displacement_double_couple_SH_wave[], double displacement_force_dipole_SH_wave[], 
 *           double h[], double h_derivative[], double time[], double time_derivative[], double x[], 
 *           double y[], string outputfilename
 * @display  "Running: write_SH_waves_to_file"
 * @return   0 on sucess
 *
 * This function writes the all the SH-wave displacements, input waveform and its derivative and its
 * location (x,y) into a file
 *
 * First created: February 14, 2017
 */

int write_SH_waves_to_file (
    double displacement_point_force_S_wave[], double displacement_single_couple_SH_wave[], 
    double displacement_double_couple_SH_wave[], double displacement_force_dipole_SH_wave[], 
    double h[], double h_derivative[], double time[], double time_derivative[], double x[], 
    double y[], string outputfilename )

{

    cout <<  "Running: write_SH_waves_to_file\n";
    cout << endl;

    return 0;

}



/**
 * @short    Gaussian function
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double time[], double time_derivative[]
 * @display  "Running: gaussian_function"
 * @return   0 on sucess
 *
 * This function generates a guassian function using total time and time steps
 *
 * First created: February 14, 2017
 */

double gaussian_function (double time[],double time_derivative[])

{

    cout << "Running: gaussian_function\n";
    cout << endl;

    return 0;

}



/**
 * @short    derivative_waveform_function
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double time[], double time_derivative[]
 * @display  "Running: derivative_waveform_function"
 * @return   0 on sucess
 *
 * This function calculates the derivative of the input waveform using total time and time steps
 *
 * First created: February 14, 2017
 */

double derivative_waveform_function (double time[],double time_derivative[])

{

    cout << "Running: derivative_waveform_function\n";
    cout << endl;

    return 0;

}




/**
 * @short    cartesian_to_spherical_function
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double x[],double y[]
 * @display  "Running: derivative_waveform_function"
 * @return   0 on sucess
 *
 * This function converts the cartesian coordinates into spherical coordinates using location(x,y)
 *
 * First created: February 14, 2017
 */

double cartesian_to_spherical_function (double x[],double y[])

{

    cout << "Running: cartesian_to_spherical_function\n";
    cout << endl;

    return 0;

}




/**
 * @short    spherical_to_cartesian_function
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double theta,double phi,double R
 * @display  "Running: spherical_to_cartesian_function"
 * @return   0 on sucess
 *
 * This function converts the spherical coordinates into cartesian coordinates using the values of theta,phi and distance (R)
 *
 * First created: February 14, 2017
 */

double spherical_to_cartesian_function (double theta,double phi,double R)

{

    cout << "Running: spherical_to_cartesian_function\n";
    cout << endl;

    return 0;

}


/**
 * @short    Radiation_pattern_P_wave_single_couple_force
 * @file     Mainfile_text.cpp
 * @authr    Eric Jambo
 * @param    double theta,double phi
 * @display  "Running: radiation_pattern_P_wave_single_couple_force"
 * @return   0 on sucess
 *
 * This function generates P-wave radiation pattern for single couple force using the values of theta and phi
 *
 * First created: February 14, 2017
 */

double radiation_pattern_P_wave_single_couple_force (double theta,double phi)

{

    cout << "Running: radiation_pattern_P_wave_single_couple_force\n";
    cout << endl;

    return 0;

}



/**
 * @short    Radiation_pattern_SH_wave_single_couple_force
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double theta,double phi
 * @display  "Running: radiation_pattern_SH_wave_single_couple_force"
 * @return   0 on sucess
 *
 * This function generates SH-wave radiation pattern for single couple force using the values of theta and phi
 *
 * First created: February 14, 2017
 */

double radiation_pattern_SH_wave_single_couple_force (double theta,double phi)

{

    cout << "radiation_pattern_SH_wave_single_couple_force\n";
    cout << endl;

    return 0;

}




/**
 * @short    Radiation_pattern_SV_wave_single_couple_force
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double theta,double phi
 * @display  "Running: radiation_pattern_SV_wave_single_couple_force"
 * @return   0 on sucess
 *
 * This function generates SV-wave radiation pattern for single couple force using the values of theta and phi
 *
 * First created: February 14, 2017
 */

double radiation_pattern_SV_wave_single_couple_force (double theta,double phi)

{

    cout << "radiation_pattern_SV_wave_single_couple_force\n";
    cout << endl;

    return 0;

}




/**
 * @short    Radiation_pattern_P_wave_double_couple_force
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double theta,double phi
 * @display  "Running: radiation_pattern_SV_wave_double_couple_force"
 * @return   0 on sucess
 *
 * This function generates P-wave radiation pattern for double couple force using the values of theta and phi
 *
 * First created: February 14, 2017
 */

double radiation_pattern_P_wave_double_couple_force (double theta,double phi)

{

    cout << "Running: radiation_pattern_SV_wave_double_couple_force\n";
    cout << endl;

    return 0;

}



/**
 * @short    Radiation_pattern_SH_wave_single_couple_force
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double theta,double phi
 * @display  "Running: radiation_pattern_SH_wave_double_couple_force"
 * @return   0 on sucess
 *
 * This function generates SH-wave radiation pattern for double couple force using the values of theta and phi
 *
 * First created: February 14, 2017
 */

double radiation_pattern_SH_wave_double_couple_force (double theta,double phi)

{

    cout << "radiation_pattern_SH_wave_double_couple_force\n";
    cout << endl;

    return 0;

}



/**
 * @short    Radiation_pattern_SV_wave_double_couple_force
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double theta,double phi
 * @display  "Running: radiation_pattern_SV_wave_double_couple_force"
 * @return   0 on sucess
 *
 * This function generates SV-wave radiation pattern for double couple force using the values of theta and phi
 *
 * First created: February 14, 2017
 */

double radiation_pattern_SV_wave_double_couple_force (double theta,double phi)

{

    cout << "Running: radiation_pattern_SV_wave_double_couple_force\n";
    cout << endl;

    return 0;

}




/**
 * @short    Radiation_pattern_P_wave_force_dipole
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double theta,double phi
 * @display  "Running: radiation_pattern_P_wave_force_dipole"
 * @return   0 on sucess
 *
 * This function generates P-wave radiation pattern for force dipole using the values of theta and phi
 *
 * First created: February 14, 2017
 */

double radiation_pattern_P_wave_force_dipole (double theta,double phi)

{

    cout << "Running: radiation_pattern_P_wave_force_dipole\n";
    cout << endl;

    return 0;

}



/**
 * @short    Radiation_pattern_SH_wave_force_dipole
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double theta,double phi
 * @display  "Running: radiation_pattern_SH_wave_force_dipole"
 * @return   0 on sucess
 *
 * This function generates SH-wave radiation pattern for force dipole using the values of theta and phi
 *
 * First created: February 14, 2017
 */

double radiation_pattern_SH_wave_force_dipole (double theta,double phi)

{

    cout << "radiation_pattern_SH_wave_force_dipole\n";
    cout << endl;

    return 0;

}



/**
 * @short    Radiation_pattern_SV_wave_force_dipole
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double theta,double phi
 * @display  "Running: radiation_pattern_SV_wave_force_dipole"
 * @return   0 on sucess
 *
 * This function generates SV-wave radiation pattern for force dipole using the values of theta and phi
 *
 * First created: February 14, 2017
 */

double radiation_pattern_SV_wave_force_dipole (double theta,double phi)

{

    cout << "radiation_pattern_SV_wave_force_dipole\n";
    cout << endl;

    return 0;

}



/**
 * @short    Radiation_pattern_P_wave_point_force
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double theta,double phi
 * @display  "Running: radiation_pattern_P_wave_point_force"
 * @return   0 on sucess
 *
 * This function generates P-wave radiation pattern for point force using the values of theta and phi
 *
 * First created: February 14, 2017
 */

double radiation_pattern_P_wave_point_force (double theta,double phi)

{

    cout << "radiation_pattern_P_wave_point_force\n";
    cout << endl;

    return 0;

}



/**
 * @short    Radiation_pattern_SH_wave_point_force
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double theta,double phi
 * @display  "Running: radiation_pattern_SH_wave_point_force"
 * @return   0 on sucess
 *
 * This function generates SH-wave radiation pattern for point force using the values of theta and phi
 *
 * First created: February 14, 2017
 */

double radiation_pattern_SH_wave_point_force (double theta,double phi)

{

    cout << "radiation_pattern_SH_wave_point_force\n";
    cout << endl;

    return 0;

}



/**
 * @short    Radiation_pattern_SV_wave_point_force
 * @file     Mainfile_text.cpp
 * @author   Eric Jambo
 * @param    double theta,double phi
 * @display  "Running: radiation_pattern_SV_wave_point_force"
 * @return   0 on sucess
 *
 * This function generates SV-wave radiation pattern for point force using the values of theta and phi
 *
 * First created: February 14, 2017
 */

double radiation_pattern_SV_wave_point_force (double theta,double phi)

{

    cout << "radiation_pattern_SV_wave_point_force\n";
    cout << endl;

    return 0;

}






