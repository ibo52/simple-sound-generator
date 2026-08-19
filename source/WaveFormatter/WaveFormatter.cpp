/*WAVE FILE FORMAT SETTINGS AND FILE OPERATIONS -HALIL IBRAHIM MUT*/
#include "WaveFormatter.h"
#include <iostream>

WaveFormatter::WaveFormatter(): WaveFormatter("out_file"){}

WaveFormatter::WaveFormatter(string music_name){

    this->music_name=music_name;
    
    this->audioFile.open(this->music_name, ios::binary | ios::trunc);//open file as binary;
    
    if(this->audioFile.is_open()){
		
		this->wave_begin_format();
    }else{
    	
        throw runtime_error(
        "WaveFormatter: Could not open file: " + music_name
        );
    }
}

int WaveFormatter::wave_begin_format(){
    //waw file encoding
    //https://docs.fileformat.com/audio/wav/
    
    //format section
    this->audioFile<<"RIFF";	//header chunk. 4bytes
    this->audioFile<<"----";	//file size.will be calculated later. 4bytes
    this->audioFile<<"WAVE";	//sound format. 4 bytes
    this->audioFile<<"fmt ";	//format chunk. 4 bytes
    this->write(16,4);//size of format chunk in terms of bits(all above)
    
    this->write(this->formatType,2);			//type of format: 1 is PCB
    this->write(this->channels,2);            //number of channels(1:mono; 2:stereo)
    this->write(this->sampleRate,4);          //sample rate info.(44100-CD; 48000 better)
    this->write(this->sampleRate*this->bitDepth*this->channels/8,4);//bit rate;
    this->write(this->channels*this->bitDepth/8,2);			//block align;
    this->write(this->bitDepth,2);            //bitdepth of file
    
    //data section
    this->audioFile<<"data";
    this->audioFile<<"----";			//we will write the file size after data appended
    
    this->init_pos=audioFile.tellp();
    return 0;
}

//write (value)chars as (size)bytes to file
void WaveFormatter::write(int32_t value,uint32_t size){
	
    for (uint32_t i = 0; i < size; i++)
    {
        char byte= static_cast<char>( (value>>(8*i)) & 0xff );
        this->audioFile.put(byte);
    }
}
void WaveFormatter::close(){
    this->wave_end_format();
}

//process the formatted wavefile and determine sizes.Then CLOSE
int WaveFormatter::wave_end_format(){
    
    this->final_pos=this->audioFile.tellp();
	
    uint32_t dataSize =
    static_cast<uint32_t>(this->final_pos - this->init_pos);

    uint32_t riffSize =
        static_cast<uint32_t>(this->final_pos - streampos(8));

    this->audioFile.seekp(this->init_pos - streamoff(4));
    this->write(dataSize, 4);

    this->audioFile.seekp(streamoff(4), ios::beg);
    this->write(riffSize, 4);
                                                        //to format section as 4byte.
                                                        //except deata section, which is 8 bytes
    this->audioFile.close();
    return 0;
}
