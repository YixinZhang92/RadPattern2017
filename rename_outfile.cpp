/**
 * @short   read in parameters
 * @file    read_in.cpp
 * @author  Yixin Zhang
 *
 * This file contains the prototypes for reading parameters from the input file and write into memory and login file.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>

#include "read_in.h"
#include "error_check.h"

using namespace std;

bool rename_file(string& str, const string& from, const string& to)
{
    size_t start_pos = str.find(from);
    if(start_pos == string::npos)
    {
        return false;
    }
    else
    {
        str.replace(start_pos, from.length(), to);
        return true;
    }
}

