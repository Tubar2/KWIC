//
//  Output.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "Output.hpp"

Output::Output(std::string outputName, std::vector<std::string> & data)
:data(data), outputTitle(outputName){
    std::cout << "Output object created." << std::endl;
}
