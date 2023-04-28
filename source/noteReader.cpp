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
#include <stdlib.h>     /* exit, EXIT_FAILURE */
using namespace std;

NoteReader::NoteReader(string filePath){
    this->file.open(filePath);
}

void NoteReader::readToBuffer(){
    
    string line;
    
    if(this->file.is_open()){
        
        while(getline(this->file, line)){
        
            short skip=line.find(";");//skip comma lines
            if(skip!=-1){
            
            	line=line.substr(0,skip);
            }
            
            short idx=line.find(":");
            if(idx!=-1){
            
            	string note=line.substr(0,idx);
            	float duration=stof( line.substr(idx+1) );//turn string to float
            
            	pair<string,float> p={note,duration};
            	this->notes.insert(this->notes.end(), p );
            }
            
        }
        this->file.close();
    }
    else{
        cout<<"NoteReader: Unable to open file!\n";
        cout<<"Path is wrong or does not exists.\n";
        exit(EXIT_FAILURE);
    }
}
