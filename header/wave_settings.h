/*
*WAVE FILE FORMAT SETTINGS AND FILE OPERATIONS HEADER
*HALIL IBRAHIM MUT
*/
#ifndef WAVE_SETT
#define WAVE_SETT "wave_settings.h"
#include<fstream>	//file operations
using namespace std;

class WaveFormatter{
private:
    int init_pos,final_pos; //initial and final positions of file
    ofstream audioFile;
    
    int sampleRate;       //Period. CD quality.(quantity of how much waves will be generated on a second)
    int bitDepth;		//bits per sample.(16 as wave file standard)
    int channels;         // mono/stereo setting of sound
    short maxAmplitude;
    
    string music_name;
    
public:
    WaveFormatter();
    WaveFormatter(string music_name);
    //WaveFormatter(ofstream *audioFile,int channels,int sampleRate,int bitDepth);
    
    void write(int value,int size);//turns int value to (size)bytes of chars. Then writes to file
    void close();

private:
    int wave_begin_format();
    int wave_end_format();
};

#endif
