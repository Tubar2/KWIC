//
//  Input.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "Input.hpp"

using namespace std;

//MARK: setup
void Input::setup(){
    cout << "Setting up input enviroment." << endl;
}

//MARK: Constructor and Interface functions
Input::Input(string inputName, string formats, LineStorage & data)
:filename(inputName), format(formats), data(data)
{
    cout << "Input object created: \nInput = " << inputName <<
            "\nformat = " << formats << endl;
}

void Input::read(LineStorage & data) const{
    cout << "Read function called in Input with reference to: " << data.wholeOriginalLine << endl;
}

