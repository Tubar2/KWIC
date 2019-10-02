//
//  LineStorage.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

/*
 
 Functions that provide means by which the user may
 call.
 
 Routines:
    - Number of words on any line
    - Lines currently stored
    - Number of characters in any word
 
 Functions:
    - CHAR
    - SETCHAR
    - WORDS
    - DELINE
    - DELWRD
 
 */

#ifndef LineStorage_hpp
#define LineStorage_hpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LineStorage {
    
public:
    
    // MARK: Variables
    string wholeOriginalLine {};
    vector<string> originalLine {};         // Vector of strings of words
    vector<string> shiftedVariations {};    // All shifted variations of line
    vector<string> stopWords {};            // All stop words
    
    //MARK: wordsInLine
    int wordsInLine();                      // Returns number of words in line
    
    //MARK: storedLines
    int storedLines();                      // Returns number of lines in storage
    
    //MARK: charsInWord
    int charsInWord(int position);          // Returns specified char

    //MARK: getWord
    string getWord(int position);           // Returns specified word
    
    //MARK: getChar
    char getChar(int wordPosition, int charPosition); // Returns specified character from specified word
    
    //MARK: getWordFromString
    string getWordFromString(int position, string line);
    
    //TODO: Implement setWord
    //MARK: setWord
    
    //TODO: Implement deleters and constructors
    LineStorage();  //Constructor
};

#endif /* LineStorage_hpp */
