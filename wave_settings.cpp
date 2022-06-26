/*WAVE FILE FORMAT SETTINGS AND FILE OPERATIONS -HALIL IBRAHIM MUT*/
#include "wave_settings.h"

int init_pos,final_pos; //initial and final positions of file

int wave_format(ofstream &audioFile,int channels,int sampleRate,int bitDepth){
	//waw file encoding
	//https://docs.fileformat.com/audio/wav/
    //format section
    audioFile<<"RIFF";	//header chunk. 4b
    audioFile<<"----";	//file size.will be calculated later. 4b
    audioFile<<"WAVE";	//sound format. 4 b
    audioFile<<"fmt ";	//format chunk. 4 b
    writeToFile(audioFile,16,4);//size of format chunk(all above)
    
    writeToFile(audioFile,1,2);			//compression code(PCM)
    writeToFile(audioFile,channels,2);	//number of channels(1:mono; 2:stereo)
    writeToFile(audioFile,sampleRate,4);//sample rate info.(44100-CD; 48000 better)
    writeToFile(audioFile,sampleRate*bitDepth*channels/8,4);//bit rate
    writeToFile(audioFile,2,2);			//block align
    writeToFile(audioFile,bitDepth,2);	//bitdepth of file
    
    //data section
    audioFile<<"data";
    audioFile<<"----";			//we will write the file size later
    
    init_pos=audioFile.tellp();
    return 0;
}

//write (value)chars as (size)bytes to file
void writeToFile(ofstream &file,int value,int size){
	//turns int value to (size)bytes of chars. Then writes to file
    file.write(reinterpret_cast<const char*> (&value),size);
    
}

//process the formatted wavefile and determine sizes.Then CLOSE
int wave_end_format(ofstream &audioFile){

	final_pos=audioFile.tellp();
	
	audioFile.seekp(init_pos-4);//go to empty space at data section
    writeToFile(audioFile,final_pos-init_pos,4);//and write data size as 4byte
    
    audioFile.seekp(4,ios::beg);			  //seek beginning of file and go 4bytes
    writeToFile(audioFile,final_pos-8,4);	 //write whole file size
    										//to format section as 4byte.
    									   //except deata section, which is 8 bytes
    audioFile.close();
    return 0;
}
