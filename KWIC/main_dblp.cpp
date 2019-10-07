//
//  main.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <algorithm>

#include "CircularShifter.hpp"
#include "Alphabetizer.hpp"
#include "LineStorage.hpp"
#include "Output/Text_Output.hpp"
#include "Input/Text_Input.hpp"
#include "Input/DBLP_Input.hpp"

using namespace std;

void printVector(vector<string> myvector);
string createFilepath();

int main(int argc, const char * argv[]) {
    
    string filepath = createFilepath();
    
    //Definig both types of enums
    type stops = typeStops;
    type inputs = typeInput;
    
    //Creating Line Storage
    LineStorage data;
    
    //Creating and setting up new Input objects
    DBLP_Input input("test", data, inputs);
    Text_Input words("Resources/mystops.txt", data, stops);
    input.open();
    words.open();
    
    //Extracting stop Words then closing reader
    words.extract();
    words.close();
    
    //Creating CircularShifter object pointer
    CircularShifter * cs = new CircularShifter(data.originalLine_Vector);
    
    //Creating alphabetizer object pointer
    Alphabetizer * alph = new Alphabetizer(data);
    
    //Creating output object
    Text_Output to(filepath, data.shiftedVariations);
    
    to.createFile();
    
    //Extracting text 1 line at a time
    do {
        data.deletePrevInfo();
        input.extract();      //One line extraction
        
        //Creating all shifts for stored line
        data.shiftedVariations = cs->makeCircularShifts();
        cout << "Shifts made: " << data.storedLines() << endl;
        
        //Removing stops and alphabetizing
        alph->removeStops();
        alph->alphabetiseData();
        
        to.printOutput();
        
    } while (!input.reachedEND());
    
    //Deleting pointers
    delete cs;
    delete alph;
    
    //Closing
    to.closeFile();
    input.close();
    
    return 0;
}

//MARK: printVector
void printVector(vector<string> myvector){
    for (auto mystr : myvector) {
        cout << mystr << endl;
    }
}

//MARK: createFileath
string createFilepath(){
    string filepath {"Exits/"}, line{};
    cout << "Enter output file name: (no txt needed)" << endl;
    getline(cin, line);
    
    filepath += line + ".txt";
    
    return filepath;
}
