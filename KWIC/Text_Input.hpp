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

class Text_Input: Input {
    
    ifstream in_file {};
    
public:
    
    //MARK: setup()
    void setup() override;
    
    //MARK: setupReading
    void setupReading();  //Opens file for reading
    
    //MARK: reachedEOF
    bool reachedEOF();  //Check if eof was reached
    
    //MARK: extractors
    virtual void extract(entryType typeEntry);  //Switches extraction type
    
    //MARK: Constructor
    Text_Input(string filename, LineStorage & data);  //Constructor
    
    //MARK: Destructor
    ~Text_Input() = default; //Destructor
    
    //MARK: Interface Functions Implementation
    virtual void read(LineStorage & data) const override;
    
private:
    void extractStops(); //Extrcats each word in a vector<string>
    void extractMain();  //Extracts line from main file and separates each word in a vector<string>
};

#endif /* Text_Input_hpp */
