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

//writes lines in json
void JSON_Output::print(){
    json j;
    for (auto line : data) {
        j.push_back(line);
    }
    k["titles"].push_back(j);
}

//MARK: closeFile
void JSON_Output::close(){

    out_file << k.dump(4); //Passes json structure to jsonfile
    out_file.close();
}

//MARK: Construcotr
JSON_Output::JSON_Output(std::vector<std::string> & data)
:Output(data){
    
    std::string filepath {"Exits/"}, line{};
    std::cout << "Enter output file name: (no .json needed)" << std::endl;
    getline(std::cin, line);
    
    filepath += line + ".json";
    
    outputTitle = filepath;
    
    std::cout << "JSON_Output object created." << std::endl;
}
