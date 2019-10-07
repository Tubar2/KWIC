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

using namespace std;

class Output {
    
protected:
    vector<string> & data;
    string outputTitle;
    
public:
    
    Output(string outputName, vector<string> & data);
};

#endif /* Output_hpp */
