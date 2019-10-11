//
//  Input.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 06/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "Input.hpp"

//MARK: Constructors
Input::Input(std::string filepath, LineStorage & data, type entryType) //3 Args Constructor
: entryType(entryType), filepath(filepath), data(data) {
}

Input::Input(LineStorage & data, type entryType) //2 Args Contructor
: entryType(entryType), data(data){
    
}

//MARK: Open
void Input::open(){
    std::cout << "Trying to open." << std::endl;
    
    if(setup()){
        std::cout << "Open() successfully executed." << std::endl;
    }
    else{
        std::cout << "Open() unsuccessful." << std::endl;
        throw "Error opening.";
    }
}

//MARK: Extract
void Input::extract(){
    switch (entryType) {
        case typeStops:
            std::cout << "Extracting stop words" << std::endl;
            extractStops();
            std::cout << "Extracted " << data.storedStops() << " words" << std::endl;
            break;
        case typeInput:
            /// std::cout << "Extracting line from main program" << std::endl;
            extractMain();
        break;
            
        default:
        throw "Invalid type extraction";
            break;
    }
}

//MARK: Close
void Input::close(){
    std::cout << "Closing.." << std::endl;
    
    finish();
}

//MARK: reachedEND
bool Input::reachedEND(){

    return endReached();
}
