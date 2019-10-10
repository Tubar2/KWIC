//
//  Terminal_Output.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 07/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#ifndef Terminal_Output_hpp
#define Terminal_Output_hpp

#include "simpleOutput.hpp"
#include <iostream>

template <typename T>
class Terminal_Output : public simpleOutput<T>{
    
private:
    
    void print() override;
    
public:
    
    //MARK: Constructor
    Terminal_Output(T &data);
    
};

#endif /* Terminal_Output_hpp */
