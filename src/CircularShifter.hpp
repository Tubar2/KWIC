//
//  CircularShifter.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

/*
 
 Cointainer for all circular shifts of a line by
 creating/providing an index of the address of the
 first character of each circular shift, as well as
 the orignal index of the line in the array.
 
 Functions:
    - CSCHAR
    - CSSETUP
 
 */

#ifndef CircularShifter_hpp
#define CircularShifter_hpp

#include <iostream>
#include "LineStorage.hpp"

class CircularShifter {
    std::vector<std::string> & data;
public:
    virtual std::vector<std::string> makeCircularShifts();
    
    //MARK: Constructors
    CircularShifter(std::vector<std::string> & originalLineVector);   //1 param Constructor
    
    
    virtual ~CircularShifter() = default;                      //Destructor
};

#endif /* CircularShifter_hpp */
