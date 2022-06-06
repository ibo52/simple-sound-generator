/* 
 * File:   main.cpp
 * Author: ibrahim
 * ----------------------------
 * Very Simple Sound Generator.
 * This program generatessound by 
 * calculation sine oscillation according to
 * given frequency and amp rates.
 * Created on January 31, 2022, 10:36 AM
 */

#include <cstdlib>
#include<iostream>
#include<math.h>//required to use pi value
#include<fstream>//file operations
#include<map>//hashmap for notes
#include<string>//use instead char* to suprass warnings
using namespace std;
/*
 * 
 */
//SES ÜRETEÇ YAZILIMI DENEME

const int sampleRate=44100;	 //Period. CD quality.(1 periyotluk dalga sayısı)
const int bitDepth=16;		//bits per sample.as wave file standard 
const int channels=1;	   // mono/stereo setting of sound


class SineOscillator{//Produce sinuse waves (representation of sounds)
public:
    float frequency,amplitude,angle=0.0f,offset=0.0;

public:
	SineOscillator(){}//constructor
    SineOscillator(float freq,float amp):frequency(freq),amplitude(amp){
        offset=(2*M_PI*frequency /sampleRate);
    }
    
    float process(){
        //Y= a* sin(2*pi *frequency/ sampleRate)
        auto sample= amplitude*sin(angle);
        angle+=offset;
        return sample;
    }
};

void writeToFile(ofstream &file,int value,int size){
	//turns int value to (size)bits of chars. Then writes to file
    file.write(reinterpret_cast<const char*> (&value),size);
    
}

//write to file note's oscillation and duration of that note(how much seconds will it play)
void uretec(ofstream &audioFile,SineOscillator so2,float duration,double maxAmplitude){
    
    int i;
    for(i=0;i<sampleRate*duration;i++){
        auto sample2=so2.process();
        int intSample2=static_cast<int> (sample2*maxAmplitude);
        
        audioFile.write(reinterpret_cast<char*> (&intSample2),2);
           
    }  
}

//settings of wave file
int wave_format(ofstream &audioFile){
	//waw file encoding
	//https://docs.fileformat.com/audio/wav/
    //format chunk
    audioFile<<"RIFF";//header chunk. 4bit
    audioFile<<"----";//file size.will be calculated later. 4bit
    audioFile<<"WAVE";//sound format. 4 bit
    audioFile<<"fmt ";//format chunk. 4 bit
    writeToFile(audioFile,16,4);//size of format chunk(all above)
    
    writeToFile(audioFile,1,2);//compression code(PCM)
    writeToFile(audioFile,channels,2);//number of channels(1:mono; 2:stereo)
    writeToFile(audioFile,sampleRate,4);//sample rate info.(44100-CD; 48000 better)
    writeToFile(audioFile,sampleRate*bitDepth*channels/8,4);//bit rate
    writeToFile(audioFile,2,2);//block align
    writeToFile(audioFile,bitDepth,2);//bitdepth of file
    
    //dataChunk
    audioFile<<"data";
    audioFile<<"----";//we will write the file size later
    return 0;
}

