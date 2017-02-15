
/*
 * Initial main file example
 * by Yixin Zhang
 */


#include <string>
#include <iostream>
#include <fstream>


using namespace std;

int main()
{

  // Print out of program message

  cout << "\n"
          "Hello,\n"
          "I am your first test program\n";
  cout << endl;

  return 0;

}



/*
 * read input file
 * by Yixin Zhang
 * February 14, 2017
 * 
 * This function read variables on input file into program
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int read_input_file ()
{
  
  //load the text file and assign them into variables:
  
  std::ifstream in("input.txt");
  std::stringstream buffer;
  buffer << in.rdbuf();
  std::string input = buffer.str();
  std::cout << input << std::endl << std::endl;
  
  return 0;

}

/*
 * generate the mesh for calculating the value of every grid
 * by Yixin Zhang
 * February 14, 2017
 * 
 * This function gives the x,y coordinates for every point and returns the spherical coordinates for each grid
 */

double mesh_generator (double x, double y, double dx, double dy)
{

  cout <<  "Running: mesh_generator\n";
  cout << endl;
  
  return 0;

}


/*
 * generate the mesh for calculating the value of every grid
 * by Yixin Zhang
 * February 14, 2017
 * 
 * This function read the input waveforms in the program
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int read_wave_file ()
{
  
  cout << "Running: read_wave_file\n";
  cout << endl;
  
  return 0;
  
}






 /*
  * displacement_point_force_P_wave
  * by Oluwaseun Fadugba
  * February 14, 2017
  *
  * This function calculates the P-wave Displacement for single force using the values of theta, phi, 
  * distance (R), moment (C1), P-wave velocity (alpha), density (rho), the input waveform (h) and the 
  * time series (time).
  */

  double displacement_point_force_P_wave (
    double theta, double R, double moment, double alpha, 
    double rho, double h[], double time[] )
  {

    cout <<  "Running: displacement_point_force_P_wave\n";
    cout << endl;

    return 0;

  }



 /*
  * displacement_point_force_S_wave
  * by Oluwaseun Fadugba
  * February 14, 2017 
  *
  * This function calculates the S-wave Displacement for single force using the values of theta, phi,
  * distance (R), moment (C1), S-wave velocity (beta), density (rho), the input waveform (h) and the 
  * time series (time).
  */

  double displacement_point_force_S_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double h[], double time[] )
  {

    cout <<  "Running: displacement_point_force_S_wave\n";
    cout << endl;

    return 0;

  }


 /*
  * displacement_single_force_P_wave
  * by Oluwaseun Fadugba
  * February 14, 2017 
  *
  * This function calculates the P-wave Displacement for single force using the values of theta, phi,
  * distance (R), moment (C1), P-wave velocity (alpha), density (rho), derivative of the input 
  * waveform (h) and derivative of the time series (time).
  */

  double displacement_single_force_P_wave (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double h_derivative[], double time_derivative[] )
  {

    cout <<  "Running: displacement_single_force_P_wave\n";
    cout << endl;

    return 0;

  }


 /*
  * displacement_single_force_SH_wave
  * by Oluwaseun Fadugba
  * February 14, 2017
  * 
  * This function calculates the SH-wave Displacement for single force using the values of theta, 
  * phi, distance (R), moment (C1), S-wave velocity (beta), density (rho), derivative of the input 
  * waveform (h) and derivative of the time series (time).
  */

  double displacement_single_force_SH_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double h_derivative[], double time_derivative[] )
  {

    cout <<  "Running: displacement_single_force_SH_wave\n";
    cout << endl;

    return 0;

  }



 /*
  * displacement_single_force_SV_wave
  * by Oluwaseun Fadugba
  * February 14, 2017 
  *
  * This function calculates the SV-wave Displacement for single force using the values of theta, phi,
  * distance (R), moment (C1), S-wave velocity (beta), density (rho), derivative of the input 
  * waveform (h) and derivative of the time series (time).
  */

  double displacement_single_force_SV_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double h_derivative[], double time_derivative[] )
  {

    cout <<  "Running: displacement_single_force_SV_wave\n";
    cout << endl;

    return 0;

  }




 /*
  * displacement_double_couple_P_wave
  * by Oluwaseun Fadugba
  * February 14, 2017 
  *
  * This function calculates the P-wave Displacement for Double Couple using the values of theta, phi,
  * distance (R), moment (C1), P-wave velocity (alpha), density (rho), derivative of the input 
  * waveform (h) and derivative of the time series (time).
  */

  double displacement_double_couple_P_wave (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double h_derivative[], double time_derivative[] )
  {

    cout <<  "Running: displacement_double_couple_P_wave\n";
    cout << endl;

    return 0;

  }


 /*
  * displacement_double_couple_SH_wave
  * by Oluwaseun Fadugba
  * February 14, 2017
  *
  * This function calculates the SH-wave Displacement for Double Couple using the values of theta, phi,
  * distance (R), moment (C1), S-wave velocity (beta), density (rho), derivative of the input 
  * waveform (h) and derivative of the time series (time).
  */

  double displacement_double_couple_SH_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double h_derivative[], double time_derivative[] )
  {

    cout <<  "Running: displacement_double_couple_SH_wave\n";
    cout << endl;

    return 0;

  }



 /*
  * displacement_double_couple_SV_wave
  * by Oluwaseun Fadugba
  * February 14, 2017
  *
  * This function calculates the SV-wave Displacement for Double Couple using the values of theta, phi,
  * distance (R), moment (C1), S-wave velocity (beta), density (rho), derivative of the input 
  * waveform (h) and derivative of the time series (time).
  */

  double displacement_double_couple_SV_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double h_derivative[], double time_derivative[] )
  {

    cout <<  "Running: displacement_double_couple_SV_wave\n";
    cout << endl;

    return 0;

  }



 /*
  * displacement_force_dipole_P_wave
  * by Oluwaseun Fadugba
  * February 14, 2017
  *
  * This function calculates the P-wave Displacement for Force Dipole using the values of theta, phi,
  * distance (R), moment (C1), P-wave velocity (alpha), density (rho), input waveform (h) and time 
  * series (time).
  */

  double displacement_force_dipole_P_wave (
    double theta, double phi, double R, double moment, double alpha, 
    double rho, double h[], double time[] )
  {

    cout <<  "Running: displacement_force_dipole_P_wave\n";
    cout << endl;

    return 0;

  }


 /*
  * displacement_force_dipole_SH_wave
  * by Oluwaseun Fadugba
  * February 14, 2017
  *
  * This function calculates the SH-wave Displacement for Force Dipole using the values of theta, phi,
  * distance (R), moment (C1), S-wave velocity, density (rho), input waveform (h) and time series (time).
  */

  double displacement_force_dipole_SH_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double h[], double time[] )
  {

    cout <<  "Running: displacement_force_dipole_SH_wave\n";
    cout << endl;

    return 0;

  }


 /*
  * displacement_force_dipole_SV_wave
  * by Oluwaseun Fadugba
  * February 14, 2017
  *
  * This function calculates the SV-wave Displacement for Force Dipole using the values of theta, phi,
  * distance (R), moment (C1), S-wave velocity, density (rho), input waveform (h) and time series (time).
  */

  double displacement_force_dipole_SV_wave (
    double theta, double phi, double R, double moment, double beta, 
    double rho, double h[], double time[] )
  {

    cout <<  "Running: displacement_force_dipole_SV_wave\n";
    cout << endl;

    return 0;

  }


 /*
  * write_P_waves_to_file
  * by Oluwaseun Fadugba
  * February 14, 2017
  *
  * This function writes the all the P-wave displacements, input waveform and its derivative and its
  * location (x,y) into a file
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



 /*
  * write_SV_waves_to_file
  * by Oluwaseun Fadugba
  * February 14, 2017
  *
  * This function writes the all the SV-wave displacements, input waveform and its derivative 
  * and its location (x,y) into a file
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


 /*
  * write_SH_waves_to_file
  * by Oluwaseun Fadugba
  * February 14, 2017
  *
  * This function writes the all the SH-wave displacements, input waveform and its derivative and its
  * location (x,y) into a file
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


/*
 *Gaussian function
 *by Eric Jambo
 *February 14,2017
 *This function generates a guassian function using total time and time steps
 */

