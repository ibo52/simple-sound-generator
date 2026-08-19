/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Instruments.h"
#include <list>
#include <example_music.h>
#include<algorithm>
#include<iostream>

Instrument::Instrument(){

        this->oscillators = {
        SineOscillator(440.0f, 0.5, 1.0),
        SineOscillator(440.0f, 0.15, 0.1571428),
        SineOscillator(440.0f, 0.15, 2.0),
        SineOscillator(440.0f, 0.15, 0.3141592),
        SineOscillator(440.0f, 0.05, 1.7142856)
    };
}

Instrument::Instrument(list<SineOscillator> oscillator_list){
                this->oscillators=oscillator_list;
}

void Instrument::setNote(float freq,float amplitude){

    int idx=1;
    for (SineOscillator &element: oscillators){

        element.setFreq(freq*idx++);
    }
}

void Instrument::setNote(string note,float amplitude){

        int size=note.size()-1;

        int octave= stoi( note.substr(size) );//last char of string is frequency/octave
        note=note.substr(0,size);			 //remaining chars of string is note table

        float mainNote=notalar[note][ to_string(octave) ];

        int idx=1;
        for (SineOscillator &element:oscillators)
        {
            element.setFreq(mainNote*idx++);//lower freq string
        }
}

void Instrument::process(float duration,WaveFormatter &f){
    
    int i;
    float sum;

    for(i=0; i< f.sampleRate *duration; i++){
        sum=0.0f;
        
        for (SineOscillator& element : oscillators)
        {
            sum += element.process();
        }

        sum/= static_cast<float>(this->oscillators.size());
        
        int intSample2=static_cast<int> (sum * f.maxAmplitude);
        
        f.write(intSample2,2);// 2 bytes(short)
    }
}