//
//  Alphabetizer.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "Alphabetizer.hpp"

Alphabetizer::Alphabetizer(LineStorage * newdata)
:data(newdata)
{
    cout << "Alphabetizer created" << endl;
}

void Alphabetizer::removeStops(){
    
    string firstWord {};
    bool change = false;
    auto dataIT = data->shiftedVariations.begin();
    auto stopsIT = data->stopWords.begin();
    
    while (dataIT != data->shiftedVariations.end()) {
        firstWord = data->getWordFromString(0, *dataIT);
        while (stopsIT != data->stopWords.end()) {
            if (*stopsIT == firstWord) {
                dataIT = data->shiftedVariations.erase(dataIT);
                change = true;
                break;
            }
            ++stopsIT;
        }
        stopsIT = data->stopWords.begin();
        if (!change) {
            ++dataIT;
        } else{
            change = false;
        }
    }
}
