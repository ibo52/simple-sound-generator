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
#include "../header/example_music.h" //example music code to listen
#include "../header/wave_settings.h" //settings for wave file format
#include "../header/sineOscillator.h"
#include "../header/instruments.h"
#include "../header/noteReader.h"


#include <cstdlib>
#include<iostream>
#include<math.h>	//required to use pi value
#include<fstream>	//file operations
using namespace std;
/*
 * 
 */
const int sampleRate=44100;	 //Period. CD quality.(defines how many waves will be at a second)
const int bitDepth=16;		//bits per sample.(16 as wave file standard)
const int channels=1;	   // mono/stereo setting of sound
auto maxAmplitude=(2<<(bitDepth-1))-1;

//write to file note's oscillation and duration of that note(how much seconds will it play)
void uretec(WaveFormatter &f,SineOscillator &so2,float duration,double maxAmplitude){
    
    int i;
    for(i=0;i<sampleRate*duration;i++){
        auto sample2=so2.process();
        int intSample2=static_cast<int> (sample2*maxAmplitude);
        
        f.write( intSample2,2);
           
    }  
}

//monophonic sound: just one harmony layer(octave) that plays notes, i suppose
int monophony_example(string music_name){
    
	float amplitude=0.5;	//sound magnitude

	SineOscillator osc;		//declare oscillator to produce musical notes
	
	WaveFormatter Wave=WaveFormatter(music_name);//waveformatter class creates a file
    
    //write the sound data(notes array) to WaveFormatter class' file
	int i;		//notes[i][0]=musical note ;; notes[i][1]=how much note goes
	for(pair<string,float> curr:example_msc1){
            
            string note=curr.first;
            int size=note.size()-1;
            int octave= stoi( note.substr(size) );//last char of string is frequency/octave
            note=note.substr(0,size);		  //remaining chars of string is note table
            
            osc=SineOscillator(notalar[note][ to_string(octave) ],amplitude);
            uretec(Wave, osc, curr.second ,maxAmplitude);
	}
	
	Wave.close(); //close file
	
    return 0;
    
}

//same notes with different harmony layers(octaves/frequencies..?) is homophony,i suppose
int homophony_example(string music_name){

	float amplitude=0.5;//sound magnitude
	
	Instrument instrument;
	
        WaveFormatter Wave=WaveFormatter(music_name);//waveformatter class creates a file
    
    
    //write the sound data(notes array) to file
	int i;
	for(pair<string,float> curr:example_msc1){

		instrument.setStrings(curr.first,amplitude);
		instrument.process(curr.second,Wave);
	}
	
	Wave.close();
	
	return 0;
}


int main(int argc, char** argv) {
    
    int i;
    string in;
    string out;
    
    if(argc==1){
        cout<<"sample musics generating..";
        /*write an example sound.wav file and exit*/
        if(0!=monophony_example("monophonic_"+music_name)){
            cout<<"monophonic failed. Beni bırak gideyim ağabey.\n";
            return -1;
        }
        if(0!=homophony_example("homophonic_"+music_name)){
            cout<<"homophonic failed. Beni bırak gideyim ağabey.\n";
            return -1;
        }
        cout<<"Done\n"<<endl;
        
       return 0;
    }else{
    
        for(i=1;i<argc;i++){

            if(argv[i][0]=='-'){

                switch(argv[i][1]){
                    case 'o': out=argv[i+1];continue;
                    case 'i': in=argv[i+1];continue;
                    case 'h': printf("%s [options]\n"
                    "OPTIONS:\n"
                    "\t-h :print this and exit\n"
                    "\t-i [path]:input file path\n"
                    "\t-o [path]:output file path\n",argv[0]);exit(0);
                }
            }
        }
        if(in.empty()){
            cerr<<"no input file specified!!"<<endl;
            return -1;
        }else if(out.empty()){
            out="msc_out.wav";
        }
        cout<<"Compile from path:"<<in<<endl;
    
		NoteReader nr=NoteReader(in);
		nr.readToBuffer();
		
		example_msc1=nr.notes;
		
		cout<<"sample compiling to generate music..";
		if(0!=monophony_example(out)){
		        cout<<"monophonic failed. Beni bırak gideyim ağabey.\n";
		        return -1;
		    }
		    if(0!=homophony_example(out)){
		        cout<<"homophonic failed. Beni bırak gideyim ağabey.\n";
		        return -1;
		    }
		
		cout<<"Done\n"<<endl;
		cout<<"saved to:"<<out<<endl;
    }
    return 0;
}

