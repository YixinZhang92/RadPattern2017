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
#include <string.h>
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
     displacement *displ, 
    double *rad_P, double *rad_SH, double *rad_SV, 
    double *t, double xx, double yy, string outputfilename, int len)
{
    // write displacement
    write_rad_patt (rad_P, rad_SH, rad_SV, xx, yy, "outputfilename");

    // write radiation pattern
    write_displ (displ, t, xx, yy, "outputfilename", len);
    
    return 0;
}


/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function writes the displacements and its location (x,y) into a file
 *
 * Return             0 on sucess
 *
 */

int write_displ (
    displacement *displ, 
    double *t, double xx, double yy, string outputfilename, int len)
{
    char str[80]; strcpy (str,outputfilename.c_str()); strcat (str,"_displ.txt"); 

    ofstream fout(str, ios::ios_base::app);

    if (!fout)
    {
        cout << "Cannot create displacement output file!" << endl;
        return 1;
    }

    int width = 10; // allowable width of each field

    // Start writing.

    // writing xx and yy
    fout.width(width);
    fout << "x  = " << xx << "\t" << "y  = " << yy << "\n";

    // writing displacement results
    fout << "         t   "  "\t" << " displ_P "  "\t" << " displ_SH "  "\t" 
         << " displ_SV " << "\n";

    for (int i=1; i<=len; i++)
    {      
        fout.width(width);
        fout << t[i] << "\t" << displ->P[i] << "\t" << displ->SH[i] << "\t" 
             << displ->SV[i] << "\n";
    }

    fout << "\n"; fout << endl; fout.close();
 return 0;
};

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function writes the radiation pattern results and its location (x,y) into a file
 *
 * Return             0 on sucess
 *
 */

int write_rad_patt (
    double *rad_P, double *rad_SH, double *rad_SV, 
    double xx, double yy, string outputfilename)
{
    char str[80]; strcpy (str,outputfilename.c_str()); strcat (str,"_rad_patt.txt");

    ofstream fout(str, ios::ios_base::app);

    if (!fout)
    {
        cout << "Cannot create radiation pattern output file!" << endl;
        return 1;
    }

    int width = 10; // allowable width of each field

    // Start writing.

    // writing xx and yy
    fout.width(width);

    fout << xx << "\t" << yy << "\t" << rad_P[1] << "\t" << rad_SH[1] << "\t" << rad_SV[1] << endl;

    fout.close();
 
return 0;
};
