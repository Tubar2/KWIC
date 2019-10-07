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

class Output {
    
protected:
    std::vector<std::string> & data;
    std::string outputTitle;
    
public:
    
    Output(std::string outputName, std::vector<std::string> & data);
};

#endif /* Output_hpp */
