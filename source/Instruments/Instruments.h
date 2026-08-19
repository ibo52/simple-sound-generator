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
#include<list>

#include "SineOscillator.h"
#include "WaveFormatter.h"
#include "example_music.h"
using namespace std;

class Instrument{
public:
    string name="base instrument";

    list<SineOscillator> oscillators;

    Instrument();
    Instrument(list<SineOscillator> oscillators_list);

    void setNote(string note,float amplitude);

    void setNote(float freq, float amplitude);

    void process(float duration, WaveFormatter &file);
};

#endif /* INSTRUMENTS_H */

