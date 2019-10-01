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

class Text_Input: Input {
    
public:
    virtual ~Text_Input() = default;
//    virtual void read(istream &is) const override;
};

#endif /* Text_Input_hpp */
