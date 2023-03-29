/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../header/instruments.h"

Instrument::Instrument(){
                    this->alt1=SineOscillator();
                    this->alt1=SineOscillator();
                    this->alt1=SineOscillator();
                }

Instrument::Instrument(SineOscillator tel1,SineOscillator tel2,SineOscillator tel3){
                this->alt1=tel1;
                this->alt2=tel2;
                this->alt3=tel3;
        }

void Instrument::setStrings(string note,float amplitude){

        int size=note.size()-1;

        int octave= stoi( note.substr(size) );//last char of string is frequency/octave
        note=note.substr(0,size);			 //remaining chars of string is note table

        this->alt1=SineOscillator(notalar[note][ to_string(octave) ],amplitude);//lower freq string
        this->alt2=SineOscillator(notalar[note][ to_string(octave+1) ],amplitude);;//higher
        this->alt3=SineOscillator(notalar[note][ to_string(octave+1) ],amplitude);;  //freqs strings
}

void Instrument::process(float duration,WaveFormatter &f){
    
    int i;
    float sum;
    for(i=0; i< this->alt1.sampleRate*duration; i++){
        sum=0;
        auto s1=this->alt1.process();
        auto s2=this->alt2.process();
        auto s3=this->alt3.process();

        sum=(s1+s2+s3)/3;
        int intSample2=static_cast<int> (sum*32767);
        f.write(intSample2,2);// 2 bytes(short)
    }
}