#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>

using namespace std;

#ifndef parameters
#define parameters

struct Parameters
{
    int n_x, n_y;
    string model_name, force_type, waveform, logfile_path, outputfile_path;
    float alpha, beta, time_step, total_time, length_x, length_y, moment, rho;
};

#endif

#ifndef Displacement
#define Displacement

struct displacement
{
    double P[100000];
    double SH[100000];
    double SV[100000];
};

#endif
