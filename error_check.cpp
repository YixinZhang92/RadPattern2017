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
        return 1;
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
        return 1;
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

int check_variables(float *alpha, float *beta, float *time_step, float *total_time,
                    float *area_x, float *area_y, int *n_x, int *n_y, float *moment, float *density)
{
    if( (*alpha > 0) && (*beta > 0) && (*alpha > *beta) && (*time_step >0) && (*total_time >0) &&
       (*area_x > 0) && (*area_y > 0) && (*n_x > 0) && (*n_y > 0) && (*moment > 0) && (density > 0) )
    {
        cout << "Variables have been checked.\n" << endl;
        return 0;
    }
    else
    {
        cout << "Input file contains illegal variable(s), please check.\n" << endl;
        return 1;
    }
}


