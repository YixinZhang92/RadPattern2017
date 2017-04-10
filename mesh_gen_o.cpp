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
 * Short description: This function gives the x,y coordinates for every point
 *                    and returns the spherical coordinates for each grid
 *
 * Return             0 on sucess
 *
 */

int mesh_gen_o (float area_x, float area_y, int n_x, int n_y, float X[], float Y[], ofstream &file)
{

    cout <<  "Running: mesh_generator\n";
    cout << endl;
    
    // Perform operation.
    
    //float temp;
    
    for (int i=0; i<n_x; i++)
    {
        
        X[i] = i * area_x / (n_x-1);
        
        for (int j=0; j<n_y; j++)
        {
            
            Y[j] = j * area_y / (n_y-1);

            file << X[i] << ", " << Y[j] << " \n";
            //cout << X[i] << ", " << Y[j] << ";  "; //commented out for too much space used
            
        }
        
    }

    return 0;
}



