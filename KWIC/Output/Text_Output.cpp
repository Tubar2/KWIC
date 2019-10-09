//
//  Text_Output.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 02/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "Text_Output.hpp"

//MARK: createFile
void Text_Output::setup(){
    
    out_file.open(outputTitle, std::ios_base::trunc);
    
    if (!out_file.is_open()) {
        std::cout << "Error creating output file." << std::endl;
        exit(2);
    } else {
        std::cout << "Output file created succesfully." << std::endl;
    }
}

void Text_Output::print(){
    
    for (auto line : data) {
        out_file << line << std::endl;
    }
    
}

//MARK: closeFile
void Text_Output::close(){
    out_file.close();
}

//MARK: Construcotr
Text_Output::Text_Output(std::vector<std::string> & data)
:Output(data){
    
    std::string filepath {"Exits/"}, line{};
    std::cout << "Enter output file name: (no txt needed)" << std::endl;
    getline(std::cin, line);
    
    filepath += line + ".txt";
    
    outputTitle = filepath;
    
    std::cout << "Text_Output object created." << std::endl;
}
