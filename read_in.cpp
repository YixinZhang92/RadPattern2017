#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>
#include "prototypes.h"

using namespace std;

// defining the value of PI.

#define PI 3.14159265

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

int read_in_parameters(int argc, char* argv[], string *model_name, string *force_type,
                      string *wave_type, float *velocity, float *time_step, float *total_time,
                      string *waveform, float *area_x, float *area_y, int *n_x, int *n_y,
                      float *moment, ifstream &infile, ofstream &logfile)
{
    
    int i=0;
    string str[100], s, variable_name;
    
    
    // Check the number of input files
    if(argc != 2)
    {
        cout << "Redunant inputfile(s) or Missing inputfile, please check\n";
        exit(EXIT_FAILURE);
        // return EXIT_FAILURE;
    }
        
    //  open the input file and read the parameters in string format
    infile.open(argv[1]);
        
    i = 0;
        
    while( infile >> s )
    {
        str[i] = s;
        i++;
    }
        
    infile.close();
    cout << "It is Reading info file\n";
    
    //  Open the log file, and wtite variable values into login file
    logfile.open("login.txt");
        
    i = 0;
        
    while(str[i] != "")
    {
        if(str[i] == "model_name")
        {
            read_string(str, i, variable_name, *model_name, logfile);
        }
        
        if(str[i] == "force_type")
        {
            read_string(str, i, variable_name, *force_type, logfile);
        }
        
        if(str[i] == "wave_type")
        {
            read_string(str, i, variable_name, *wave_type, logfile);
        }
        
        if(str[i] == "waveform")
        {
            read_string(str, i, variable_name, *waveform, logfile);
        }
        
        if(str[i] == "velocity")
        {
            read_float(str, i, variable_name, *velocity, logfile);
        }
        
        
        if(str[i] == "time_step")
        {
            read_float(str, i, variable_name, *time_step, logfile);
        }
        
        if(str[i] == "total_time")
        {
            read_float(str, i, variable_name, *total_time, logfile);
        }
        
        if(str[i] == "area_x")
        {
            read_float(str, i, variable_name, *area_x, logfile);
        }
        
        if(str[i] == "area_y")
        {
            read_float(str, i, variable_name, *area_y, logfile);
        }
        
        if(str[i] == "n_x")
        {
            read_int(str, i, variable_name, *n_x, logfile);
        }
        
        if(str[i] == "n_y")
        {
            read_int(str, i, variable_name, *n_y, logfile);
        }
        
        if(str[i] == "moment")
        {
            read_float(str, i, variable_name, *moment, logfile);
        }
        
        i++;
    }
    
    logfile.close();
    
    cout << "login file has been written.\n" <<endl;
    
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

// read variables in as int

int read_int(string str[], int i, string variable_name,
               int &int_value, ofstream &file)

{
    
    char* c;
    
    variable_name = str[i];
    file << variable_name << "=\t" << endl;
    cout << variable_name << "=\t" << endl;
    
    c = const_cast<char*>(str[i+1].c_str());
    sscanf(c,"%d", &int_value);
    file << int_value << endl << "\n";
    cout << int_value << endl << "\n";
    
    return 0;
    
}


