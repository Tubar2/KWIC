//
//  DBLP_Input.cpp
//  KWIC
//
//  Created by Gianlucas dos Santos on 06/10/19.
//  Copyright © 2019 Gianlucas dos Santos. All rights reserved.
//

#include "JSONText_Input.hpp"

//MARK: Constructors
JSON_Input::JSON_Input(std::string name, LineStorage & data, type entryType) //3Args Constructor
:Input(name, data, entryType){
    
}

JSON_Input::JSON_Input(LineStorage & data, type entryType) //2 Args Constructor
:Input(data, entryType)
{
    
    std::string filename {"Resources/"}, line{}, filetype{};
    
    switch (entryType) {
        case typeStops:
            filetype = "stops";
            break;
        case typeInput:
            filetype = "input";
            break;
        default:
            break;
    }
    
    std::cout << "Enter json " << filetype << " file name: (no .json needed)" << std::endl;
    getline(std::cin, line);
    
    filename += line + ".json";
    
    filepath = filename;
    
    std::cout << "Created JSON_Input object for reading." << std::endl;
}

//MARK: setup
bool JSON_Input::setup()
{
    std::cout << "Setting up JSON Input enviroment." << std::endl;
    
    in_file.open(filepath);
    
    return in_file.is_open();
}

//MARK: extractMain
void JSON_Input::extractMain()
{
    throw "Can't read titles from JSON.";
}

//MARK: extractStops
void JSON_Input::extractStops(){
    std::string line {};
    std::stringstream sstr;
    sstr << in_file.rdbuf();
    json j = json::parse(sstr.str());
    json o = j["stops"];
    for (auto it = o.begin(); it != o.end(); ++it)
    {
        data.stopWords.push_back(*it);
    }
}

//MARK: finish
void JSON_Input::finish(){//Closes file
    in_file.close();
}

//MARK: reachedEND
bool JSON_Input::endReached(){ //Check if eof was reached
    return in_file.eof();
}
