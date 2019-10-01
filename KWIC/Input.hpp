//
//  Input.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include "I_Input.hpp"
#include "LineStorage.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Input: public I_Input {
    
protected:
    ifstream in_file {}, stopWords {};
    string filename {}, stopWordsFilename {};
    LineStorage data;
    
public:
    
    virtual ~Input() = default;
    virtual void read(istream &is) const override;
    
    virtual void setupReading();        //Trys to open files
    virtual void extractLine();
    virtual void extractWords();        // Extracts stop words (each word is in single line)
    virtual bool reachedEOF();
    
    Input(string name, string stops);   //Constructor
};

#endif /* Input_hpp */
