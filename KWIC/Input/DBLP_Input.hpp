//
//  DBLP_Input.hpp
//  KWIC
//
//  Created by Gianlucas dos Santos on 06/10/19.
//  Copyright © 2019 Gianlucas dos Santos. All rights reserved.
//

#ifndef DBLP_INPUT_H
#define DBLP_INPUT_H


//This class uses cURL library to access DBLP api and search for a query returning a json string.
//The string is used with the json library to extract all titles and store them in a vector of strings.
//This module can't be used to read stopwords

#include "I_Input.hpp"
#include "Input.hpp"
#include "../LineStorage.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <curl/curl.h>
#include "../single_include/nlohmann/json.hpp"

using json = nlohmann::json;

class DBLP_Input : public Input{
private:
    std::vector<std::string> all_titles_vector;
    int title_iterator;
    int title_count;

    // write the data into a `std::string`
    static std::size_t write_data(void* buf, std::size_t size, std::size_t nmemb, void* userp);

    // A deleter to use in the smart pointer for automatic cleanup
    struct curl_dter{void operator()(CURL* curl) const
        { if(curl) curl_easy_cleanup(curl); }};

    using curl_uptr = std::unique_ptr<CURL, curl_dter>;// A smart pointer to automatically clean up out CURL session
    
    std::string get_url(std::string const& url);       // Download the URL into a `std::string`.

    //MARK: Overriden functions
    bool setup() override;
    void extractStops() override; //Extracts all stop words in a std::vector<std::string>
    void extractMain() override; // search for query in DBLP api and stores all titles in a vector of strings
    void finish() override;//Closes file
    bool endReached() override;// return true when all titles in all_titles_vector have been accessed

public:

    //MARK: Constructor
    DBLP_Input(std::string search, LineStorage & data, type entryType); //3 Args Constructor
    DBLP_Input(LineStorage & data, type entryType); //2 Args Construcotr
    //MARK: Destructor
    virtual ~DBLP_Input() = default;
};

#endif
