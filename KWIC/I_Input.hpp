//
//  I_Input.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 30/09/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#ifndef I_Input_hpp
#define I_Input_hpp

#include <iostream>
#include "LineStorage.hpp"

using namespace std;

class I_Input {
//    friend istream &operator>>(istream &is, const I_Input &obj);
    
public:
    virtual void read(LineStorage & data) const = 0;
    virtual ~I_Input() = default;
};

#endif /* I_Input_hpp */