double gaussian_function (double time[],double time_derivative[])
{

cout << "Running:gaussian_function\n";
cout << endl;

return 0;

}


/*
 *derivative_waveform_function
 *by Eric Jambo
 *February 14,2017
 *This function calculates the derivative of the input waveform using total time and time steps
 */

double derivative_waveform_function (double time[],double time_derivative[])
{

cout << "derivative_waveform_function\n";
cout << endl;

return 0;

}


/*
 *cartesian_to_spherical_function
 *by Eric Jambo
 *February 14,2017
 *This function converts the cartesian coordinates into spherical coordinates using location(x,y)
 */

double cartesian_to_spherical_function (double x[],double y[])
{

cout << "cartesian_to_spherical_function\n";
cout << endl;

return 0;

}


/*
 *spherical_to_cartesian_function
 *by Eric Jambo
 *February 14,2017
 *This function converts the spherical coordinates into cartesian coordinates using the values of theta,phi and distance (R)
 */

double spherical_to_cartesian_function (double theta,double phi,double R)
{

cout << "spherical_to_cartesian_function\n";
cout << endl;

return 0;

}



/*
 *Radiation_pattern_P_wave_single_couple_force
 *by Eric Jambo
 *February 14,2017
 *This function generates P-wave radiation pattern for single couple force using the values of theta and phi
 */

