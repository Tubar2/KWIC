//
//  Input.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include "I_Input.hpp"
#include <iostream>
#include <fstream>

using namespace std;

class Input: public I_Input {
    
private:
    ifstream filename {};
    ifstream stopWords {};
    
public:
    
    virtual void read(istream &is) const override;
};

#endif /* Input_hpp */
