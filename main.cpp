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
#include <time.h>

#include "displ_calc.h"
#include "write2file.h"
#include "read_in.h"

#include "gaussian.h"
#include "radiation.h"
#include "cart2sph.h"
#include "mesh_gen_o.h"

using namespace std;

// defining the value of PI.
#define PI 3.14159265

/**
 * @short   Main program
 * @file    main.cpp
 * @author  Oluwaseun Fadugba, Yixin Zhang and Eric Jambo
 * @param   parameters.in
 * @return  0 on success
 *
 */

int main(int argc, char* argv[])
{

    clock_t t1 = clock(); //beginning time
  
    // Declare all parameters and files
    int n_x, n_y;
    string model_name, force_type, waveform;
    float alpha, beta, time_step, total_time, area_x, area_y, moment, density;
    
    ifstream infile;
    ofstream logfile, outfile;

    // Check the number of input files, exit program if check failed
    if (check_file_num(argc) != 0)
    {
        exit(EXIT_FAILURE);
    }

    // Reading parameters from infile and convert them to setup types
    read_in_parameters(argc, argv, &model_name, &force_type, &alpha, &beta,
                       &time_step, &total_time, &waveform, &area_x, &area_y,
                       &n_x, &n_y, &moment, &density, infile);
    
    // Check the reasonability of variables
    if (check_variables(&alpha, &beta, &time_step, &total_time, &area_x, &area_y, &n_x, &n_y,
                        &moment, &density) != 0 )
    {
        exit(EXIT_FAILURE);
    }
    
    cout << "Parameters are good to use\n" << endl;
    
    // Open logfile, prepare to write memory in login file.
    logfile.open("login.txt");
        
    out_login(&model_name, &force_type, &alpha, &beta, &time_step, &total_time,
              &waveform, &area_x, &area_y, &n_x, &n_y, &moment, &density, logfile);
        
    logfile.close();
        
    cout << "login file has been written.\n" <<endl;


    // This function gives the x,y coordinates for every point and returns the
    // spherical coordinates for each grid
    // -----------------------------------------------------------------------

    // Output file open
    outfile.open("output.txt");
    float* X = new float[n_x];
    float* Y = new float[n_y];
    
    mesh_gen_o (area_x, area_y, n_x, n_y, X, Y, outfile);
    
    // Output file close
    outfile.close();

    
    // -------------------------------------------------------------------------
    // These parameters (in this bracket) are supposed to be from the input file.
    // I initialize them here to make things work. We will delete them when the
    // everything is working.
    // -------------------------------------------------------------------------
    
    int len = 9;
    
    double *t;	          t        = new double[len];
    
    double *h;	          h        = new double[len];
    double *h_der;        h_der    = new double[len];
    double *t_der;        t_der    = new double[len];
    
    double *displ_P;	  displ_P  = new double[len];
    double *displ_SH;     displ_SH = new double[len];
    double *displ_SV;	  displ_SV = new double[len];

    double *rad_P;	  rad_P  = new double[len];
    double *rad_SH;       rad_SH = new double[len];
    double *rad_SV;	  rad_SV = new double[len];
    
    string outputfilename;
    
    
    // These functions generates a guassian function and its derivative using
    // total time and time steps
    // ------------------------------------------------------------------------
    
    gauss_func (total_time, time_step, 6.0,3.5);
 
    // Output file close
    outfile.close();

    // Now we want to iterate over the grid centers and determine the radiation 
    // pattern and displacement based on the type of force specified
    
    double xx;
    double yy;
    

    // open the file containing the grid centers
    std::ifstream grid_centers("output.txt", std::ios_base::in);
    
    cout <<  "Running: radiation pattern and displacement, and write to file \n";
    cout << endl;

    int tmp = 0;

    while (grid_centers >> xx >> yy)
    {
        tmp += 1;
        //cout << "line number: " << tmp << endl; commented out. Taking too much space.
        //cout << xx << "\t" << yy << "\n";

        if (xx < 0 || xx > area_x || yy < 0 || yy > area_y)
        {
             cout << "Invalid grid centers!" << endl;
             exit(EXIT_FAILURE);
        }      
         
        // This function converts the cartesian coordinates into spherical coordinates
        // using location(x,y)
        // ----------------------------------------------------------------------------------
        
        cart_2_sph (xx, yy, 4.0, 5.6,3.0);
        
        // This function generates P-, SH- and SV-wave radiation patterns for single couple force,
        // double couple, force dipole and point forces using the values of theta and phi.
        // --------------------------------------------------------------------------------------
        
        radp (4.0, 2.9, rad_P, rad_SH, rad_SV, len, force_type);
        
        // Short description: This function calculates the P-, SH- and SH-wave Displacements for
        // single force, double couple, force dipole and point forces using the values of theta,
        // phi, distance (R), moment (C1), S-wave velocity (beta), density (rho), the input
        // waveform (h) and its derivative, and the time series (time) and its derivative.
        // -------------------------------------------------------------------------------------
        
        displ (3.9, 3.5, 2.8, 3.5, 3.7,3.9, 3.5, h, t, h_der, t_der, displ_P, displ_SH, displ_SV,
               len, force_type);
        
        // This function writes the all the P-, SH- and SV-wave displacements, input waveform
        // and its derivative and its location (x,y) into a file.
        // ----------------------------------------------------------------------------------
        
        double rad_P = 9.; double rad_SH = 9.; double rad_SV = 9.;
        
        wr_2_file (displ_P, displ_SH, displ_SV, rad_P, rad_SH, rad_SV, t, xx, xx,
                   "outputfilename.txt", len);
        
    }
    
    cout << "\n"
    "I have completed running all the functions.\n"
    "Good bye.\n"<< endl;
    std::cout << "Execution time : "<<float( clock () - t1 ) / CLOCKS_PER_SEC<< endl;
    cout << endl;
    return 0;

}
