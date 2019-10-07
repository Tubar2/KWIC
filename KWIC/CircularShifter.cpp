//
//  CircularShifter.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "CircularShifter.hpp"
using namespace std;

// Auxiliar Function
string joinVector(vector<string> myVector){
    string line {};
    
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        if(std::next(it) == myVector.end()) // last element
        {
            line.append(*it);
        }
        else {
            line.append(*it);
            line.append(" ");
        }
    }
    
    return line;
}

vector<string> CircularShifter::makeCircularShifts(){
    string tempShift {}, tempWord {};
    vector<string> allShifts {};
    int expectedShifts = static_cast<int>(data.size());
    
    for (int i = 0; i < expectedShifts; i++) {
        tempWord = data.front(); //Returns first element from vector
        data.erase(data.begin());
        data.push_back(tempWord);
        
        tempShift = joinVector(data);
        cout << "Shift (" << (i+1) << "/" << expectedShifts << "): " << tempShift << endl;
        allShifts.push_back(tempShift);
    }
    
    return allShifts;
}

//MARK: Constructor
CircularShifter::CircularShifter(vector<string> & originalLineVector)
:data(originalLineVector)
{
    cout << "Circular Shifter object created with " << originalLineVector.size() << " words." << endl;
    
}
