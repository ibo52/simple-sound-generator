#include "example_music.h"

using namespace std;

//renewed musical note map(as hertz)
//starts form 4th octave(c1==octave 4)
map<string, map<string,float> > notalar={

	{"c",{  {"1",261.63},{"2",523.26},{"3",1046.5},{"4",2093.0} }},//do
	{"c#",{ {"1",277.18},{"2",554.36},{"3",1108.73},{"4",2217.46} }},//re
	{"d",{  {"1",293.66},{"2",587.32},{"3",1174.66},{"4",2349.32}  }},//..
	{"d#",{ {"1",311.13},{"2",622.26},{"3",1244.51},{"4",2489.02}  }},
	{"e",{  {"1",329.63},{"e2",659.26},{"3",1318.51},{"4",2637.02} }},
	{"f",{  {"1",349.23},{"2",698.46},{"3",1396.91},{"4",2793.83}  }},
	{"f#",{ {"1",369.99},{"2",739.98},{"3",1479.9},{"4",2959.96}   }},
	{"g",{  {"1",392.0},{"2",784.00},{"3",1567.98},{"4",3135.96} }},
	{"g#",{ {"1",415.3},{"2",830.6},{"3",1661.22},{"4",3322.44} }},
	{"a",{  {"1",440.0},{"2",880.0},{"3",1760.0},{"4",3520.0} }},
	{"a#",{ {"1",466.16},{"2",932.32},{"3",1864.66},{"4",3729.31} }},
	{"b",{  {"1",493.88},{"2",987.76},{"3",1975.53},{"4",3951.07} }},
	{".",{  {"1",44.1},{"2",88.2},{"3",132.3},{"4",264.6} }}//duraklama
};

//https://mixbutton.com/mixing-articles/music-note-to-frequency-chart/
	//musical note map(as hertz)
