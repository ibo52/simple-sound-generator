/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sineOscillator.h
 * Author: ibrahim
 *
 * Created on March 24, 2023, 11:25 PM
 */

#ifndef SINEOSCILLATOR_H
#define SINEOSCILLATOR_H
#include <math.h>

class SineOscillator{//Produce sinuse waves (representation of sounds)
public:

    int sampleRate=44100; // CD quality
    
    float frequency=440.1
    ,amplitude=0.5
    ,angle=0.0
    ,offset=(2 * M_PI * frequency / sampleRate);

    float tuneCoeff=1.0;
    

    SineOscillator();
    SineOscillator(float freq,float amp);
    SineOscillator(float freq,float amp, float tune_coeff);
    
    void setFreq(float freq);

    void setFreqNAmp(float freq, float amp);

    void setTuneCoefficient(float coeff);
    
    float process();
};


#endif /* SINEOSCILLATOR_H */

