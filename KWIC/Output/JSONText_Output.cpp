#include "JSONText_Output.hpp"

//MARK: createFile
void JSON_Output::setup(){
    
    out_file.open(outputTitle, std::ios_base::trunc);
    
    if (!out_file.is_open()) {
        std::cout << "Error creating output file." << std::endl;
        exit(2);
    } else {
        std::cout << "Output file created succesfully." << std::endl;
    }
}

void JSON_Output::print(){
    
    for (auto line : data) {
        out_file << line << std::endl;;
    }
    
}