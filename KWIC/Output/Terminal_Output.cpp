//
//  Terminal_Output.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 07/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "Terminal_Output.hpp"

Terminal_Output::Terminal_Output(vector<string> &data)
:Output("", data){
    
}

void Terminal_Output::print(){
    for (auto line : data) {
        std::cout << line << std::endl;;
    }
}

void Terminal_Output::close(){
    //No need to do anything
}

void Terminal_Output::setup(){
    //Setup need's no previous setup on terminal output
}
