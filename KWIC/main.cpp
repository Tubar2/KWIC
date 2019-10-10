//
//  main.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <algorithm>

#include "Factory.hpp"
#include "LineStorage.hpp"
#include "Output/Text_Output.hpp"
#include "Input/Text_Input.hpp"
#include "Output/Terminal_Output.hpp"
#include "Input/DBLP_Input.hpp"
#include "Input/JSONText_Input.hpp"


int main(int argc, const char * argv[]) {
    
    //Creating Line Storage
    LineStorage data;
    
    //Creating new Input objects
    Text_Input input(data, typeInput);
    Text_Input words(data, typeStops);
    
    //Creating output object
    Terminal_Output to(data.shiftedVariations);
    
    //Assembles Factory with corresponding types
    Factory factory{input, words, to, data};
    
    //Runs factory
    factory.run();
    
    return 0;
}

