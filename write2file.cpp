/**
 * @short   Write
 * @file    write2file.cpp
 * @author  Oluwaseun Fadugba
 *
 * This file contains write_2_file function
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include "write2file.h"       

using namespace std;

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function writes the all the displacements, radiation 
 *                    and its location (x,y) into a file
 *
 * Return             0 on sucess
 *
 */

int write_2_file (
    double *displ_P, double *displ_SH, double *displ_SV, 
    double *rad_P, double *rad_SH, double *rad_SV, 
    double *t, double xx, double yy, string outputfilename, int len)
{
    ofstream fout(outputfilename.c_str(), ios::ios_base::app);

    if (!fout)
    {
        cout << "Cannot create output file!" << endl;
        return 1;
    }

    int width = 10; // allowable width of each field

    // Start writing.

    // writing xx and yy
    fout.width(width);
    fout << "x  = " << xx << "\t" << "y  = " << yy << "\n";

    fout << "rad_P  = " << rad_P[1] << "\t" << "rad_SH  = " << rad_SH[1] << "\t" 
         << "rad_SV  = " << rad_SV[1] << "\n";

    // writing displacement results
    fout << "         t   "  "\t" << " displ_P "  "\t" << " displ_SH "  "\t" 
         << " displ_SV " << "\n";

    for (int i=1; i<=len; i++)
    {      
        fout.width(width);
        fout << t[i] << "\t" << displ_P[i] << "\t" << displ_SH[i] << "\t" 
             << displ_SV[i] << "\n";
    }

    fout << "\n"; fout << endl; fout.close();

    return 0;
}
