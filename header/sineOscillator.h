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

class SineOscillator{//Produce sinuse waves (representation of sounds)
public:
    float frequency,amplitude,angle,offset;
    int sampleRate;

    SineOscillator();
    SineOscillator(float freq,float amp);
    
    float process();
};


#endif /* SINEOSCILLATOR_H */