map<string,float> noteMap={
	{"c",261.63},//do
	{"c#",277.18},//re
	{"d",293.66},//..
	{"d#",311.13},
	{"e",329.63},
	{"f",349.23},
	{"f#",369.99},
	{"g",392.0},
	{"g#",415.3},
	{"a",440.0},
	{"a#",466.16},
	{"b",493.88},
	
	{"c2",523.26},
	{"c#2",554.36},
	{"d2",587.32},//..
	{"d#2",622.26},
	{"e2",659.26},
	{"f2",698.46},
	{"f#2",739.98},
	{"g2",784.0},
	{"g#2",830.6},
	{"a2",880.0},
	{"a#2",932.32},
	{"b2",987.76},
	
	{"c3",1046.5},
	{"c#3",1108.73},
	{"d3",1174.66},//..
	{"d#3",1244.51},
	{"e3",1318.51},
	{"f3",1396.91},
	{"f#3",1479.9},
	
	{".",0.0}//duraklama
	};
	
	//sample music coded. It is a folk song 
	//from the Tunceli region of Turkey
	string music_name="nenni bebek.wav";
	float notes[374][2]={
	{noteMap["f#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["f#2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["g#2"],0.1},
	{noteMap["c#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["g#2"],0.4},
	{noteMap["c#2"],0.1},
	
	{noteMap["g#2"],0.25},
	{noteMap["f#2"],0.25},
	{noteMap["c#2"],0.05},
	
	//mi fa sol la
	{noteMap["g#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["g#2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["c#3"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["c#3"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["g#2"],0.25},
	{noteMap["c#2"],0.05},
	{noteMap["f#2"],0.25},
	{noteMap["c#2"],0.05},
	
	//----yineleme oncesi ara ses->redo-redo
	{noteMap["f#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["e2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["f#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["e2"],0.1},
	{noteMap["."],0.05},
	//--------------
	//yineleme
	{noteMap["f#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["g#2"],0.4},
	{noteMap["c#2"],0.05},
	
	{noteMap["g#2"],0.1},
	{noteMap["c#2"],0.05},
	{noteMap["g#2"],0.1},
	{noteMap["c#2"],0.05},
	{noteMap["g#2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["g#2"],0.2},
	{noteMap["."],0.05},
	
	{noteMap["g#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["f#2"],0.1},
	{noteMap["c#2"],0.05},
	
	//mi fa sol la
	{noteMap["g#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["c#3"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["c#3"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["g#2"],0.25},
	{noteMap["c#2"],0.05},
	{noteMap["f#2"],0.25},
	{noteMap["c#2"],0.05},
	
	//düşüş >>son kısım
	//sol mire redo remi
	{noteMap["b2"],0.1},
	{noteMap["a#2"],0.1},
	{noteMap["b2"],0.25},
	
	{noteMap["g#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["f#2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["f#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["e2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["f#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["g#2"],0.25},
	{noteMap["."],0.05},
	
	//mi.. doresi dosi dore
	{noteMap["g#2"],0.25},
	{noteMap["."],0.05},
	{noteMap["g#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["g#2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["e2"],0.1},
	{noteMap["."],0.05},
	{noteMap["f#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["d#2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["e2"],0.1},
	{noteMap["."],0.05},
	{noteMap["d#2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["e2"],0.1},
	{noteMap["."],0.05},
	{noteMap["f#2"],0.25},
	{noteMap["."],0.05},
	
	//re. dosi sila sido
	{noteMap["f#2"],0.25},
	{noteMap["."],0.05},

	{noteMap["e#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["d#2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["d#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["c#2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["d#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["e2"],0.25},
	{noteMap["."],0.05},
	//dosido si-la si-si lala
	{noteMap["e2"],0.05},
	{noteMap["d#2"],0.05},
	{noteMap["e2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["d#2"],0.25},
	{noteMap["."],0.05},
	{noteMap["c#2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["d#2"],0.25},
	{noteMap["."],0.05},
	{noteMap["d#2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["c#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["c#2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["c#2"],0.25},
	{noteMap["."],0.05},
	{noteMap["f#2"],0.25},
	{noteMap["."],0.05},
	{noteMap["c#2"],0.4},
	{noteMap["."],0.05},
	
	//deyiş kısmı
	//fa sol la-la
	{noteMap["a#2"],0.25},
	{noteMap["."],0.05},
	{noteMap["b2"],0.25},
	{noteMap["."],0.05},
	{noteMap["c#3"],0.4},
	{noteMap["."],0.05},
	{noteMap["c#3"],0.4},
	{noteMap["."],0.05},
	//la do si la-la
	{noteMap["c#3"],0.4},
	{noteMap["."],0.05},
	{noteMap["e3"],0.1},
	{noteMap["."],0.05},
	{noteMap["d#3"],0.25},
	{noteMap["."],0.05},
	{noteMap["c#3"],0.25},
	{noteMap["."],0.05},
	{noteMap["c#3"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["b2"],0.1},
	{noteMap["a#2"],0.05},
	{noteMap["b2"],0.25},
	
	//la fa sol fa...x3
	{noteMap["c#3"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["c#3"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	
	
	{noteMap["c#3"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["b2"],0.4},
	{noteMap["."],0.05},
	{noteMap["c#3"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.4},
	{noteMap["."],0.05},
	
	//ara geçiş
	{noteMap["b2"],0.25},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	
	//gitti beşiğe dayandı
	{noteMap["a#2"],0.25},
	{noteMap["."],0.05},
	{noteMap["b2"],0.25},
	{noteMap["."],0.05},
	{noteMap["b2"],0.4},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	
	{noteMap["b2"],0.4},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	
	{noteMap["c#3"],0.25},
	{noteMap["."],0.05},
	
	//solla fasol mi- re-
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["c#3"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["g#2"],0.25},
	{noteMap["c#2"],0.05},
	{noteMap["f#2"],0.25},
	{noteMap["c#2"],0.05},
	
	//bebek uykudan uyandı
	{noteMap["c#3"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["b2"],0.25},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	
	{noteMap["b2"],0.25},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["c#3"],0.25},
	{noteMap["."],0.05},
	//düşüs solla fasol mi- re-
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["c#3"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["g#2"],0.25},
	{noteMap["c#2"],0.05},
	{noteMap["f#2"],0.25},
	{noteMap["c#2"],0.05},
	
	// ağıt la(sol yerine) nenni oğul
	{noteMap["c#3"],0.4},
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.4},
	{noteMap["."],0.05},
	{noteMap["a#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["g#2"],0.4},
	
	{noteMap["."],0.05},
	{noteMap["b2"],0.1},
	{noteMap["."],0.05},
	{noteMap["g#2"],0.4},
	
	//BİTİŞ....
	{noteMap["b2"],0.1},
	{noteMap["a#2"],0.1},
	{noteMap["b2"],0.25},
	
	{noteMap["g#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["f#2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["f#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["e2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["f#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["g#2"],0.25},
	{noteMap["."],0.05},
	
	//mi.. doresi dosi dore
	{noteMap["g#2"],0.25},
	{noteMap["."],0.05},
	{noteMap["g#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["g#2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["e2"],0.1},
	{noteMap["."],0.05},
	{noteMap["f#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["d#2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["e2"],0.1},
	{noteMap["."],0.05},
	{noteMap["d#2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["e2"],0.1},
	{noteMap["."],0.05},
	{noteMap["f#2"],0.25},
	{noteMap["."],0.05},
	
	//re. dosi sila sido
	{noteMap["f#2"],0.25},
	{noteMap["."],0.05},

	{noteMap["e#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["d#2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["d#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["c#2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["d#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["e2"],0.25},
	{noteMap["."],0.05},
	//dosido si-la si-si lala
	{noteMap["e2"],0.05},
	{noteMap["d#2"],0.05},
	{noteMap["e2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["d#2"],0.25},
	{noteMap["."],0.05},
	{noteMap["c#2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["d#2"],0.25},
	{noteMap["."],0.05},
	{noteMap["d#2"],0.1},
	{noteMap["."],0.05},
	
	{noteMap["c#2"],0.1},
	{noteMap["."],0.05},
	{noteMap["c#2"],0.25},
	{noteMap["."],0.05},
	
	{noteMap["c#2"],0.25},
	{noteMap["."],0.05},
	{noteMap["f#2"],0.25},
	{noteMap["."],0.05},
	{noteMap["c#2"],0.4},
	{noteMap["."],0.05}
	
	};
