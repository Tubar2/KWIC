#ifndef DBLP_INPUT_H
#define DBLP_INPUT_H


//This class uses cURL library to access DBLP api and search for a query returning a json string.
//The string is used with the json library to extract all titles and store them in a vector of strings.

#include "I_Input.hpp"
#include "Input.hpp"
#include "LineStorage.hpp"

#include <iostream>
#include <memory>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class DBLP_Input : public Input{
public:

    //MARK: Constructor
    DBLP_Input(string query, LineStorage & data);

    //TODO: Essa função não faz nada - deletar ou procurar alguma utilidade.
    virtual void read(LineStorage & data) const override;

    //MARK: Setup
    virtual void setup() override;

    //Extracts line : delimiter '\n'
    void extract();

    // return true when all titles in all_titles_vector have been accessed
    bool reachedEND();

    //MARK: Destructor
    virtual ~DBLP_Input() = default;


private:

    std::vector<std::string> all_titles_vector;
    int title_iterator;
    int title_count;

    // write the data into a `std::string`
    static std::size_t write_data(void* buf, std::size_t size, std::size_t nmemb, void* userp);

    // A deleter to use in the smart pointer for automatic cleanup
    struct curl_dter{void operator()(CURL* curl) const
        { if(curl) curl_easy_cleanup(curl); }};

    // A smart pointer to automatically clean up out CURL session
    using curl_uptr = std::unique_ptr<CURL, curl_dter>;

    // download the URL into a `std::string`.
    std::string get_url(std::string const& url);

    // search for query in DBLP api and stores all titles in a vector of strings
    void search_and_store();
};

#endif