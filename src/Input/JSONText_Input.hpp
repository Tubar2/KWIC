//
//  JSON_Input.hpp
//  KWIC
//
//  Created by Gianlucas dos Santos on 06/10/19.
//  Copyright © 2019 Gianlucas dos Santos. All rights reserved.
//

#ifndef JSON_INPUT_H
#define JSON_INPUT_H

//This class reads stop words from a JSON file in this specific format "{"stops" : ["word1", "word2", ... ]}"

#include "I_Input.hpp"
#include "Input.hpp"
#include "../LineStorage.hpp"

#include <iostream>
#include <memory>
#include "../single_include/nlohmann/json.hpp"

using json = nlohmann::json;

class JSON_Input : public Input{
private:
    std::vector<std::string> all_titles_vector;
    int title_iterator;
    int title_count;

    //MARK: Overriden function
    bool setup() override;  //Opens url
    void extractStops() override; //Extracts all stop words in a vector<string>
    void extractMain() override; // Cant be used
    bool endReached() override; // return true when all titles in all_titles_vector have been accessed
    void finish() override;//Closes file

public:
    std::ifstream in_file {};

    //MARK: Constructors
    JSON_Input(std::string name, LineStorage & data, type entryType); //3 Args Constructor
    JSON_Input(LineStorage & data, type entryType); //2 Args Constructor

    //MARK: Destructor
    virtual ~JSON_Input() = default;

};
#endif
