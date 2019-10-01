//
//  Input.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "Input.hpp"
using namespace std;

Input::Input(string name, string stops)
:filename(name), stopWordsFilename(stops)
{
    cout << "Input object created: \nFilename = " << name <<
            "\nstopWordsFilename = " << stops << endl;
}

void Input::setupReading(){
    in_file.open(filename);
    stopWords.open(stopWordsFilename);
    
    if(!in_file.is_open()){
        cout << "Couldn't open main file." << endl;
        exit(1);
    }
    else if(!stopWords.is_open()){
        cout << "Couldn't open stop words file." << endl;
        exit(1);
    }
    else {
        cout << "Files opened succesfully." << endl;
    }
    
}
    
void Input::extractLine(){
    string line {};
    getline(in_file, line, '.');
    
    string tempWord {};
    for (auto c : line) {
        
        if (c == ' ' /*|| c == ',' || c == ';' || c == ':'*/) {
            data.originalLine.push_back(tempWord);
            tempWord = "";
//            if (c == ',' || c == ';' || c == ':') {
//                tempWord += c;
//                data.originalLine.push_back(tempWord);
//                tempWord = "";
//            }
        }
        else{
            tempWord += c;
        }
    }
}

void Input::extractWords(){
    string line {};
    
    while (!stopWords.eof()) {
        getline(stopWords, line);
        data.stopWords.push_back(line);
    }
}

bool Input::reachedEOF(){
    return in_file.eof();
}

void Input::read(istream &is) const{
    cout << "Read function called in Input" << endl;
}
