//
//  I_Output.hpp
//  KWIC
//
//  Created by Ricardo de Castro Giometti Santos on 07/10/19.
//  Copyright © 2019 Ricardo de Castro Giometti Santos. All rights reserved.
//

#ifndef I_Outputable_hpp
#define I_Outputable_hpp

class I_Outputable { 
private:

public:

    virtual void printContent() = 0;
    
    //MARK: Destructor
    virtual ~I_Outputable() = default;
};

#endif /* I_Output_hpp */