int note_shift_example(){

	int duration=1;//duration of sound goes
	float amplitude=0.5;//sound magnitude
	
	//https://mixbutton.com/mixing-articles/music-note-to-frequency-chart/
	//musical note (hertz) map
	map<string,float> map={
	{"c",261.63},//do
	{"c#",277.18},//re
	{"d",293.66},//..
	{"d#",311.13},
	{"e",329.63},
	{"f",349.23},
	{"f#",369.99},
	{"g",392.0},
	{"g#",415.3},
	{"a",440.0},
	{"a#",466.16},
	{"b",493.88},
	
	{"c2",523.26},
	{"c#2",554.36},
	{"d2",587.32},//..
	{"d#2",622.26},
	{"e2",659.26},
	{"f2",698.46},
	{"f#2",739.98},
	{"g2",784.0},
	{"g#2",830.6},
	{"a2",880.0},
	{"a#2",932.32},
	{"b2",987.76},
	
	{"c3",1046.5},
	{"c#3",1108.73},
	{"d3",1174.66},//..
	{"d#3",1244.51},
	{"e3",1318.51},
	{"f3",1396.91},
	{"f#3",1479.9},
	
	{".",0.0}//duraklama
	};
	
	//sample music coded. It is a folk song 
	//from the Tunceli region of Turkey
	string music_name="nenni bebek.wav";
	float notes[220][2]={
	{map["f#2"],0.1},
	{map["."],0.05},
	{map["f#2"],0.1},
	{map["."],0.05},
	
	{map["g#2"],0.1},
	{map["c#2"],0.1},
	{map["."],0.05},
	{map["g#2"],0.4},
	{map["c#2"],0.1},
	
	{map["g#2"],0.4},
	{map["f#2"],0.4},
	{map["c#2"],0.05},
	
	//mi fa sol la
	{map["g#2"],0.1},
	{map["."],0.05},
	{map["g#2"],0.1},
	{map["."],0.05},
	
	{map["a#2"],0.1},
	{map["."],0.05},
	{map["a#2"],0.1},
	{map["."],0.05},
	
	{map["b2"],0.1},
	{map["."],0.05},
	{map["b2"],0.1},
	{map["."],0.05},
	
	{map["c#3"],0.25},
	{map["."],0.05},
	
	{map["b2"],0.1},
	{map["."],0.05},
	{map["c#3"],0.1},
	{map["."],0.05},
	
	{map["a#2"],0.1},
	{map["."],0.05},
	{map["b2"],0.1},
	{map["."],0.05},
	
	{map["g#2"],0.4},
	{map["c#2"],0.05},
	{map["f#2"],0.4},
	{map["c#2"],0.05},
	
	//----yineleme oncesi ara ses->redo-redo
	{map["f#2"],0.1},
	{map["."],0.05},
	{map["e2"],0.1},
	{map["."],0.05},
	
	{map["f#2"],0.1},
	{map["."],0.05},
	{map["e2"],0.1},
	{map["."],0.05},
	//--------------
	//yineleme
	{map["f#2"],0.1},
	{map["."],0.05},
	{map["b2"],0.1},
	{map["."],0.05},
	
	{map["g#2"],0.4},
	{map["c#2"],0.05},
	
	{map["g#2"],0.1},
	{map["c#2"],0.05},
	{map["g#2"],0.1},
	{map["c#2"],0.05},
	{map["g#2"],0.1},
	{map["."],0.05},
	
	{map["g#2"],0.2},
	{map["."],0.05},
	
	{map["g#2"],0.1},
	{map["."],0.05},
	{map["f#2"],0.1},
	{map["c#2"],0.05},
	
	//mi fa sol la
	{map["g#2"],0.1},
	{map["."],0.05},
	{map["a#2"],0.1},
	{map["."],0.05},
	
	{map["a#2"],0.1},
	{map["."],0.05},
	{map["b2"],0.1},
	{map["."],0.05},
	
	{map["b2"],0.1},
	{map["."],0.05},
	{map["b2"],0.1},
	{map["."],0.05},
	
	{map["c#3"],0.25},
	{map["."],0.05},
	
	{map["b2"],0.1},
	{map["."],0.05},
	{map["c#3"],0.1},
	{map["."],0.05},
	
	{map["a#2"],0.1},
	{map["."],0.05},
	{map["b2"],0.1},
	{map["."],0.05},
	
	{map["g#2"],0.4},
	{map["c#2"],0.05},
	{map["f#2"],0.25},
	{map["c#2"],0.05},
	
	//düşüş >>son kısım
	//sol mire redo remi
	{map["b2"],0.1},
	{map["a#2"],0.1},
	{map["b2"],0.25},
	
	{map["g#2"],0.1},
	{map["."],0.05},
	{map["f#2"],0.25},
	{map["."],0.05},
	
	{map["f#2"],0.1},
	{map["."],0.05},
	{map["e2"],0.25},
	{map["."],0.05},
	
	{map["f#2"],0.1},
	{map["."],0.05},
	{map["g#2"],0.25},
	{map["."],0.05},
	
	//mi.. doresi dosi dore
	{map["g#2"],0.25},
	{map["."],0.05},
	{map["g#2"],0.1},
	{map["."],0.05},
	{map["g#2"],0.1},
	{map["."],0.05},
	
	{map["e2"],0.1},
	{map["."],0.05},
	{map["f#2"],0.1},
	{map["."],0.05},
	{map["d#2"],0.25},
	{map["."],0.05},
	
	{map["e2"],0.1},
	{map["."],0.05},
	{map["d#2"],0.25},
	{map["."],0.05},
	
	{map["e2"],0.1},
	{map["."],0.05},
	{map["f#2"],0.25},
	{map["."],0.05},
	
	//re. dosi sila sido
	{map["f#2"],0.25},
	{map["."],0.05},

	{map["e#2"],0.1},
	{map["."],0.05},
	{map["d#2"],0.25},
	{map["."],0.05},
	
	{map["d#2"],0.1},
	{map["."],0.05},
	{map["c#2"],0.25},
	{map["."],0.05},
	
	{map["d#2"],0.1},
	{map["."],0.05},
	{map["e2"],0.25},
	{map["."],0.05},
	//dosido si-la si-si lala
	{map["e2"],0.05},
	{map["d#2"],0.05},
	{map["e2"],0.25},
	{map["."],0.05},
	
	{map["d#2"],0.25},
	{map["."],0.05},
	{map["c#2"],0.25},
	{map["."],0.05},
	
	{map["d#2"],0.25},
	{map["."],0.05},
	{map["d#2"],0.1},
	{map["."],0.05},
	
	{map["c#2"],0.1},
	{map["."],0.05},
	{map["c#2"],0.25},
	{map["."],0.05},
	
	{map["c#2"],0.25},
	{map["."],0.05},
	{map["f#2"],0.25},
	{map["."],0.05},
	{map["c#2"],0.4},
	{map["."],0.05},
	
	//deyiş kısmı
	//fa sol la-la
	{map["a#2"],0.25},
	{map["."],0.05},
	{map["b2"],0.25},
	{map["."],0.05},
	{map["c#3"],0.4},
	{map["."],0.05},
	{map["c#3"],0.4},
	{map["."],0.05},
	//la do si la-la
	{map["c#3"],0.4},
	{map["."],0.05},
	{map["e3"],0.1},
	{map["."],0.05},
	{map["d#3"],0.25},
	{map["."],0.05},
	{map["c#3"],0.25},
	{map["."],0.05},
	{map["c#3"],0.25},
	{map["."],0.05},
	
	{map["b2"],0.1},
	{map["a#2"],0.05},
	{map["b2"],0.25},
	
	//la fa sol fa...x3
	{map["c#3"],0.1},
	{map["."],0.05},
	{map["a#2"],0.1},
	{map["."],0.05},
	{map["b2"],0.1},
	{map["."],0.05},
	{map["a#2"],0.1},
	{map["."],0.05},
	
	{map["c#3"],0.1},
	{map["."],0.05},
	{map["a#2"],0.1},
	{map["."],0.05},
	{map["b2"],0.1},
	{map["."],0.05},
	{map["a#2"],0.1},
	{map["."],0.05},
	
	
	{map["c#3"],0.1},
	{map["."],0.05},
	{map["a#2"],0.1},
	{map["."],0.05},
	{map["b2"],0.1},
	{map["."],0.05},
	{map["a#2"],0.1},
	{map["."],0.05},
	
	{map["b2"],0.4},
	{map["."],0.05},
	{map["c#3"],0.1},
	{map["."],0.05},
	{map["a#2"],0.1},
	{map["."],0.05},
	{map["b2"],0.4},
	{map["."],0.05},
	
	//ara geçiş
	{map["b2"],0.25},
	{map["."],0.05},
	{map["b2"],0.1},
	{map["."],0.05},
	{map["b2"],0.1},
	{map["."],0.05}
	};
	

	SineOscillator osc;//declare oscillator to calc musical notes
	
	ofstream audioFile;//declare a file to save sound
	audioFile.open(music_name,ios::binary);//open file as binary
	wave_format(audioFile);//dump initial settings of wav format
    
    int firstPosition=audioFile.tellp();//returns current pos of cursor on file
    							       //to determine (sound data and whole file) size
    auto maxAmplitude=pow(2,bitDepth-1)-1;
    
    //write the sound data(notes array) to file
	int i;		//notes[i][0]=musical note ;; notes[i][1]=how much note goes
	for(i=0;i<sizeof(notes)/sizeof(*notes);i++){
	
		osc=SineOscillator(notes[i][0],amplitude);//calculation of musical note
		
		uretec(audioFile,osc,notes[i][1],maxAmplitude);//dumping to file
	}
	
	int finalPosition=audioFile.tellp();//end of data write, and also file
    
    audioFile.seekp(firstPosition-4);//go to empty format space from before
    writeToFile(audioFile,finalPosition-firstPosition,4);//and write data size
    													//to data chunk section
    
    audioFile.seekp(4,ios::beg);			  //beginning of file
    writeToFile(audioFile,finalPosition-8,4);//write whole file size
    										//to format chunk section.
    audioFile.close();
    return 0;
    
}

int main(int argc, char** argv) {
	/*write an example sound.wav file and exit*/
    if(-1==note_shift_example()){
    	cout<<"program sıçtı. Beni bırak gideyim ağabey.\n";
    	return -1;
    }

    return 0;
}

