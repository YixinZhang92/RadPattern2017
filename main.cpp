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
#include <mpi.h>

#include "init_time.h"
#include "struct.h"
#include "read_in.h"
#include "error_check.h"
#include "compute_displ.h"
#include "write2file.h"
#include "gaussian.h"
#include "radiation.h"
#include "cart2sph.h"

using namespace std;

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
  
    int rank;
    int size;

    // Initialize an MPI process
    // Passing the arguments of the main program
    MPI_Init(&argc, &argv);

    // Captures the rank (i.e., the processor ID)
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Captures the total number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 4 ) 
    {
        cout << "\nQuitting. Number of MPI tasks must be 4.\n\n";
        MPI_Abort(MPI_COMM_WORLD, 0);
        exit(EXIT_FAILURE);
    };

    if ( rank == 0 ) 
    {
        cout << "Welcome to Radiation Pattern parallel program!\n";
        cout << endl;      
    }; 

    // Create a barrier here
    MPI_Barrier(MPI_COMM_WORLD);

    // Introduction by each processors
    cout << "I am processor " << rank << " out of " << size << endl;
  
    // Declare all parameters and files
    Parameters params;
    displacement displ; 
    radiation_pattern radiation;
    
    // if ( rank == 1 ) 
    //{
        // Parameters will be read from input file, checked  for their reasonability,
        // stored into memory, and then written into login file
        process_parameter(argc, argv, &params); 
    //};

    int len = params.total_time/ params.time_step;
    double *t = new double[len];   
    init_time (t, len, &params); //initializes time array

    double *h = new double[len];
    double *h_der = new double[len]; 
    double *R = new double[1];
    double *theta = new double[1];
    double *phi = new double[1]; 

    // if (rank == 1 ) 
    //{
        // This function generates a guassian function and its derivative
        gauss_func (h, h_der, len, &params);
    //};

    // Create a barrier here
    MPI_Barrier(MPI_COMM_WORLD);

    // Now we want to iterate over the grid centers and determine the radiation
    // pattern and displacement based on the type of force specified

    int ni = (params.n_x - 1)/ 2;
    int nj = (params.n_y - 1)/ 2;

    if ((rank == 2) )
    {
        for (int i= -ni; i <= ni; i++){
            for (int j= -nj; j <= nj; j++){

                double xx = 4 * i / params.length_x;
                double yy = 4 * j / params.length_y;

                check_grid(xx, yy, &params);
                cart_2_sph (xx, yy, R, theta, phi);

                if ((xx < 0) & (yy > 0) & (rank == 0))
                {
                    compute_displ (R[1], theta[1], phi[1] , h, h_der, &displ, len, &params);
                    rad_pattern (theta[1], phi[1], &radiation, &params);
                    write_2_file (&displ, &radiation, t, xx, yy, params.outputfile_path, len);
                };

                if ((xx >= 0) & (yy >= 0) & (rank == 1))
                {
                    compute_displ (R[1], theta[1], phi[1] , h, h_der, &displ, len, &params);
                    rad_pattern (theta[1], phi[1], &radiation, &params);
                    write_2_file (&displ, &radiation, t, xx, yy, params.outputfile_path, len);
                };

                if ((xx > 0) & (yy < 0) & (rank == 2))
                {
                    compute_displ (R[1], theta[1], phi[1] , h, h_der, &displ, len, &params);
                    rad_pattern (theta[1], phi[1], &radiation, &params);
                    write_2_file (&displ, &radiation, t, xx, yy, params.outputfile_path, len);
                };

                if ((xx <= 0) & (yy <= 0) & (rank == 3))
                {
                    compute_displ (R[1], theta[1], phi[1] , h, h_der, &displ, len, &params);
                    rad_pattern (theta[1], phi[1], &radiation, &params);
                    write_2_file (&displ, &radiation, t, xx, yy, params.outputfile_path, len);
                };
            };
        };
    };

    if ( rank == 0 ) 
    {    
        cout << "I have completed running all the functions.\n"
        "Good bye.\n"<< endl;
        std::cout << "Execution time : "<<float( clock () - t1 ) / CLOCKS_PER_SEC<< endl;
    };
    
    MPI_Finalize();

    return 0;
};
