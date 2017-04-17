/**
 * @short   write Headers
 * @file    write2file.h
 * @author  Yixin Zhang
 *
 * This function writes the all the P-, SH- and SV-wave displacements, radiation pattern,
 * and its location (x,y) into a file.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>

using namespace std;


bool rename_file(string& str, const string& from, const string& to);
