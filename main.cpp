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
#include "prototypes.h"
using namespace std;

int main()

{

    // Print out of program message
	double h[5], time[5];
	double h_derivative[2],time_derivative[5];
	double x[3],y[4];
	double dx[2],dy[4];

	double displacement_point_force_P_wave_output[9], displacement_single_couple_P_wave_output[3],
	       displacement_double_couple_P_wave_output[3], displacement_force_dipole_P_wave_output[3];
	double displacement_point_force_S_wave_output[2], displacement_single_couple_SV_wave_output[3],
	       displacement_double_couple_SV_wave_output[3], displacement_force_dipole_SV_wave_output[3];
	double displacement_single_couple_SH_wave_output[3], displacement_double_couple_SH_wave_output[3],
               displacement_force_dipole_SH_wave_output[3];
        string outputfilename;

        mesh_generator (3.0, 2.0, 0.7, 0.5);
	read_wave_file ();
	displacement_point_force_P_wave (3.9, 3.5, 2.8, 3.5, 3.7, h, time );
	displacement_point_force_S_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h, time);
	displacement_single_force_P_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_derivative, time_derivative );
	displacement_single_force_SH_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_derivative, time_derivative );
	displacement_single_force_SV_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_derivative, time_derivative );
	displacement_double_couple_P_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_derivative, time_derivative );
	displacement_double_couple_SH_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_derivative, time_derivative );
	displacement_double_couple_SV_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h_derivative, time_derivative );
	displacement_force_dipole_P_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h, time );
	displacement_force_dipole_SH_wave (3.7, 2.9, 3.5, 2.8, 3.5, 3.7, h, time );
	displacement_force_dipole_SV_wave (3.0, 2.0, 5.9, 2.8, 2.5, 4, h, time );

        write_P_waves_to_file (
	    displacement_point_force_P_wave_output, displacement_single_couple_P_wave_output,
	    displacement_double_couple_P_wave_output, displacement_force_dipole_P_wave_output, h,
	    h_derivative, time, time_derivative, x, y, outputfilename );
	write_SV_waves_to_file (
	    displacement_point_force_S_wave_output, displacement_single_couple_SV_wave_output,
	    displacement_double_couple_SV_wave_output,displacement_force_dipole_SV_wave_output,h,
	    h_derivative,  time, time_derivative,  x, y, outputfilename );
	write_SH_waves_to_file (
	    displacement_point_force_S_wave_output, displacement_single_couple_SH_wave_output,
	    displacement_double_couple_SH_wave_output, displacement_force_dipole_SH_wave_output, h,
	    h_derivative,  time, time_derivative,  x, y, outputfilename );

	gaussian_function (time, time_derivative);
	derivative_waveform_function (time, time_derivative);
	cartesian_to_spherical_function (x, y);
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
    cout << "\n"
            "I have completed running all the prototypes,\n";
	    "Goodbye.";
    cout << endl;
}
