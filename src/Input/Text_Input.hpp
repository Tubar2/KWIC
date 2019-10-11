//
//  Text_Input.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#ifndef Text_Input_hpp
#define Text_Input_hpp

#include <iostream>
#include "Input.hpp"
#include "I_Input.hpp"

class Text_Input: public Input{
    
private:
    std::ifstream in_file {};
    
    //MARK: Overriden function
    void extractStops() override; //Extracts each word in a vector<string>
    void extractMain() override;  //Extracts line from main file and separates each word in a vector<string>
    bool setup() override; //Opens file for reading
    void finish() override;//Closes file
    bool endReached() override;  //Check if eof was reached
    
public:
    
    //MARK: Constructor
    Text_Input(std::string name, LineStorage & data, type entryType); //3 Args Construcotr
    Text_Input(LineStorage & data, type entryType);  //2 Args Constructor
    
    //MARK: Destructor
    ~Text_Input() = default; //Destructor
    
};

#endif /* Text_Input_hpp */
