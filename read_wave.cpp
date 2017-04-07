/**
 * @short   Prototypes
 * @file    read_wave.cpp
 * @author  Yixin Zhang
 *
 * This file contains the prototypes and a short description of all the functions used
 * to read the input waveform.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include "read_wave.h"

using namespace std;

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function float inputs
 *
 * Return             0 on sucess
 *
 * Return             EXIT_FAILURE when the input file is missing
 */

// Just test, try to add read in program
// made by Yixin Zhang
//

int read_string(string str[], int i, string variable_name,
    string &string_value, ofstream &file)
{

    variable_name = str[i];
    file << variable_name << "=\t" << endl;
    cout << variable_name << "=\t" << endl;

    string_value = str[i+1];
    file << string_value << endl << "\n";
    cout << string_value << endl << "\n";
    
    return 0;

}

/**
 * Author:            Yixin Zhang
 *
 * Short description: This function float inputs
 *
 * Return             0 on sucess
 *
 */

int read_float(string str[], int i, string variable_name,
    float &float_value, ofstream &file)
{

    char* c;
    
    variable_name = str[i];
    file << variable_name << "=\t" << endl;
    cout << variable_name << "=\t" << endl;

    c = const_cast<char*>(str[i+1].c_str());
    sscanf(c, "%e", &float_value);
    file << float_value << endl << "\n";
    cout << float_value << endl << "\n";

    return 0;
}

//  End of test by Yixin Zhang


/**
 * Author:            Yixin Zhang
 *
 * Short description: This function read the input waveforms in the program
 *
 * Return             0 on sucess
 *
 */

int read_wave_file ()
{

    cout << "Running: read_wave_file\n";
    cout << endl;

    return 0;
}


