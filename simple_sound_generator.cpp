/* 
 * File:   main.cpp
 * Author: ibrahim
 * ----------------------------
 * Very Simple Sound Generator.
 * This program generates sound by 
 * producing sine oscillations according to
 * given frequency and amplitude rates.
 * Created on January 31, 2022, 10:36 AM
 */
#include "example_music.h" //example music code to listen
#include "wave_settings.h" //settings for wave file format
#include <cstdlib>
#include<iostream>
#include<math.h>	//required to use pi value
#include<fstream>	//file operations
using namespace std;
/*
 * 
 */
const int sampleRate=44100;	 //Period. CD quality.(1 periyotluk dalga sayısı)
const int bitDepth=16;		//bits per sample.(16 as wave file standard)
const int channels=1;	   // mono/stereo setting of sound
auto maxAmplitude=pow(2,bitDepth-1)-1;

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


//write to file note's oscillation and duration of that note(how much seconds will it play)
void uretec(ofstream &audioFile,SineOscillator so2,float duration,double maxAmplitude){
    
    int i;
    for(i=0;i<sampleRate*duration;i++){
        auto sample2=so2.process();
        int intSample2=static_cast<int> (sample2*maxAmplitude);
        
        audioFile.write(reinterpret_cast<char*> (&intSample2),2);
           
    }  
}

//monophonic sound: just one harmony layer(octave) that plays notes, i suppose
int monophony_example(string music_name){

	float amplitude=0.5;	//sound magnitude

	SineOscillator osc;		//declare oscillator to produce musical notes
	
	ofstream audioFile;		//declare a file to save sound
	audioFile.open("../sounds/"+music_name,ios::binary);//open file as binary
	wave_format(audioFile,channels,sampleRate,bitDepth);//dump initial settings of wav format
    
    //write the sound data(notes array) to file
	int i;		//notes[i][0]=musical note ;; notes[i][1]=how much note goes
	for(auto curr:example_msc1){
	
		osc=SineOscillator(noteMap[curr.first],amplitude);
		uretec(audioFile,osc, curr.second ,maxAmplitude);
	}
	
	wave_end_format(audioFile); //close file
	
    return 0;
    
}

//ınstrument class
class Instrument{
	public:
		string name="polyphonic instrument";
		
		SineOscillator alt1,alt2,alt3;
		Instrument(){}
		
		//DEPRECATED:: USE setStrings INSTEAD!!------------------
		Instrument(SineOscillator tel1,SineOscillator tel2,SineOscillator tel3){
			alt1=tel1;
			alt2=tel2;
			alt3=tel3;
		}
		//-------------------------------------------------------
		
	void setStrings(string note,float amplitude){
		
		int size=note.size()-1;
		
		int octave= stoi( note.substr(size) );//last char of string is frequency/octave
		note=note.substr(0,size);			 //remaining chars of string is note table
		
		alt1=SineOscillator(notalar[note][ to_string(octave) ],amplitude);//lower freq string
		alt2=SineOscillator(notalar[note][ to_string(octave+1) ],amplitude);;//higher
		alt3=SineOscillator(notalar[note][ to_string(octave+1) ],amplitude);;  //freqs strings
		
		//cout<<"size:"<<size<<" octave:"<<octave<<" note:"<<note<<endl;
	}
	
	void process(float duration,ofstream &audioFile){
	
		int i;
		float sum;
    	for(i=0;i<sampleRate*duration;i++){
    		sum=0;
			auto s1=alt1.process();
			auto s2=alt2.process();
			auto s3=alt3.process();
			
			sum=(s1+s2+s3)/3;
			int intSample2=static_cast<int> (sum*maxAmplitude);
			writeToFile(audioFile,intSample2,2);//2 means 2 bit(short)
		}
	}
};

//same notes with different harmony layers(octaves/frequencies..?) is homophony,i suppose
int homophony_example(string music_name){

	float amplitude=0.5;//sound magnitude
	
	Instrument instrument;
	
	ofstream audioFile;//declare a file to save sound
	audioFile.open("../sounds/"+music_name,ios::binary);//open file as binary
	wave_format(audioFile,channels,sampleRate,bitDepth);//dump initial settings of wav format
    
    
    //write the sound data(notes array) to file
	int i;
	for(auto curr:example_msc1){
		/*
		string n=curr.first;
		float f =curr.second;
		*/
		instrument.setStrings(curr.first,amplitude);
		instrument.process(curr.second,audioFile);
	}
	
	wave_end_format(audioFile);
	
	return 0;
}

int main(int argc, char** argv) {
	/*write an example sound.wav file and exit*/
    if(-1==monophony_example("monophonic_"+music_name)){
    	cout<<"monophonic failed. Beni bırak gideyim ağabey.\n";
    	return -1;
    }
    if(-1==homophony_example("homophonic_music.wav")){
    	cout<<"homophonic failed. Beni bırak gideyim ağabey.\n";
    	return -1;
    }
    return 0;
}

