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

#include "CircularShifter.hpp"
#include "Alphabetizer.hpp"
#include "Text_Output.hpp"
#include "Text_Input.hpp"

using namespace std;

void printVector(vector<string> myvector);
void testMultipleParamGetLine();
string testJoinVector(vector<string> myVector);
vector<string> testMakeCircularShifts(vector<string> data);
void removeStops(vector<string> & shiftedVariations, vector<string> stopWords);
string testGetWordFromString(int position, string line);
void testAlphabetizeData(vector<string> & shiftedVariations);
void testWithMadeVectors();
bool testCompareString(string a, string b);

int main(int argc, const char * argv[]) {
    
    entryType stops = typeStops;
    entryType inputs = typeInput;
    
    //Creating Line Storage
    LineStorage data;
    
    //Creating and setting up new Input objects
    Text_Input input("Resources/myfile.txt", data);
    Text_Input words("Resources/mystops.txt", data);
    input.setup();
    words.setup();
    
    //Extracting Words and line
    words.extract(stops);
    input.extract(inputs);
    
    //Creating CircularShifter object
    CircularShifter cs (data.originalLine);
    
    //Creating all shifts for stored line
    data.shiftedVariations = cs.makeCircularShifts();
    cout << "Shifts made: " << data.storedLines() << endl;
    
    //Creating alphabetizer
    Alphabetizer alph(data);
    
    //Removing stops and alphabetizing
    alph.removeStops();
    alph.alphabetiseData();
    
    //TODO: Read all lines of file
    
    //Creating output object
    Text_Output to("Exits/exit.txt", data.shiftedVariations);
    
    to.createFile();
    to.printOutput();
    
    //Closing files
    to.closeFile();
    input.closeFile();
    words.closeFile();
    
    return 0;
}


//Testing functions

void printVector(vector<string> myvector){
    for (auto mystr : myvector) {
        cout << mystr << endl;
    }
}

//MARK: getline with multiple param
void testMultipleParamGetLine(){
    string str {};
    cout << "Type something:" << endl;
    getline(cin, str);
    
    std::cout << str <<endl;
    
    cout << "Type another thing:" << endl;
    getline(cin, str, '.');
    std::cout << str <<endl;
}

void testWithMadeVectors(){
    vector<string> testVector {}, shiftsVector {}, stopsVector {};
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
        printVector(shiftsVector);
        
        testAlphabetizeData(shiftsVector);
        printVector(shiftsVector);
}

//MARK: Vector -> String
string testJoinVector(vector<string> myVector){
    string line {};
    
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
vector<string> testMakeCircularShifts( vector<string> data){
    string tempShift {}, tempWord {};
    vector<string> allShifts {};
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
string testGetWordFromString(int position, string line){
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

//MARK: Remove Stops
void removeStops(vector<string> & shiftedVariations, vector<string> stopWords){
    
    string firstWord {};
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
bool testCompareString(string a, string b){
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
void testAlphabetizeData(vector<string> & shiftedVariations){
    sort(shiftedVariations.begin(), shiftedVariations.end(), testCompareString);
}