double radiation_pattern_P_wave_single_couple_force (double theta,double phi)
{

cout << "radiation_pattern_P_wave_single_couple_force\n";
cout << endl;

return 0;

}


/*
 *Radiation_pattern_SH_wave_single_couple_force
 *by Eric Jambo
 *February 14,2017
 *This function generates SH-wave radiation pattern for single couple force using the values of theta and phi
 */

double radiation_pattern_SH_wave_single_couple_force (double theta,double phi)
{

cout << "radiation_pattern_SH_wave_single_couple_force\n";
cout << endl;

return 0;

}


/*
 *Radiation_pattern_SV_wave_single_couple_force
 *by Eric Jambo
 *February 14,2017
 *This function generates SV-wave radiation pattern for single couple force using the values of theta and phi
 */

double radiation_pattern_SV_wave_single_couple_force (double theta,double phi)
{

cout << "radiation_pattern_SV_wave_single_couple_force\n";
cout << endl;

return 0;

}


/*
 *Radiation_pattern_P_wave_double_couple_force
 *by Eric Jambo
 *February 14,2017
 *This function generates P-wave radiation pattern for double couple force using the values of theta and phi
 */

double radiation_pattern_P_wave_double_couple_force (double theta,double phi)
{

cout << "radiation_pattern_SV_wave_double_couple_force\n";
cout << endl;

return 0;

}


/*
 *Radiation_pattern_SH_wave_single_couple_force
 *by Eric Jambo
 *February 14,2017
 *This function generates SH-wave radiation pattern for double couple force using the values of theta and phi
 */

double radiation_pattern_SH_wave_double_couple_force (double theta,double phi)
{

cout << "radiation_pattern_SH_wave_double_couple_force\n";
cout << endl;

return 0;

}


/*
 *Radiation_pattern_SV_wave_double_couple_force
 *by Eric Jambo
 *February 14,2017
 *This function generates SV-wave radiation pattern for double couple force using the values of theta and phi
 */

double radiation_pattern_SV_wave_double_couple_force (double theta,double phi)
{

cout << "radiation_pattern_SV_wave_double_couple_force\n";
cout << endl;

return 0;

}


/*
 *Radiation_pattern_P_wave_force_dipole
 *by Eric Jambo
 *February 14,2017
 *This function generates P-wave radiation pattern for force dipole using the values of theta and phi
 */

double radiation_pattern_P_wave_force_dipole (double theta,double phi)
{

cout << "radiation_pattern_P_wave_force_dipole\n";
cout << endl;

return 0;

}


/*
 *Radiation_pattern_SH_wave_force_dipole
 *by Eric Jambo
 *February 14,2017
 *This function generates SH-wave radiation pattern for force dipole using the values of theta and phi
 */

double radiation_pattern_SH_wave_force_dipole (double theta,double phi)
{

cout << "radiation_pattern_SH_wave_force_dipole\n";
cout << endl;

return 0;

}

/*
 *Radiation_pattern_SV_wave_force_dipole
 *by Eric Jambo
 *February 14,2017
 *This function generates SV-wave radiation pattern for force dipole using the values of theta and phi
 */

double radiation_pattern_SV_wave_force_dipole (double theta,double phi)
{

cout << "radiation_pattern_SV_wave_force_dipole\n";
cout << endl;

return 0;

}


/*
 *Radiation_pattern_P_wave_point_force
 *by Eric Jambo
 *February 14,2017
 *This function generates P-wave radiation pattern for point force using the values of theta and phi
 */

double radiation_pattern_P_wave_point_force (double theta,double phi)
{

cout << "radiation_pattern_P_wave_point_force\n";
cout << endl;

return 0;

}


/*
 *Radiation_pattern_SH_wave_point_force
 *by Eric Jambo
 *February 14,2017
 *This function generates SH-wave radiation pattern for point force using the values of theta and phi
 */

double radiation_pattern_SH_wave_point_force (double theta,double phi)
{

cout << "radiation_pattern_SH_wave_point_force\n";
cout << endl;

return 0;

}


/*
 *Radiation_pattern_SV_wave_point_force
 *by Eric Jambo
 *February 14,2017
 *This function generates SV-wave radiation pattern for point force using the values of theta and phi
 */

double radiation_pattern_SV_wave_point_force (double theta,double phi)
{

cout << "radiation_pattern_SV_wave_point_force\n";
cout << endl;

return 0;

}






