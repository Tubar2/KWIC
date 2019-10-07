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
    
    out_file.open(outputTitle, ios_base::trunc);
    
    if (!out_file.is_open()) {
        cout << "Error creating output file." << endl;
        exit(2);
    } else {
        cout << "Output file created succesfully." << endl;
    }
}

void Text_Output::print(){
    
    for (auto line : data) {
        out_file << line << endl;;
    }
    
}

//MARK: closeFile
void Text_Output::close(){
    out_file.close();
}

//MARK: Construcotr
Text_Output::Text_Output(vector<string> & data)
:Output(data){
    
    string filepath {"Exits/"}, line{};
    cout << "Enter output file name: (no txt needed)" << endl;
    getline(cin, line);
    
    filepath += line + ".txt";
    
    outputTitle = filepath;
    
    cout << "Text_Output object created." << endl;
}
