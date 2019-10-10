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

#ifndef LineStorage_vector_hpp
#define LineStorage_vector_hpp

#include <iostream>
#include <string>
#include <vector>

#include "I_Storable.hpp"

class LineStorage_vector : public I_Storable<std::vector<std::string>> {
private:
   std::string originalLine_String {};

public:
   //MARK: unused functions
   int wordsInLine();                      // Returns number of words in line
   int charsInWord(int position);          // Returns specified char
   std::string getWord(int position);           // Returns specified word
   char getChar(int wordPosition, int charPosition); // Returns specified character from specified word
    
   //MARK: storage verification
   int storedLines();                      // Returns number of lines in storage
   int storedStops();                      // Returns number of stop words in storage
    
   //MARK: getWordFromString
   std::string getWordFromString(int position, std::string line);
    
   //MARK: Must be overriden functions
   void deletePrevInfo(); //Deltes previous information on data
    

   //MARK: Constructor and Destructor
   LineStorage_vector();            //Constructor
   ~LineStorage_vector() = default; //Destructor

};

#endif /* LineStorage_hpp */
