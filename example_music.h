#ifndef EXAMPLE_MUSIC
#define EXAMPLE_MUSIC "example_music.h"

#include<map>
#include<string>
using namespace std;

//new definition of note frequency table
extern map<string, map<string,float> > notalar;

extern map<string,float> noteMap;

extern string music_name;

extern float notes[374][2];

#endif
