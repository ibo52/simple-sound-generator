/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "../header/noteReader.h"

#include<fstream>
#include<string>
#include <iostream>
#include<utility>	//for pair
#include<vector>	//for vector
using namespace std;

NoteReader::NoteReader(string filePath){
    this->file.open(filePath);
}

void NoteReader::readToBuffer(){
    
    string line;
    
    if(this->file.is_open()){
        
        while(getline(this->file, line)){
            
            short idx=line.find(":");
            
            string note=line.substr(0,idx);
            float duration=stof( line.substr(idx+1) );//turn string to float
            
            pair<string,float> p={note,duration};
            this->notes.insert(this->notes.end(), p );
            
        }
        this->file.close();
    }
    else{
        cout<<"unable to open file!";
    }
}