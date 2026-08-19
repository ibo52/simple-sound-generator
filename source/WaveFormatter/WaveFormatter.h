/*
*WAVE FILE FORMAT SETTINGS AND FILE OPERATIONS HEADER
*HALIL IBRAHIM MUT
*/
#ifndef WAVE_SETT
#define WAVE_SETT
#include<fstream>	//file operations
#include<cstdint>
using namespace std;

class WaveFormatter{
private:
    streampos init_pos;
    streampos final_pos; //initial and final positions of file
    ofstream audioFile;
    
    int formatType=1;//(1: PCM integer, 3: IEEE 754 float)    
    string music_name="out_file";
    
public:
    int sampleRate=44100;       //44100 (CD), 48000 (DAT).(quantity of how much waves will be generated on a second)
    int bitDepth=16;		//bits per sample.(16 as wave file standard)
    int channels=2;         // mono/stereo setting of sound
    short maxAmplitude=(1<<(bitDepth-1))-1;
    WaveFormatter();
    WaveFormatter(string music_name);
    //WaveFormatter(ofstream *audioFile,int channels,int sampleRate,int bitDepth);
    
    WaveFormatter(const WaveFormatter&) = delete;
    WaveFormatter& operator=(const WaveFormatter&) = delete;
    
    void write(int32_t value,uint32_t size);//turns int value to (size)bytes of chars. Then writes to file
    void close();

private:
    int wave_begin_format();
    int wave_end_format();
};

#endif
