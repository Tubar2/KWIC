//
//  Output.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

/*
 
 Desired formatted print of set of lines obtained from
 "Alphabetizer".
 
 */

#ifndef complexOutput_hpp
#define complexOutput_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "I_Outputable.hpp"
#include "I_assembleble.hpp"

template<class Storage_t>
class complexOutput : public I_Outputable, public I_assembleble {
    
private:
    virtual void setup() = 0;
    virtual void print() = 0;
    virtual void close() = 0;
    
protected:
    Storage_t & data;
    std::string outputTitle;
    
public:
    
    void assemble() override;
    void printContent() override;
    void terminate() override;
    
    //MARK: Constructor
    complexOutput(std::string outputName, Storage_t & data); //2 Args Contructor
    
};

#endif /* Output_hpp */
