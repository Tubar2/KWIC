//
//  LineStorage.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "LineStorage_vector.hpp"


// MARK: wordsInLine
int LineStorage_vector::wordsInLine(){
    return static_cast<int>(I_Storable::get_originalLine().size());
}

// MARK: storedLines
int LineStorage_vector::storedLines(){
    return (static_cast<int>(I_Storable::get_shiftedVariations().size()));
}

//MARK: storedStops
int LineStorage_vector::storedStops(){

    return (static_cast<int>(I_Storable::get_stopWords().size()));
}

// MARK: charsInWord
int LineStorage_vector::charsInWord(int position){
    int curPosition {0}, numChars {0};
    std::string requestedWord {};
    
    for (auto word : I_Storable::get_originalLine()) {
        if (curPosition == position) {
            requestedWord = word;
        }
        
        curPosition += 1;
    }
    
    numChars = static_cast<int>(requestedWord.size());
    
    return numChars;
}

// MARK: getWord
std::string LineStorage_vector::getWord(int position){
    int curPosition {0};
    std::string requestedWord {};
    
    for (auto word : I_Storable::get_originalLine()) {
        if (curPosition == position) {
            requestedWord = word;
            break;
        }
        
        curPosition += 1;
    }
    
    return requestedWord;
}

// MARK: getChar
char LineStorage_vector::getChar(int wordPosition, int charPosition){
    int curWordPosition {0}, curCharPosition {0};
    char requestedChar{};
    
    for (auto word : I_Storable::get_originalLine()) {
        if (curWordPosition == wordPosition) {
            for (auto curChar : word) {
                if (curCharPosition == charPosition) {
                    requestedChar = curChar;
                    break;
                }
                
                curCharPosition += 1;
            }
        }
        
        curWordPosition += 1;
    }
    
    return requestedChar;
}

//MARK: getWordFromString
std::string LineStorage_vector::getWordFromString(int position, std::string line){
    std::string word {};
    int tempPos {};
    
    for (auto c : line) {
        if (c == ' ') {
            tempPos += 1;
            if ((tempPos-1) == position) {
                return word;
            }
            word = "";
        }
        else{
            word += c;
        }
        
    }
    return "Word not found";
}

//MARK: deletePrevInfo
void LineStorage_vector::deletePrevInfo(){
    originalLine_String = "";
    I_Storable::get_originalLine().clear();
    I_Storable::get_shiftedVariations().clear();
}

//MARK: Constructor
LineStorage_vector::LineStorage_vector(){
    std::cout << "Line Storage vector object created." << std::endl;
}
