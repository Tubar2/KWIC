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

std::string createFilepath();

int main(int argc, const char * argv[]) {
    
    std::string filepath = createFilepath();
    
    //Definig both types of enums
    type stops = typeStops;
    type inputs = typeInput;
    
    //Creating Line Storage
    LineStorage data;
    
    //Creating new Input objects
    Text_Input input("Resources/myfile.txt", data, inputs);
    Text_Input words("Resources/mystops.txt", data, stops);
    
    //Creating output object
    Text_Output to(filepath, data.shiftedVariations);
    
    Factory factory{input, words, to, data};
    factory.run();
    
    return 0;
}

//MARK: createFilepath
std::string createFilepath(){
    std::string filepath {"Exits/"}, line{};
    std::cout << "Enter output file name: (no txt needed)" << std::endl;
    getline(std::cin, line);
    
    filepath += line + ".txt";
    
    return filepath;
}
