/*
g++ dblp.cpp -lcurl -ljsoncpp -I /usr/local/json/include/
*/

#include <iostream>
#include <memory>
#include <jsoncpp/json/json.h>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// write the data into a `std::string` rather than to a file.
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
    curl_global_init(CURL_GLOBAL_DEFAULT);
    //CURL *curl;
    std::string url;
    url.append("https://dblp.org/search/publ/api?q=");
    url.append("Parnas");
    url.append("&format=json");
    std::cout << url << std::endl;
    
    auto json = get_url(url);

    //std::cout << json << '\n';

    Json::Reader reader;
    Json::Value obj;
    reader.parse(json, obj);
    std::cout << obj["result"]["hits"]["hit"]["info"]["tittle"] << std::endl;
    curl_global_cleanup();
    return 0;
}
