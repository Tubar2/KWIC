//
//  I_Output.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 07/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#ifndef I_Output_hpp
#define I_Output_hpp

class I_Output {
    
    
public:
    
    virtual void assemble() = 0;
    virtual void extractContent() = 0;
    
    //MARK: Destructor
    virtual ~I_Output() = default;
};

#endif /* I_Output_hpp */
