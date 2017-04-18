/**
 * @short   error checking
 * @file    error_check.cpp
 * @author  Yixin Zhang
 *
 * This file contains the prototypes and a short description of functions used for checking errors.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>

#include "read_in.h"
#include "struct.h"

using namespace std;

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function checks the number of input file(s).
 *
 * Return             0 on sucess
 *
 * Return             1 on fail
 */

int check_file_num(int argc)
{
    if(argc == 2)
    {
        cout << "//***My program is initializing***// \n" << endl;
        return 0;
    }
    else
    {
        cout << "Redunant inputfile(s) or Missing inputfile, please check\n" << endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function checks if the input file can be open.
 *
 * Return             0 on sucess
 *
 * Return             1 on fail
 */

int check_file_open(ifstream &infile)
{
    if (infile.is_open())
    {
        cout << "File successfully opened \n" << endl;
        return 0;
    }
    else
    {
        cout << "Error opening input file\n" << endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function checks the reasonability of readin values.
 *
 * Return             0 on sucess
 *
 * Return             1 on fail
 */

int check_variables(Parameters *params)
{
    if( (params->alpha > 0) && (params->beta > 0) && (params->alpha > params->beta) && (params->time_step >0)
        && (params->total_time >0) && (params->length_x > 0) && (params->length_y > 0) && (params->n_x > 0)
       && (params->n_y > 0) && (params->moment > 0) && (params->rho > 0) )
    {
        cout << "Variables have been checked, parameters are good to use.\n" << endl;
        return 0;
    }
    else
    {
        cout << "Input file contains illegal variable(s), please check.\n" << endl;
        exit(EXIT_FAILURE);
    }
}


