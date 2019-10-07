//
//  DBLP_Input.cpp
//  KWIC
//
//  Created by Gianlucas dos Santos on 06/10/19.
//  Copyright © 2019 Gianlucas dos Santos. All rights reserved.
//

#include "DBLP_Input.hpp"

//MARK: Constructor
DBLP_Input::DBLP_Input(string query, LineStorage & data, type entryType)
:Input(query, data, entryType)
{
    cout << "Created DBLP_Input object for reading." << endl;
}

//MARK: Setup
bool DBLP_Input::setup(){
    // query is the desired search paramter
    std::string query = Input::filepath;

    // bufilepathrl
    std::string url;
    url.append("https://dblp.org/search/publ/api?q=");
    url.append(query);
    url.append("&format=json&h=10");
    std::cout << url << std::endl;
    
    // store json file from url into variable j
    json j = json::parse(get_url(url));
    
    // reaching the part where the articles are stored
    json o = j["result"]["hits"]["hit"];

    std::string str;

    // iterating through articles and colecting titles
    for (auto it = o.begin(); it != o.end(); ++it)
    {
        str = (*it)["info"]["title"];
        all_titles_vector.insert(all_titles_vector.end(),str);

    }
    title_count = static_cast<int>(all_titles_vector.size());
    title_iterator = 0;
    

    return true;
}
//Extracts line : delimiter '\n'
void DBLP_Input::extractMain(){  
    string line;
    
    line = all_titles_vector.at(title_iterator);
    data.originalLine_String = line;
    
    string tempWord {};
    for (auto c : line) {
        if (c == ' ') {
            data.originalLine_Vector.push_back(tempWord);
            tempWord = "";
        }
        else{
            tempWord += c;
        }
    }
    data.originalLine_Vector.push_back(tempWord);

    title_iterator++;
}

// TODO
void DBLP_Input::extractStops(){
    std::cout << "can't extract stop words from dblp site" << std::endl;
    exit(15);
}

bool DBLP_Input::reachedEND() {
    if (title_iterator == title_count)
    {
        return true;
    }
    return false;
}

void DBLP_Input::finish() {
    std::cout << "Closing DBLP_Input resources" << std::endl;
}

std::size_t DBLP_Input::write_data(void* buf, std::size_t size, std::size_t nmemb, void* userp)
{
if(auto sp = static_cast<std::string*>(userp))
{
    sp->append(static_cast<char*>(buf), size * nmemb);
    return size * nmemb;
}
return 0;
}


// download the URL into a `std::string`.
std::string DBLP_Input::get_url(std::string const& url)
{
    std::string data;

    if(auto curl = curl_uptr(curl_easy_init()))
    {
        curl_easy_setopt(curl.get(), CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl.get(), CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, &data);

        CURLcode ec;
        if((ec = curl_easy_perform(curl.get())) != CURLE_OK)
            throw std::runtime_error(curl_easy_strerror(ec));

    }
    return data;
}
