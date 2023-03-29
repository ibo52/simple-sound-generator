/*WAVE FILE FORMAT SETTINGS AND FILE OPERATIONS -HALIL IBRAHIM MUT*/
#include "../header/wave_settings.h"
#include <iostream>
WaveFormatter::WaveFormatter(){
    this->music_name="sample_music.wav";
    this->audioFile.open("../sounds/"+this->music_name,ios::binary);//open file as binary;
    this->channels=1;
    this->sampleRate=44100;
    this->bitDepth=16;
    
    this->maxAmplitude=(2<<(this->bitDepth-1))-1;

    this->wave_begin_format();
    
}
WaveFormatter::WaveFormatter(string music_name){
    this->music_name=music_name;
    this->audioFile.open("../sounds/"+this->music_name,ios::binary);//open file as binary;
    this->channels=1;
    this->sampleRate=44100;
    this->bitDepth=16;
    
    this->maxAmplitude=(2<<(this->bitDepth-1))-1;
    
    this->wave_begin_format();
}

int WaveFormatter::wave_begin_format(){
    //waw file encoding
    //https://docs.fileformat.com/audio/wav/
    
    //format section
    this->audioFile<<"RIFF";	//header chunk. 4bytes
    this->audioFile<<"----";	//file size.will be calculated later. 4bytes
    this->audioFile<<"WAVE";	//sound format. 4 bytes
    this->audioFile<<"fmt ";	//format chunk. 4 bytes
    this->write(16,4);//size of format chunk(all above)
    
    this->write(1,2);			//compression code(PCM);
    this->write(this->channels,2);            //number of channels(1:mono; 2:stereo)
    this->write(this->sampleRate,4);          //sample rate info.(44100-CD; 48000 better)
    this->write(this->sampleRate*this->bitDepth*this->channels/8,4);//bit rate;
    this->write(2,2);			//block align;
    this->write(this->bitDepth,2);            //bitdepth of file
    
    //data section
    this->audioFile<<"data";
    this->audioFile<<"----";			//we will write the file size after data appended
    
    this->init_pos=audioFile.tellp();
    return 0;
}

//write (value)chars as (size)bytes to file
void WaveFormatter::write(int value,int size){
	//turns int value to (size)bytes of chars. Then writes to file
    this->audioFile.write(reinterpret_cast<const char*> (&value),size);
    
}
void WaveFormatter::close(){
    this->wave_end_format();
}

//process the formatted wavefile and determine sizes.Then CLOSE
int WaveFormatter::wave_end_format(){
    
    this->final_pos=this->audioFile.tellp();
	
    this->audioFile.seekp( this->init_pos-4) ;      //go to empty space at data section
    this->write(this->final_pos-init_pos,4 );//and write data size as 4byte
    
    this->audioFile.seekp( 4,ios::beg );                //seek beginning of file and go 4bytes
    this->write(this->final_pos-8,4 );	//write whole file size
                                                        //to format section as 4byte.
                                                        //except deata section, which is 8 bytes
    this->audioFile.close();
    return 0;
}
