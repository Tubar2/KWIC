//
//  main.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include "CircularShifter.hpp"
#include "Alphabetizer.hpp"
#include "Text_Output.hpp"
#include "Text_Input.hpp"

void printVector2(std::vector<std::string> myvector);
void testMultipleParamGetLine();
std::string testJoinVector(std::vector<std::string> myVector);
std::vector<std::string> testMakeCircularShifts(std::vector<std::string> data);
void removeStops(std::vector<std::string> & shiftedVariations, std::vector<std::string> stopWords);
std::string testGetWordFromString(int position, std::string line);
void testAlphabetizeData(std::vector<std::string> & shiftedVariations);
void testWithMadeVectors();
bool testCompareString(std::string a, std::string b);

//Testing functions

void printVector2(std::vector<std::string> myvector){
    for (auto mystr : myvector) {
        std::cout << mystr << std::endl;
    }
}

//MARK: getline with multiple param
void testMultipleParamGetLine(){
    std::string str {};
    std::cout << "Type something:" << std::endl;
    getline(std::cin, str);
    
    std::cout << str <<std::endl;
    
    std::cout << "Type another thing:" << std::endl;
    getline(std::cin, str, '.');
    std::cout << str <<std::endl;
}

void testWithMadeVectors(){
    std::vector<std::string> testVector {}, shiftsVector {}, stopsVector {};
        testVector.push_back("Oi,");
        testVector.push_back("meu");
        testVector.push_back("nome");
        testVector.push_back("é");
        testVector.push_back("Ricardo.");
            
        stopsVector.push_back("é");
        stopsVector.push_back("meu");
        
        shiftsVector = testMakeCircularShifts(testVector);
    //    printVector(shiftsVector);
        
        removeStops(shiftsVector, stopsVector);
        printVector2(shiftsVector);
        
        testAlphabetizeData(shiftsVector);
        printVector2(shiftsVector);
}

//MARK: Vector -> String
std::string testJoinVector(std::vector<std::string> myVector){
    std::string line {};
    
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        if(std::next(it) == myVector.end()) // last element
        {
            line.append(*it);
        }
        else {
            line.append(*it);
            line.append(" ");
        }
    }
    
    return line;
}

//MARK: All circular shifts
std::vector<std::string> testMakeCircularShifts( std::vector<std::string> data){
    std::string tempShift {}, tempWord {};
    std::vector<std::string> allShifts {};
    int expectedShifts = static_cast<int>(data.size());
    
    
    for (int i = 0; i < expectedShifts; i++) {
        tempWord = data.front(); //Returns first element from vector
        data.erase(data.begin());
        data.push_back(tempWord);
        tempShift = testJoinVector(data);
        allShifts.push_back(tempShift);
    }
    
    
    return allShifts;
}

//MARK: wordFromString
std::string testGetWordFromString(int position, std::string line){
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

//MARK: Remove Stops
void removeStops(std::vector<std::string> & shiftedVariations, std::vector<std::string> stopWords){
    
    std::string firstWord {};
    bool change = false;
    auto dataIT = shiftedVariations.begin();
    auto stopsIT = stopWords.begin();
    
    while (dataIT != shiftedVariations.end()) {
        firstWord = testGetWordFromString(0, *dataIT);
        while (stopsIT != stopWords.end()) {
            if (*stopsIT == firstWord) {
                dataIT = shiftedVariations.erase(dataIT);
                change = true;
                break;
            }
            ++stopsIT;
        }
        stopsIT = stopWords.begin();
        if (!change) {
            ++dataIT;
        } else{
            change = false;
        }
    }
}

//TODO: Diminuir função
//MARK: compareString
bool testCompareString(std::string a, std::string b){
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

//MARK: Sorting
void testAlphabetizeData(std::vector<std::string> & shiftedVariations){
    sort(shiftedVariations.begin(), shiftedVariations.end(), testCompareString);
}
