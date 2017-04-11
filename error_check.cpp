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
 * Author:            Yixin Zhang
 *
 * Short description: This function read all parameters in from parameter.in, check the reasonability, and then store them into login file, out to the screen as well as to the program memory.
 *
 * Return             0 on sucess
 *
 * Return             EXIT_FAILURE when parameter.in is wrong.
 */

int check_file_num(int argc, int flag)
{
    if(argc != 2)
    {
        cout << "Redunant inputfile(s) or Missing inputfile, please check\n";
        flag = 1;
    }
    else
    {
        flag =0;
    }
    return flag;
}

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function read all parameters in from parameter.in, check the reasonability, and then store them into login file, out to the screen as well as to the program memory.
 *
 * Return             0 on sucess
 *
 * Return             EXIT_FAILURE when parameter.in is wrong.
 */

int check_file_open(ifstream &infile, int flag1)
{
    if (infile.is_open())
    {
        cout << "File successfully open";
        flag1 = 0;
    }
    else
    {
        cout << "Error opening input file";
        flag1 = 1;
    }
    return flag1;
}

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function read all parameters in from parameter.in, check the reasonability, and then store them into login file, out to the screen as well as to the program memory.
 *
 * Return             0 on sucess
 *
 * Return             EXIT_FAILURE when parameter.in is wrong.
 */

int check_variables(float *alpha, float *beta, float *time_step, float *total_time,
                    float *area_x, float *area_y, int *n_x, int *n_y, float *moment,
                    int flag2)
{
    if(alpha > 0 && beta > 0 && alpha > beta && time_step >0 && total_time >0
       && area_x > 0 && area_y > 0 && n_x > 0 && n_y > 0 && moment > 0)
    {
        flag2 = 0;
    }
    else
    {
        cout << "Input file contains illegal variable(s), please check.";
        flag2 = 1;
    }
    return flag2;
}


