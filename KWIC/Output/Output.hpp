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

using namespace std;

class Output : public I_Output {
    
private:
    virtual void setup() = 0;
    virtual void print() = 0;
    virtual void close() = 0;
    
protected:
    vector<string> & data;
    string outputTitle;
    
public:
    
    void assemble() override;
    void printContent() override;
    void terminate() override;
    
    //MARK: Constructor
    Output(string outputName, vector<string> & data);
};

#endif /* Output_hpp */
