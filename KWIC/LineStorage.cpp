//
//  LineStorage.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "LineStorage.hpp"


// MARK: wordsInLine
int LineStorage::wordsInLine(){

    return static_cast<int>(originalLine.size());
}

// MARK: storedLines
int LineStorage::storedLines(){
    
    return (static_cast<int>(shiftedVariations.size()));
}

//MARK: storedStops
int LineStorage::storedStops(){
    return (static_cast<int>(stopWords.size()));
}

// MARK: charsInWord
int LineStorage::charsInWord(int position){
    int curPosition {0}, numChars {0};
    string requestedWord {};
    
    for (auto word : originalLine) {
        if (curPosition == position) {
            requestedWord = word;
        }
        
        curPosition += 1;
    }
    
    numChars = static_cast<int>(requestedWord.size());
    
    return numChars;
}

// MARK: getWord
string LineStorage::getWord(int position){
    int curPosition {0};
    string requestedWord {};
    
    for (auto word : originalLine) {
        if (curPosition == position) {
            requestedWord = word;
            break;
        }
        
        curPosition += 1;
    }
    
    return requestedWord;
}

// MARK: getChar
char LineStorage::getChar(int wordPosition, int charPosition){
    int curWordPosition {0}, curCharPosition {0};
    char requestedChar{};
    
    for (auto word : originalLine) {
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
string LineStorage::getWordFromString(int position, string line){
    string word {};
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
void LineStorage::deletePrevInfo(){
    wholeOriginalLine = "";
    originalLine.clear();
    shiftedVariations.clear();
    
}

//MARK: Constructor
LineStorage::LineStorage(){
    cout << "Line Storage object created." << endl;
}