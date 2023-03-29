/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   instruments.h
 * Author: ibrahim
 *
 * Created on March 25, 2023, 10:18 AM
 */

#ifndef INSTRUMENTS_H
#define INSTRUMENTS_H
#include <cstdlib>
#include<string>

#include "../header/sineOscillator.h"
#include "../header/wave_settings.h"
#include "../header/example_music.h"
using namespace std;

class Instrument{
public:
    string name;

    SineOscillator alt1,alt2,alt3;
    Instrument();
    Instrument(SineOscillator tel1,SineOscillator tel2,SineOscillator tel3);

    void setStrings(string note,float amplitude);

    void process(float duration,WaveFormatter &f);
};

#endif /* INSTRUMENTS_H */

