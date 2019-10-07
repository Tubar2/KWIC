//
//  CircularShifter.cpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#include "CircularShifter.hpp"

// Auxiliar Function
std::string joinVector(std::vector<std::string> myVector){
    std::string line {};
    
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

std::vector<std::string> CircularShifter::makeCircularShifts(){
    std::string tempShift {}, tempWord {};
    std::vector<std::string> allShifts {};
    int expectedShifts = static_cast<int>(data.size());
    
    for (int i = 0; i < expectedShifts; i++) {
        tempWord = data.front(); //Returns first element from vector
        data.erase(data.begin());
        data.push_back(tempWord);
        
        tempShift = joinVector(data);
        std::cout << "Shift (" << (i+1) << "/" << expectedShifts << "): " << tempShift << std::endl;
        allShifts.push_back(tempShift);
    }
    
    return allShifts;
}

//MARK: Constructor
CircularShifter::CircularShifter(std::vector<std::string> & originalLineVector)
:data(originalLineVector)
{
    std::cout << "Circular Shifter object created with " << originalLineVector.size() << " words." << std::endl;
    
}
