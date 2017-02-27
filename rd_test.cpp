#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

               
//  purpose: read in the parameters from input file and write these values to a log file
//  usage: ./rd_test EQinfo.txt logfile 

int read_string(string str[], int i, string variable_name,
                string &variable_value, ofstream &file);
int read_float(string str[], int i, string variable_name,
               float &variable_value, ofstream &file);


int main(int argc, char* argv[])
{
    
    string s, variable_name, string_value;
   

    string str[100];
    string model_name, force_type, wave_type,waveform;
    float velocity, time_step, total_time, area_x, area_y, 
        grid_x, grid_y, moment;

    int i;
    
    
    if(argc < 2)
    { 
           cout << "Missing inputfile, please check\n";
           return EXIT_FAILURE;
     }
    
    
//  open the input file and read the parameters in string format    
    ifstream infile;
    infile.open(argv[1]);

    i = 0;
    while( infile >> s )
    { 
         str[i] = s;
         i++;
     }
    
    infile.close();
    
      
//  open the log file, and wtite the input values in float format      
    ofstream logfile;

    logfile.open("login.txt");
    string line;
      
    i = 0;
    while(str[i] != "")
    {
        if(str[i] == "model_name")
            read_string(str, i, variable_name, model_name, logfile);
         
        if(str[i] == "force_type")
            read_string(str, i, variable_name, force_type, logfile);
        
        if(str[i] == "wave_type")
            read_string(str, i, variable_name, wave_type, logfile);
        
        if(str[i] == "waveform")
            read_string(str, i, variable_name, string_value, logfile);
        
        
        if(str[i] == "velocity")
            read_float(str, i, variable_name, velocity, logfile);
        
        if(str[i] == "time_step")
            read_float(str, i, variable_name, time_step, logfile);

        if(str[i] == "total_time")
            read_float(str, i, variable_name, total_time, logfile);

        if(str[i] == "area_x")
            read_float(str, i, variable_name, area_x, logfile);

        if(str[i] == "area_y")
            read_float(str, i, variable_name, area_y, logfile);
        
        if(str[i] == "grid_x")
            read_float(str, i, variable_name, grid_x, logfile);

        if(str[i] == "grid_y")
            read_float(str, i, variable_name, grid_y, logfile);

        if(str[i] == "moment")
            read_float(str, i, variable_name, moment, logfile);

        i++;
    }
    
    logfile.close();
    
    return 0;
}




int read_string(string str[], int i, string variable_name,
                string &variable_value, ofstream &file)
{
    variable_name = str[i];
    file << variable_name << "=\t" << endl;
    cout << variable_name << "=\t" << endl;
    
    variable_value = str[i+1];
    file << variable_value << endl << "\n";
    cout << variable_value << endl << "\n";
    
    return 0;
}


int read_float(string str[], int i, string variable_name,
                float &variable_value, ofstream &file)
{
    char* c;
    
    variable_name = str[i];
    file << variable_name << "=\t" << endl;
    cout << variable_name << "=\t" << endl;
    
    c = const_cast<char*>(str[i+1].c_str());
    sscanf(c,"%e", &variable_value);
    file << variable_value << endl << "\n";
    cout << variable_value << endl << "\n";
    
    return 0;
}












