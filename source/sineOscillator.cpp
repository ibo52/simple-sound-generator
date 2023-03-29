/*
 *halil ibrahim mut
 */
#include "../header/sineOscillator.h"
#include <math.h>

SineOscillator::SineOscillator(){
    this->angle=0.0f;
    this->frequency=440.1;
    this->amplitude=0.5;
    this->sampleRate=44100;
    
    this->offset=(2*M_PI*this->frequency /this->sampleRate);
    
}

SineOscillator::SineOscillator(float freq,float amp){
    this->frequency=freq;
    this->amplitude=amp;
    this->sampleRate=44100;
    
    this->offset=(2*M_PI*this->frequency /this->sampleRate);
}

float SineOscillator::process(){
    auto sample= this->amplitude*sin(this->angle);
    this->angle+=this->offset;
    return sample;
}