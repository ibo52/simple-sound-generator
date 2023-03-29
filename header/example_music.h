#ifndef EXAMPLE_MUSIC
#define EXAMPLE_MUSIC "example_music.h"

#include<map>		//hashmap for notes
#include<string>	//use instead char* to surpass warnings
#include<utility>	//for pair
#include<vector>	//for vector
 
using namespace std;

//new definition of note frequency table
extern map<string, map<string,float> > notalar;

extern map<string,float> noteMap;

extern string music_name;

extern vector< pair<string,float> > example_msc1;

#endif
