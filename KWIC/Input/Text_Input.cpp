//
//  Text_Input.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "Text_Input.hpp"

using namespace std;

//MARK: setup
bool Text_Input::setup(){
    cout << "Setting up Text Input enviroment." << endl;
    
    in_file.open(filepath);
    
    return in_file.is_open();
}

//MARK: reachedEND
bool Text_Input::reachedEND(){ //Check if eof was reached
    return in_file.eof();
}

//MARK: Extractors
void Text_Input::extractMain(){  //Extracts line : delimiter '\n'
    string line {};
    
    getline(in_file, line);
    data.wholeOriginalLine = line;
    
    string tempWord {};
    for (auto c : line) {
        if (c == ' ') {
            data.originalLine.push_back(tempWord);
            tempWord = "";
        }
        else{
            tempWord += c;
        }
    }
    data.originalLine.push_back(tempWord);
}

void Text_Input::extractStops(){
    string line {};

    while (!reachedEND()) {
        getline(in_file, line);
        data.stopWords.push_back(line);
    }
}

//MARK: Finish
void Text_Input::finish(){
    in_file.close();
    
}

//MARK: Constructor
Text_Input::Text_Input(string filename, LineStorage & data, type entryType)
:Input(filename, data, entryType)
{
    cout << "Created Text_Input object for reading." << endl;
    
}

