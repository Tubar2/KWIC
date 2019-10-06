//
//  Input.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 06/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include <iostream>
#include <string>
#include "../LineStorage.hpp"
#include "I_Input.hpp"

class Input : public I_Input{

private:
    
    //Functions that need to be implemented by derived class
    virtual void extractStops() = 0; //Extracts all stop words in a vector<string>
    virtual void extractMain() = 0;  //Extracts line from main file and separates each word in a vector<string>
    virtual bool setup() = 0;        //Trys to open
    virtual void finish() = 0;       //Finishes document reading
    
protected:
    type entryType {};
    std::string filepath {};
    LineStorage & data;
    
public:
    
    void extract() override;  //Extracts single line from file into data storage or all stop words
    void open() override;    //Opens url, file, etc...
    void close() override;  //Closes opend url, file, etc...
    
    //MARK: Constructor and Destructor
    Input(string filepath, LineStorage & data, type entryType);
    ~Input() = default;
};

#endif /* Input_hpp */
