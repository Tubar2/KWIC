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

#ifndef Output_hpp
#define Output_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "I_Output.hpp"

class Output : public I_Output {
    
private:
    virtual void setup() = 0;
    virtual void print() = 0;
    virtual void close() = 0;
    
protected:
    std::vector<std::string> & data;
    std::string outputTitle;
    
public:
    
    void assemble() override;
    void printContent() override;
    void terminate() override;
    
    //MARK: Constructor
    Output(std::string outputName, std::vector<std::string> & data); //2 Args Contructor
    Output(std::vector<std::string> & data); //1 Arg Constructor
    
};

#endif /* Output_hpp */
