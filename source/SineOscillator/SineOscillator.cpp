/*
 *halil ibrahim mut
 */
#include "SineOscillator.h"
#include <math.h>

SineOscillator::SineOscillator():SineOscillator(440.1, 0.5){
        
}

SineOscillator::SineOscillator(float freq,float amp): SineOscillator(freq, amp, 1.0){
}

SineOscillator::SineOscillator(float freq,float amp, float tune_coeff){
    this->frequency=freq;
    this->amplitude=amp;
    this->tuneCoeff=tune_coeff;
    
    this->offset=(2*M_PI*this->frequency /this->sampleRate);
}

float SineOscillator::process(){
    
    float sample = this->amplitude*sin(this->angle) * this->tuneCoeff;
    this->angle+=this->offset;

    if (angle >= 2.0f * M_PI)
        angle -= 2.0f * M_PI;
    
    return sample;
}

void SineOscillator::setFreq(float freq){
    
    this->frequency=freq;

    this->offset=(2*M_PI*this->frequency /this->sampleRate);
}

void SineOscillator::setFreqNAmp(float freq, float amp){
    
    this->frequency=freq;
    this->amplitude=amp;

    this->offset=(2*M_PI*this->frequency /this->sampleRate);
}

void SineOscillator::setTuneCoefficient(float coeff){
    this->tuneCoeff=coeff;
}