/*
compile with:
    g++ -std=c++14 dblp.cpp -lcurl -I single_include/
    biblioteca já json incluida.
    libcurl precisa ser baixada.
*/

//TODO: Organizar esse módulo em uma classe quando a interface for definida.

#include <iostream>
#include <memory>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// write the data into a `std::string`
std::size_t write_data(void* buf, std::size_t size, std::size_t nmemb, void* userp)
{
    if(auto sp = static_cast<std::string*>(userp))
    {
        sp->append(static_cast<char*>(buf), size * nmemb);
        return size * nmemb;
    }

    return 0;
}

// A deleter to use in the smart pointer for automatic cleanup
struct curl_dter{void operator()(CURL* curl) const
    { if(curl) curl_easy_cleanup(curl); }};

// A smart pointer to automatically clean up out CURL session
using curl_uptr = std::unique_ptr<CURL, curl_dter>;

// download the URL into a `std::string`.
std::string get_url(std::string const& url)
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

int main()
{
    // query is the desired search paramter
    std::string query {"test"};

    // building url
    std::string url;
    url.append("https://dblp.org/search/publ/api?q=");
    url.append(query);
    url.append("&format=json");
    std::cout << url << std::endl;
    
    // store json file from url into variable j
    json j = json::parse(get_url(url));
    
    // reaching the part where the articles are stored
    json o = j["result"]["hits"]["hit"];

    int i = 1;
    std::string str;

    // iterating through articles and colecting titles
    for (auto it = o.begin(); it != o.end(); ++it)
    {
        str = (*it)["info"]["title"];
        std::cout << i << ' ' << str << std::endl;
        i++;

        //TODO: set structure to store title strings
    }

    return 0;
}
