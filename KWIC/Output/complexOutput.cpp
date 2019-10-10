//
//  Output.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "complexOutput.hpp"

template<class Storage_t>
void complexOutput<Storage_t>::assemble(){
    std::cout << "Assembling output" << std::endl;
    setup();
}

template<class Storage_t>
void complexOutput<Storage_t>::printContent(){
    print();
}

template<class Storage_t>
void complexOutput<Storage_t>::terminate(){
    close();
}

//MARK: Constructor
template<class Storage_t>
complexOutput<class Storage_t>::complexOutput(std::string outputName, Storage_t & data)
:data(data), outputTitle(outputName){
    std::cout << "Output object created." << std::endl;
}

