//
//  Terminal_Output.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 07/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#ifndef Terminal_Output_hpp
#define Terminal_Output_hpp

#include "Output.hpp"
#include <iostream>

class Terminal_Output : public Output{
    
private:
    
    void setup() override;
    void print() override;
    
};

#endif /* Terminal_Output_hpp */
