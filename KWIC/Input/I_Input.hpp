//
//  I_Input.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 06/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#ifndef I_Input_hpp
#define I_Input_hpp

#include "LineStorage.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

enum type { typeStops, typeInput};

class I_Input{
    
public:
    
    //MARK: Must be overriden functions:
    virtual void open() = 0;    //Opens url, file, etc...
    virtual void extract() = 0;  //Extracts single line from file into data storage or all stop words
    virtual bool reachedEND() = 0; //Checks if end was reached
    virtual void close() = 0; //Closes opened file, url, etc...
    
    //MARK: Destructor
    virtual ~I_Input() = default;
    
};
#endif /* I_Input_hpp */
