//
//  Alphabetizer.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

/*
 
 Takes as inputs arrays created by "Input" and "CircleShifter".
 Alphabetical organization.
 
 */

#ifndef Alphabetizer_hpp
#define Alphabetizer_hpp

#include <iostream>
#include "LineStorage.hpp"

class Alphabetizer {
    LineStorage & data;
    
    
public:
    void alphabetiseData();
    void removeStops();
    
    Alphabetizer(LineStorage & newdata);
    
};

#endif /* Alphabetizer_hpp */
