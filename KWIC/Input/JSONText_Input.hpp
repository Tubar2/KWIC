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
public:
    std::ifstream in_file {};

    //MARK: Constructor
    JSON_Input(std::string filepath, LineStorage & data, type entryType);

    //MARK: Setup
    bool setup() override;

    void extractStops() override; //Extracts all stop words in a vector<string>

    // Cant be used
    void extractMain() override; 

    // return true when all titles in all_titles_vector have been accessed
    bool reachedEND() override;

    //MARK: finish
    void finish() override;//Closes file

    //MARK: Destructor
    virtual ~JSON_Input() = default;

private:
    std::vector<std::string> all_titles_vector;
    int title_iterator;
    int title_count;

};
#endif
