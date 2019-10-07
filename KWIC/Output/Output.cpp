//
//  Output.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "Output.hpp"

void Output::assemble(){
    std::cout << "Assembling output" << std::endl;
    setup();
}

void Output::printContent(){
    print();
}

void Output::terminate(){
    close();
}

//MARK: Constructor
Output::Output(std::string outputName, std::vector<std::string> & data)
:data(data), outputTitle(outputName){
    std::cout << "Output object created." << std::endl;
}

Output::Output(std::vector<std::string> & data) //1 Arg Constructor
:data(data){
    std::cout << "Output object created." << std::endl;
}
