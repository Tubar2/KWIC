//
//  CircularShifter.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "CircularShifter.hpp"
using namespace std;

CircularShifter::CircularShifter(LineStorage newData)
:data(newData)
{
    cout << "Circular Shifter object created with " << data.wordsInLine() << " words." << endl;
}

void CircularShifter::makeCircularShifts(){
    string tempShift {};
    int expectedShifts = data.wordsInLine();
    
    for (int i = 0; i < expectedShifts; i++) {
        
    }
}
