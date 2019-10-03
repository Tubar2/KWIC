#include "DBLP_Input.hpp"

//MARK: Constructor
DBLP_Input::DBLP_Input(string query, LineStorage & data)
:Input(query, "json", data)
{
    cout << "Created DBLP_Input object for reading." << endl;
}

//TODO: Useless
void DBLP_Input::read(LineStorage & data) const{
    std::cout << "yay";
}

//MARK: Setup
void DBLP_Input::setup(){
    Input::setup();
    
    cout << "Setting up DBLP Input enviroment." << endl;
    search_and_store();

}
//Extracts line : delimiter '\n'
void DBLP_Input::extract(){  
    string line;
    
    line = all_titles_vector.at(title_iterator);
    data.wholeOriginalLine = line;
    
    string tempWord {};
    for (auto c : line) {
        if (c == ' ') {
            data.originalLine.push_back(tempWord);
            tempWord = "";
        }
        else{
            tempWord += c;
        }
    }
    data.originalLine.push_back(tempWord);

    title_iterator++;
}

bool DBLP_Input::reachedEND() {
    if (title_iterator == title_count)
    {
        return true;
    }
    return false;
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

void DBLP_Input::search_and_store(){

    // query is the desired search paramter
    std::string query = Input::filename;

    // building url
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
    title_count = all_titles_vector.size();
    title_iterator = 0;

    //TODO : apagar isso aqui
    /*//imprimir titulos no terminal
    for (auto it = all_titles_vector.begin(); it != all_titles_vector.end(); ++it)
        std::cout << (*it) << std::endl;*/
}