/**
 * @short   writing
 * @file    writing.cpp
 * @author  Oluwaseun Fadugba
 *
 * This file contains the prototypes and a short description of all the functions used
 * to write all wave displacements, input waveform and its derivative and its location
 * (x,y) into a file.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include "writing.h"

using namespace std;

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function writes the all the P-wave displacements, input waveform
 *                    and its derivative and its location (x,y) into a file
 *
 * Return             0 on sucess
 *
 */

int wr_Pw_2_file (
    double *displ_pt_fo_Pw_o, double *displ_si_cpl_Pw_o,
    double *displ_do_cpl_Pw_o, double *displ_fo_dipo_Pw_o,
    double *h, double *h_der, double *t, double *t_der, double xx,
    double yy, string outputfilename, int len)
{

    cout <<  "Running: write_P_waves_to_file\n";
    cout << endl;

    ofstream fout(outputfilename.c_str(), ios::out);

    if (!fout)
    {

        cout << "Cannot create output file!" << endl;
        return 1;

    }

    int width = 10;

    // Set precision.
    //fout.precision(3);
    //fout.setf(ios::fixed);   fill by zeros if not enough number of digits after the decimal point

    // Start writing.

    // writing xx
    fout.width(width);
    fout << "x  = " << xx << "\n";

    // writing yy
    fout.width(width);
    fout << "y  = " << yy << "\n";

    // writing displacement_point_force_P_wave_output

    fout << "displacement_point_force_P_wave_output" << "\n";

    for (int i=0; i<len; i++)
    {

        fout.width(width);
        fout << displ_pt_fo_Pw_o[i] << "\t";

    }
     
    fout << endl;

    // writing displacement_single_couple_P_wave_output

    fout << "displacement_single_couple_P_wave_output"<< "\n";

    for (int i=0; i<len; i++)
    {

        fout.width(width);
        fout << displ_si_cpl_Pw_o[i] << "\t";

    }

    fout << endl;

    // writing displacement_double_couple_P_wave_output

    fout << "displacement_double_couple_P_wave_output" << "\n";

    for (int i=0; i<len; i++)
    {

        fout.width(width);
        fout << displ_do_cpl_Pw_o[i] << "\t";

    }

    fout << endl;

    // writing displacement_force_dipole_P_wave_output
    fout << "displacement_force_dipole_P_wave_output" <<  "\n";

    for (int i=0; i<len; i++)
    {

        fout.width(width);
        fout << displ_fo_dipo_Pw_o[i] << "\t";

    }

    fout << endl;
    fout.close();

    return 0;
}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function writes the all the SV-wave displacements, input waveform
 *                    and its derivative and its location (x,y) into a file
 *
 * Return             0 on sucess
 *
 */

int wr_SVw_2_file (
    double *displ_pt_fo_Sw_o, double *displ_si_cpl_SVw_o,
    double *displ_do_cpl_SVw_o, double *displ_fo_dipo_SVw_o,
    double *h, double *h_der, double *t, double *t_der, double xx,
    double yy, string outputfilename, int len) 
{

    ofstream fout(outputfilename.c_str(), std::ios_base::app); // append to the fout file

    if (!fout)
    {

        cout << "Cannot create output file!" << endl;
        return 1;

    }

    int width = 10;
 
    // Set precision.
    //fout.precision(3);
    //fout.setf(ios::fixed);
    // fill by zeros if not enough number of digits after the decimal point

    // Start writing.

    // writing xx
    fout.width(width);
    fout << "x  = " << xx << "\n";

    // writing yy
    fout.width(width);
    fout << "y  = " << yy << "\n";

    // writing displacement_point_force_S_wave_output

    fout << "displacement_point_force_S_wave_output" << "\n";

    for (int i=0; i<len; i++)
    {

        fout.width(width);
        fout << displ_pt_fo_Sw_o[i] << "\t";

    }
     
    fout << endl;

    // writing displacement_single_couple_SV_wave_output

    fout << "displacement_single_couple_SV_wave_output"<< "\n";

    for (int i=0; i<len; i++)
    {

        fout.width(width);
        fout << displ_si_cpl_SVw_o[i] << "\t";

    }
  
    fout << endl;

    // writing displacement_double_couple_SV_wave_output

    fout << "displacement_double_couple_SV_wave_output" << "\n";

    for (int i=0; i<len; i++)
    {

        fout.width(width);
        fout << displ_do_cpl_SVw_o[i] << "\t";

    }
    
    fout << endl;

    // writing displacement_force_dipole_SV_wave_output
    fout << "displacement_force_dipole_SV_wave_output" <<  "\n";

    for (int i=0; i<len; i++)
    {

        fout.width(width);
        fout << displ_fo_dipo_SVw_o[i] << "\t";

    }

    fout << endl;
    fout.close();

    cout <<  "Running: write_SV_waves_to_file\n";
    cout << endl;

    return 0;
}

/**
 * Author:            Oluwaseun Fadugba
 *
 * Short description: This function writes the all the SH-wave displacements, input waveform
 *                    and its derivative and its location (x,y) into a file
 *
 * Return             0 on sucess
 *
 */

int wr_SHw_2_file (
    double *displ_pt_fo_Sw_o, double *displ_si_cpl_SHw_o,
    double *displ_do_cpl_SHw_o, double *displ_fo_dipo_SHw_o,
    double *h, double *h_der, double *t, double *t_der, double xx,
    double yy, string outputfilename, int len)
{

    cout <<  "Running: write_SH_waves_to_file\n";
    cout << endl;

    ofstream fout(outputfilename.c_str(), std::ios_base::app);
    
    if (!fout)
    {

        cout << "Cannot create output file!" << endl;
        return 1;

    }

    int width = 10;
 
    // Set precision.
    //fout.precision(3);
    //fout.setf(ios::fixed);
    // fill by zeros if not enough number of digits after the decimal point

    // Start writing.

    // writing xx
    fout.width(width);
    fout << "x  = " << xx << "\n";

    // writing yy
    fout.width(width);
    fout << "y  = " << yy << "\n";

    // writing displacement_point_force_S_wave_output

    fout << "displacement_point_force_S_wave_output" << "\n";

    for (int i=0; i<len; i++)
    {

        fout.width(width);
        fout << displ_pt_fo_Sw_o[i] << "\t";

    }

    fout << endl;

    // writing displacement_single_couple_SH_wave_output

    fout << "displacement_single_couple_SH_wave_output"<< "\n";

    for (int i=0; i<len; i++)
    {

        fout.width(width);
        fout << displ_si_cpl_SHw_o[i] << "\t";

    }

    fout << endl;

    // writing displacement_double_couple_SH_wave_output

    fout << "displacement_double_couple_SH_wave_output" << "\n";

    for (int i=0; i<len; i++)
    {

        fout.width(width);
        fout << displ_do_cpl_SHw_o[i] << "\t";

    }

    fout << endl;

    // writing displacement_force_dipole_SH_wave_output
    fout << "displacement_force_dipole_SH_wave_output" <<  "\n";

    for (int i=0; i<len; i++)
    {

        fout.width(width);
        fout << displ_fo_dipo_SHw_o[i] << "\t";

    }

    fout << endl;

    fout.close();

    return 0;
}
