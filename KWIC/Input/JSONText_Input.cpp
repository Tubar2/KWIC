//
//  DBLP_Input.cpp
//  KWIC
//
//  Created by Gianlucas dos Santos on 06/10/19.
//  Copyright © 2019 Gianlucas dos Santos. All rights reserved.
//

#include "JSONText_Input.hpp"

//MARK: Constructor
JSON_Input::JSON_Input(LineStorage & data, type entryType)
:Input(data, entryType)
{
    
    string filename {"Resources/"}, line{}, filetype{};
    
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
    
    cout << "Enter JSON " << filetype << " file name: (no txt needed)" << endl;
    getline(cin, line);
    
    filename += line + ".JSON";
    
    filepath = filename;
    
    cout << "Created JSON_Input object for reading." << endl;
}

bool JSON_Input::setup()
{
    cout << "Setting up JSON Input enviroment." << endl;
    
    in_file.open(filepath);
    
    return in_file.is_open();
}

void JSON_Input::extractStops(){
    string line {};
    std::stringstream sstr;
    sstr << in_file.rdbuf();
    json j = json::parse(sstr.str());
    json o = j["stops"];
    for (auto it = o.begin(); it != o.end(); ++it)
    {
        data.stopWords.push_back(*it);
    }
}

//MARK: reachedEND
bool JSON_Input::reachedEND(){ //Check if eof was reached
    return in_file.eof();
}

//TODO
void JSON_Input::extractMain()
{
    std::cout << "Can't read titles from JSON file due to different possibilities of formats,"
        << "use DBLP_Input module" << std::endl;
    exit(17);
}

//MARK: finish
void JSON_Input::finish(){//Closes file
    in_file.close();
}
