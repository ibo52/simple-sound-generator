/*
*WAVE FILE FORMAT SETTINGS AND FILE OPERATIONS HEADER
*HALIL IBRAHIM MUT
*/
#ifndef WAVE_SETT
#define WAVE_SETT "wave_settings.h"
#include<fstream>	//file operations
using namespace std;
int wave_format(ofstream &audioFile,int channels,int sampleRate,int bitDepth);
int wave_end_format(ofstream &audioFile);

void writeToFile(ofstream &file,int value,int size);
extern int init_pos,final_pos;

#endif
