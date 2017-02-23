#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

//  output values in scientific form
using std::scientific;
               
//  purpose: read in the parameters from input file and write these values to a log file
//  usage: ./rd_test EQinfo.txt logfile 

int main(int argc, char* argv[])
{
    
    string s;
//    string sentence[20];
    string str[100];
    string model_name, force_type, wave_type,waveform;
    float velocity, time_step, total_time, area_x, area_y, 
        grid_x, grid_y, moment;

    int i;
    char* c;
    
    
    if(argc < 3)
    { 
           cout << "Missing inputfile or logfile, please check\n";
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

    logfile.open(argv[2]);
      
    i = 0;
    while(str[i] != "")
    {
         if(str[i] == "model_name")
         {
            // c = const_cast<char*>(str[i+1].c_str());
            // sscanf(str[i+1], "%s", &model_name);
             model_name = str[i+1];
             logfile << model_name << endl;
             logfile << "\n";
             i++;
         }
         else if(str[i] == "force_type")
         {
             //c = const_cast<char*>(str[i+1].c_str());
             //sscanf("%s", &force_type);
             force_type = str[i+1];
             logfile << force_type << endl;
             logfile << "\n";
             i++;
         }    
         else if(str[i] == "wave_type")
         {
             //c = const_cast<char*>(str[i+1].c_str());
             //sscanf("%s", &wave_type);
             wave_type = str[i+1];
             logfile << wave_type << endl;
             logfile << "\n";
             i++;
         }
         else if(str[i] == "velocity")
         {
             c = const_cast<char*>(str[i+1].c_str());
             sscanf(c,"%e", &velocity);
             
             logfile << velocity << endl;
             logfile << "\n";
             i++;
         }    
         else if(str[i] == "time_step")
         {
              c = const_cast<char*>(str[i+1].c_str());                                
              sscanf(c,"%e", &time_step);
              logfile << time_step << "\n";
              logfile << "\n"; 
              i++;     
         }
         else if(str[i] == "total_time")
         {
              c = const_cast<char*>(str[i+1].c_str());                                
              sscanf(c,"%e", &total_time);
              logfile << total_time << "\n";
              logfile << "\n";
              i++; 
         }
         else if(str[i] == "waveform")
         {
              //c = const_cast<char*>(str[i+1].c_str());
              //sscanf("%s", &waveform);
              waveform = str[i+1];
              logfile << waveform << "\n";
              logfile << "\n";
              i++;
         }
         else if(str[i] == "area_x")
         {
              c = const_cast<char*>(str[i+1].c_str());
              sscanf(c,"%e", &area_x);
              logfile << area_x << "\n";
              logfile << "\n";
              i++;
         }     
         else if(str[i] == "area_y")
         {
              c = const_cast<char*>(str[i+1].c_str());
              sscanf(c,"%e", &area_y);
              logfile << area_y << "\n";
              logfile << "\n";
              i++;
         }
         else if(str[i] == "grid_x")
         {
              c = const_cast<char*>(str[i+1].c_str());
              sscanf(c,"%e", &grid_x);
              logfile << grid_x << "\n";
              logfile << "\n";
              i++;
         }
         else if(str[i] == "grid_y")
         {
              c = const_cast<char*>(str[i+1].c_str());
              sscanf(c,"%e", &grid_y);
              logfile << grid_y << "\n";
              logfile << "\n";
              i++;
         }
         else if(str[i] == "moment")
         {
              c = const_cast<char*>(str[i+1].c_str());
              sscanf(c,"%e", &moment);
              logfile << moment << "\n";
              logfile << "\n";
              i++;
         }
        i++;
    }
}


