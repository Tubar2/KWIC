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

//TODO: Define enum for type of entry: stopwords or mainFile
enum entryType { typeStops, typeInput};

class Input: public I_Input {
    
protected:
    entryType entry {};
    string filename {}, format {};
    LineStorage & data;
    
public:
    
    virtual void read(LineStorage & data) const override;
    
    virtual void setup();
    
    virtual ~Input() = default;
    //MARK: Constructor
    Input(string inputName, string format, LineStorage & data);   //Constructor
};

#endif /* Input_hpp */
