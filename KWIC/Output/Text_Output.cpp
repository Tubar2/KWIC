//
//  Text_Output.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 02/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "Text_Output.hpp"

//MARK: createFile
void Text_Output::createFile(){
    
    out_file.open(outputTitle, ios_base::trunc);
    
    if (!out_file.is_open()) {
        cout << "Error creating output file." << endl;
        exit(2);
    } else {
        cout << "Output file created succesfully." << endl;
    }
}

void Text_Output::printOutput(){
    
    for (auto line : data) {
        out_file << line << endl;;
    }
    
}

//MARK: closeFile
void Text_Output::closeFile(){
    out_file.close();
}

//MARK: Construcotr
Text_Output::Text_Output(string filename, vector<string> & data)
:Output(filename, data){
    cout << "Text_Output object created." << endl;
}
