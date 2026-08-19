/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   noteReader.h
 * Author: ibrahim
 *
 * Created on March 25, 2023, 12:16 PM
 */

#ifndef NOTEREADER_H
#define NOTEREADER_H

#include<fstream>
#include<string>
#include<utility>	//for pair
#include<vector>	//for vector

class NoteReader{
public:
    std::ifstream file;
    std::vector< std::pair<std::string,float> > notes;

public:
    NoteReader(std::string filePath);
    void readToBuffer();
};



#endif /* NOTEREADER_H */

