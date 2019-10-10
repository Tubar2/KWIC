//
//  Alphabetizer.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "Alphabetizer.hpp"

bool compareString(std::string a, std::string b){
    bool bigger {};
    int i{0};
    
    for (auto c : a) {
        if (tolower(c) < tolower(b[i])) {
            bigger = true;
            break;
        }
        else if (tolower(c) > tolower(b[i])){
            bigger = false;
            break;
        }
        i++;
    }
    
    return bigger;
}

template <typename T>
Alphabetizer<T>::Alphabetizer<T>(I_Storable<T> && newdata)
:data(std::move(newdata))
{
    std::cout << "Alphabetizer created" << std::endl;
}

template <typename T>
void Alphabetizer<T>::removeStops(){
    
    std::string firstWord {};
    bool change = false;
    auto dataIT = data.shiftedVariations.begin();
    auto stopsIT = data.stopWords.begin();
    
    while (dataIT != data.shiftedVariations.end()) {
        firstWord = data.getWordFromString(0, *dataIT);
        while (stopsIT != data.stopWords.end()) {
            if (*stopsIT == firstWord) {
                dataIT = data.shiftedVariations.erase(dataIT);
                change = true;
                break;
            }
            ++stopsIT;
        }
        stopsIT = data.stopWords.begin();
        if (!change) {
            ++dataIT;
        } else{
            change = false;
        }
    }
}

template <typename T>
void Alphabetizer<T>::alphabetiseData(){
    sort(data.shiftedVariations.begin(), data.shiftedVariations.end(), compareString);
}
