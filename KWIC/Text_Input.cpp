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
void Text_Input::setup(){
    Input::setup();
    cout << "Setting up Text Input enviroment." << endl;
    
    setupReading();
}

//MARK: setupReading
void Text_Input::setupReading(){ //Opens file for reading
    in_file.open(filename);
    
    if(!in_file.is_open()){  //Checks if file was opened succesfully
        cout << "Couldn't open file." << endl;
        exit(1);
    }
    else {
        cout << "File opened succesfully." << endl;
    }
    
}

//MARK: reachedEOF
bool Text_Input::reachedEOF(){ //Check if eof was reached
    return in_file.eof();
}

//MARK: extractors
void Text_Input::extract(entryType typeEntry){
    switch (typeEntry) {
        case typeStops:
            cout << "Extracting stop words" << endl;
            extractStops();
            cout << "Extracted " << data.storedStops() << " words" << endl;
            break;
        case typeInput:
            cout << "Extracting line from main program" << endl;
            extractMain();
        break;
            
        default:
            exit(2);
            break;
    }
}

//TODO: Implement extractors
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

    while (!in_file.eof()) {
        getline(in_file, line);
        data.stopWords.push_back(line);
    }
}

//MARK:
void Text_Input::closeFile(){
    in_file.close();
}

//MARK: Constructor
Text_Input::Text_Input(string filename, LineStorage & data)
:Input(filename, ".txt", data)
{
    cout << "Created Text_Input object for reading." << endl;
    
}

//MARK: Interface function Override
void Text_Input::read(LineStorage & data) const {
    cout << "Read function called in Text_Input." << endl;
}
