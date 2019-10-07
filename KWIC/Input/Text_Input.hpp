//
//  Text_Input.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#ifndef Text_Input_hpp
#define Text_Input_hpp

#include <iostream>
#include "Input.hpp"
#include "I_Input.hpp"

class Text_Input: public Input{
    
private:
    ifstream in_file {};
    
    //MARK: Extractors
    void extractStops() override; //Extracts each word in a vector<string>
    void extractMain() override;  //Extracts line from main file and separates each word in a vector<string>
    
    //MARK: setup
    bool setup() override; //Opens file for reading
    
    //MARK: finish
    void finish() override;//Closes file
    
public:
    
    //MARK: reachedEOF
    bool reachedEND() override;  //Check if eof was reached
    
    //MARK: Constructor
    Text_Input(string filename, LineStorage & data, type entryType);  //Constructor
    
    //MARK: Destructor
    ~Text_Input() = default; //Destructor
    
};

#endif /* Text_Input_hpp */
