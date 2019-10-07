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
Output::Output(string outputName, vector<string> & data)
:data(data), outputTitle(outputName){
    cout << "Output object created." << endl;
}
